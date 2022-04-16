# Análisis del código utilizado

## Optimización del código

El módulo a implementar puede ser descrito de manera muy básica mediante el siguiente código, desde una mirada del alto nivel:

```cpp
void eucDis(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT* C){
    uint32_t temp = 0;
    eachElement:for(int index = 0; index < VECTOR_LENGTH; index ++){
      temp += (A[index]-B[index])*(A[index]-B[index]);
    }
    C[0] = std::sqrt(temp);
}
```

Si se sintetizará, desde _Vitis HLS_ el módulo inferido tendría el siguiente desempeño a nivel de latencia y recursos utilizados:

| **Latencia** _ciclos_ | **BRAM** _%_ | **DSP** _%_ | **FF** _%_ | **LUT** _%_ | **URAM** _%_ |
|-|-|-|-|-|-|
| 1095| 0 | ~0 | ~0 | 1 | 0 |

**Esto corresponde a lo reportado por Vitis HLS luego de la etapa de síntesis y es un estimado, para el hardware dado y la frecuencia del reloj principal (100MHz).**

Si bien el uso de recursos dada esta implementación es mínimo, la latencia es bastante alta, dado que se asume una secuencialidad en la operación. Al inferir el módulo, se asume que cada dato va llegando uno a uno, antes de procesarse, por lo que al menos hay 1 ciclo por cada dato A y B que va llegando al modulo (1024 en total). La diferencia puede atribuirse a la operación de raiz cuadrada final. A continuación se exploran las formas en las que se optimizó el código a partir de este punto.

### Optimización operación raíz:  Vitis HLS Math

_Vitis HLS_ ofrece una biblioteca ([Vitis HLS Math](https://docs.xilinx.com/r/en-US/ug1399-vitis-hls/Vitis-HLS-Math-Library)) especializada en operaciones matemáticas, para el trabajo mas granular con bits, pensadas para su uso en bajo nivel. Si bien no entregan la misma precisión que las bibliotecas de C/C++, al estar pensadas para síntesis, ofrecen un tradeoff de precisión por una menor latencia.

Haciendo el cambio en la variable acumuladora por la nueva raíz `hls::sqrt()` :
```cpp
void eucDis(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT* C){
    uint32_t temp = 0;
    eachElement:for(int index = 0; index < VECTOR_LENGTH; index ++){
      temp += (A[index]-B[index])*(A[index]-B[index]);
    }
    C[0] = hls::sqrt(temp);
}
```
Sintetizando:

| **Latencia** _ciclos_ | **BRAM** _%_ | **DSP** _%_ | **FF** _%_ | **LUT** _%_ | **URAM** _%_ |
|-|-|-|-|-|-|
| 1038| 0 | ~0 | ~0 | 2 | 0 |

A partir de este cambio, se puede obtener **una mejora de 57 ciclos**, en relación a la implementación original. El uso de **LUTs** aumenta, pero su aumento es marginal. Otra ventaja del uso de esta biblioteca de operaciones, es que permite el uso de tipos específicos, como enteros sin signos de un número X de bits, esto se explorará a continuación.

### Uso de arbitrary precission data types: Vitis HLS ap_int
_Vitis HLS_ ofrece una biblioteca ([Vitis HLS ap_int](https://docs.xilinx.com/r/en-US/ug1399-vitis-hls/Using-Arbitrary-Precision-Data-Types)) que permite trabajar con variables de una tamaño determinado de _bits_,de esta manera optimizando el uso de recursos a bajo nivel. En este caso, tenemos que la variable acumuladora `temp` es de tipo `uint32_t` (definida por `<cstdint>`), sin embargo, si analizamos el máximo valor requerido:

```
clog2(255*sqrt(1024))= 26
```

Se tiene que en el peor de los casos, para representar la salida, se utilizaran 26 _bits_, por lo que se puede ajustar el código para trabajar con este tamaño:

```cpp
void eucDis(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT* C){
    ap_uint<26> temp = 0;
    eachElement:for(int index = 0; index < VECTOR_LENGTH; index ++){
      temp += (A[index]-B[index])*(A[index]-B[index]);
    }
    C[0] = hls::sqrt(temp);
}
```
Sintetizando:

| **Latencia** _ciclos_ | **BRAM** _%_ | **DSP** _%_ | **FF** _%_ | **LUT** _%_ | **URAM** _%_ |
|-|-|-|-|-|-|
| 1035| 0 | ~0 | ~0 | 1 | 0 |

Se logra una **reducción de 3 ciclos ** en términos de latencia y un 1% menos de uso de recursos en el caso *LUTs*.

### Pragmas utilizados

#### Array Partition

Como se tiene una estructura, donde los vectores A y B, están almacenados en memorias de tipo SIPO, se tiene acceso a cada elemento del vector de forma inmediata, por lo que se puede utilizar el _pragma_ `ARRAY_PARTITION` para indicar que el módulo podrá recibir como entrada los 1024 valores por vector de forma directa. De esta forma para un vector X, se podría tener el siguiente _pragma_

```
#pragma HLS ARRAY_PARTITION variable=X type=complete dim=1
```
Esto básicamente convertirá el arreglo de entrada, en múltiples entradas que cumplan con el largo máximo del array. Implementando en código queda:

```cpp
void eucDis(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT* C){
    #pragma HLS ARRAY_PARTITION variable=A type=complete  dim=1
    #pragma HLS ARRAY_PARTITION variable=B type=complete dim=1
    ap_uint<26> temp = 0;
    eachElement:for(int index = 0; index < VECTOR_LENGTH; index ++){
      temp += (A[index]-B[index])*(A[index]-B[index]);
    }
    C[0] = hls::sqrt(temp);
}
```
Inherentemente, este _pragma_ no trae una mejora directa en términos de latencia o uso de recursos, es más éste ultimo aumenta dado el aumento de entradas:

| **Latencia** _ciclos_ | **BRAM** _%_ | **DSP** _%_ | **FF** _%_ | **LUT** _%_ | **URAM** _%_ |
|-|-|-|-|-|-|
| 1035| 0 | ~0 | ~0 | 10 | 0 |

Sin embargo, este _pragma_ en combinación con el siguiente permiten reducir la latencia.

#### Unroll

Este _pragma_ permite desenrrollar el _loop_, para que las operaciones se hagan en paralelo. Se utiliza en combinación con el _pragma_ de _Array_Partition_ dado que al tener todas las entradas disponibles, se puede, **en teoría**, trabajar en paralelo la operación del _loop_ con todos los valores (como se verá más adelante hay limitaciones que impiden realizar esto). Para utilizarlo:
```
#pragma HLS unroll factor=X
```
Donde X es el número de elementos que se desenrrollan, en nuestro caso por ejemplo, se podría escoger X= 2, con un _loop_ de 1024 iteraciones, significa que se harían 512 operaciones en un ciclo y luego se harían otras 512. **Realizando pruebas, se encontró que para este modulo un factor de X = 128, permitía maximizar el número de ciclos, manteniendo un uso de recursos razonable, factores superiores como X>=256, disminuían uno o dos ciclos, con el costo de un uso de recursos estimado cercano al 80%, es por esto que se optó por el valor X=128.** De esta forma el código queda de la siguiente manera:

```
```

| **Latencia** _ciclos_ | **BRAM** _%_ | **DSP** _%_ | **FF** _%_ | **LUT** _%_ | **URAM** _%_ |
|-|-|-|-|-|-|
| 21| 0 | ~0 | ~0 | 10 | 0 |

## Testbench
La comparación realizada busca encontrar dos métricas de comparación, en primer lugar un error directo, que corresponde al valor absoluto entre el resultado esperado (obtenido mediante el cálculo de valores desde la goldenReference) y el valor obtenido desde el módulo inferido. En segundo lugar, se obtiene una métrica de error relativo, la cual es simplemente el porcentaje obtenido del error directo, sobre el valor esperado. En resumen:

```
errorDirecto = Esperado - Obtenido

errorRelativo = 100*errorDirecto/Esperado
```
