# Script Útiles

En esta sección se describe el funcionamiento y utilización de los scripts incluidos junto al repositorio.

## Índice

1. [goldenGenerator](#goldengenerator)
2. [generateTemplate](#generatetemplate)

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

## generateTemplate

Dado que al realizar _Array Partition_ el modulo resultante, tendrá un puerto por cada uno de los elementos de los vectores A y B, se hace difícil realizar la instanciación del módulo en un código system verilog, dado que el template autogenerado tendrá la forma:

```
eucDis_0 your_instance_name (
  .C_ap_vld(C_ap_vld),  // output wire C_ap_vld
  .ap_clk(ap_clk),      // input wire ap_clk
  .ap_rst(ap_rst),      // input wire ap_rst
  .ap_start(ap_start),  // input wire ap_start
  .ap_done(ap_done),    // output wire ap_done
  .ap_idle(ap_idle),    // output wire ap_idle
  .ap_ready(ap_ready),  // output wire ap_ready
  .A_0(A_0),            // input wire [7 : 0] A_0
  .A_1(A_1),            // input wire [7 : 0] A_1
  .A_2(A_2),            // input wire [7 : 0] A_2
  .A_3(A_3),            // input wire [7 : 0] A_3
  .A_4(A_4),            // input wire [7 : 0] A_4
  .
  .
  .
  .A_1023(A_1023),      // input wire [7 : 0] A_4
  .
  .
  .
  .B_0(B_0),            // input wire [7 : 0] B_0
  .
  .
  .
  .B_1023(B_1023),      // input wire [7 : 0] B_4
  .C(C)                // output wire [25 : 0] C
```

Donde por defecto, a cada puerto se le asigna un cable con un identificador único, debido a esto se entrega entre los archivos el script `generateTemplate.py`, el cual permite reemplazar estas asignaciones únicas en los puertos, por un bus que represente a los vectores, entregando como resultado un template de la siguiente forma:

```
eucDis_0 your_instance_name (
  .C_ap_vld(C_ap_vld),  // output wire C_ap_vld
  .ap_clk(ap_clk),      // input wire ap_clk
  .ap_rst(ap_rst),      // input wire ap_rst
  .ap_start(ap_start),  // input wire ap_start
  .ap_done(ap_done),    // output wire ap_done
  .ap_idle(ap_idle),    // output wire ap_idle
  .ap_ready(ap_ready),  // output wire ap_ready
  .A_0(A[0]),            // input wire [7 : 0] A_0
  .A_1(A[1]),            // input wire [7 : 0] A_1
  .A_2(A[2]),            // input wire [7 : 0] A_2
  .A_3(A[3]),            // input wire [7 : 0] A_3
  .A_4(A[4]),            // input wire [7 : 0] A_4
  .
  .
  .
  .A_1023(A[1023]),      // input wire [7 : 0] A_4
  .
  .
  .
  .B_0(B[0]),            // input wire [7 : 0] B_0
  .
  .
  .
  .B_1023(B[1023]),      // input wire [7 : 0] B_4
  .C(C)                // output wire [25 : 0] C
```

De esta forma, se puede trabajar con vectores (packed arrays), para la totalidad de puertos asociados a A y B. Para utilizar el script es necesario copiar el template entregado por el módulo IP, en un archivo de texto, por defecto (también incluido en el repositorio como `module_template.txt`), se busca un archivo llamado: `module_template.txt` y se entrega como salida un archivo de texto llamado : `corrected_template.txt` que contiene las correcciones realizadas. Los nombres de entrada y salida pueden ser cambiados mediante el uso de flags, para ver las opciones se puede correr el script de la siguiente forma: `python generateTemplate.py -h`, lo que da como resultado:

```
usage: generateTemplate.py [-h] [-if INPUTFILE] [-of OUTPUTFILE]

By default, the script will search for a template located in the same folder with the name <module_template.txt>, and will save the new template in the same folder with the name <corrected_template.txt>. This behaviour can be overriden
by passing arguments to the script

optional arguments:
  -h, --help            show this help message and exit
  -if INPUTFILE, --InputFile INPUTFILE
                        Indicates which template file to correct. By default it searches for: module_template.txt
  -of OUTPUTFILE, --OutputFile OUTPUTFILE
                        Indicates where to save the corrected template. By default it's saved to: corrected_template.txt

```
