# Uso de host scripts

Para poder interactuar con el coprocesador se implementa el script `coprocessorTesting.py` el cual permite enviar dos vectores, con valores entre 0-255, para ser almacenados en el dispositivo (A y B), los cuales se generan de forma aleatoria y son enviados a través de puerto serial, como también el envío de un **comando** para solicitar la operación de distancia Euclidiana.

Para su uso, basta desde una terminal utilizar el siguiente comando:
```
python coprocessorTesting.py -port=COMx
```

Donde `COMx` corresponde al puerto asociado a la FPGA. Como resultado se espera el resultado obtenido de forma teórica para la operación y el obtenido desde el coprocesador, así como la diferencia:

```
Distancia de Manhattan. Host: 3327.5022163779245 - Device: 3328 - Diff: -0.49778362207553073

```
