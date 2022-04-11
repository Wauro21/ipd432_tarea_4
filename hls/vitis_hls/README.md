# Análisis del código utilizado



## Testbench
La comparación realizada busca encontrar dos métricas de comparación, en primer lugar un error directo, que corresponde al valor absoluto entre el resultado esperado (obtenido mediante el cálculo de valores desde la goldenReference) y el valor obtenido desde el módulo inferido. En segundo lugar, se obtiene una métrica de error relativo, la cual es simplemente el porcentaje obtenido del error directo, sobre el valor esperado. En resumen:

```
errorDirecto = Esperado - Obtenido

errorRelativo = 100*errorDirecto/Esperado
```
