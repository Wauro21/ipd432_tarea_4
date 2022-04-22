# Script Útiles incluidos

## Índice

- [super host cmd](#super-host-cmd)
- [latenc yanalyzer](#latency_analyzer)

## super host cmd

Este script permite iniciar los trials y obtener métricas, a partir de las operaciones que ocurren dentro del SoC. Además permite _seedear_ la función random implementada dentro del PS.

Para su utilización se pueden incluir los siguientes argumentos:
```
usage: super_host_cmd.py [-h] -N N -port PORT [-seed [SEED]]

Script to initiate the trial operations in the SoC

optional arguments:
  -h, --help    show this help message and exit
  -N N          Number of trials
  -port PORT
  -seed [SEED]

```

Un ejemplo de utilización de este script:

```
python super_host_cmd.py -port <port> -N 1000
```

Donde `<port>` corresponde al puerto. Se escoge `-N 1000` para realizar 1000 trials. **Note que el PS recibe el número de trials como una variable u16, por lo que el límite a la cantidad de trials que se puede enviar es 1023.**


## latency analyzer

Este script permite realizar el análisis de latencia a partir de los datos exportados desde el software de captura. Para su utilización se pueden incluir los siguientes argumentos:

```
usage: latency_analyzer.py [-h] [-if INPUTFILE]

This script runs analytics on the output file taken from the logic analyzer, to measure the latency of PS and PL operations in the Zybo

optional arguments:
  -h, --help            show this help message and exit
  -if INPUTFILE, --InputFile INPUTFILE
                        File that contains the exported values from the logic analyzer
```

Un ejemplo de su utilización:

```
python latency_analyzer.py -if eucDis_32_int_latency_1000_trials.csv
```

**Note que dentro de los archivos incluidos, se encuentran `eucDis_32_int_latency_1000_trials.csv` y `eucDis_32_float_latency_1000_trials.csv` que corresponden a mediciones de latencia para ambos módulos, para 1000 trials.**
