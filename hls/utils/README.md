# Script Útiles

En esta sección se describe el funcionamiento y utilización de los scripts incluidos junto al repositorio.

## goldenGenerator

Este script se encarga de generar un archivo _csv_ que contiene la goldenreference utilizada por Vitis HLS para hacer las pruebas entre los módulos. El archivo generado contiene 1024 filas de dos valores, por lo que corresponde a los valores para dos vectores de 1024 valores.

Para utilizarlo basta con correr el comando, con una terminal ubicada en el directorio /hls/utils:
```
python goldenGenerator.py
```

De esta manera, automáticamente generará un nuevo archivo de referencia, en la ubicación esperada por Vitis HLS, en el caso de este tutorial: _/hls/vitis_hls/goldenreference.csv_. El script puede ser configurado para variar el nombre del archivo de salida, la ubicación de este y también el largo de los vectores generados. Para modificar estos parámetros se puede utilizar los argumentos provistos por el script, para revisarlos utilice el comando: `python goldenGenerator.py -h` que desplegará la opciones:

```
usage: goldenGenerator.py [-h] [-oP OUTPUTPATH] [-nf NAMEFILE] [-l LENGTH]

This script generates a goldenreference file of 2 vectors, with 1024 random values from 0-255. The output is a csv file, by default, saved at: vitis_hls/goldenreference.csv

optional arguments:
  -h, --help            show this help message and exit
  -oP OUTPUTPATH, --OutputPath OUTPUTPATH
                        Indicates where to save the goldenreference file. By default it's saved to: vitis_hls/
  -nf NAMEFILE, --nameFile NAMEFILE
                        Select a name for the outputfile, by default it's: goldenreference
  -l LENGTH, --Length LENGTH
                        The length of the vectors to generate, by default it's 1024

```

A continuación se deja un ejemplo dónde se genera un nuevo archivo ubicado en la carpeta _/hls/utils/_, con el nombre `prueba_golden` y un largo de 10 valores por vector:

```
python goldenGenerator.py -oP /home/mauricio/ipd432_tarea_4/hls/utils -nF prueba_golden -l 10
```
