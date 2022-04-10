# High Level Synthesis

En la siguiente sección se explicará el proceso para a partir de un código implementado en lenguaje C++, poder implementar un bloque (circuito lógico) que sea capaz de tomar dos entradas de 1024 valores x 8 bits, para entregar la distancia Euclidiana de ambos vectores. Este proceso de tomar un código de alto nivel (C++) y llevarlo a una implementación en FPGA se denomina _High Level Synthesis_.

<p align="center">
  <img src="graphic_rsrc/eucMod.png">
</p>

En la Figura, se puede ver el bloque que se espera implementar. Como entrada, los vectores **A** y **B**, cada uno de 1024x8 bits. La salida, **C**, corresponde a un **único valor de 26 bits.**

## Requisitos:

Para poder seguir las instrucciones que se listaran a continuación es necesario tener previamente instalado una versión de **Vivado y Vitis HLS.** Durante el desarrollo de este tutorial se estuvo trabajando con las versiones otorgadas por Xilinx: 2021.1

Si bien no es requisito, pero el hardware utilizado para el presente tutorial corresponde a una tarjeta de desarrollo: **Nexys 4 DDR**, con un chip **xc7a100tcsg324-1**.


## Instrucciones:

### Vitis HLS: Generación de módulo a partir de código de alto nivel

#### 1. Creación de proyecto en Vitis HLS
<p align="center">
  <img src="graphic_rsrc/create_project.gif">
</p>

En primer lugar se tiene que generar un nuevo proyecto dentro de Vitis HLS, para ello se puede hacer click en: "Create Project", esto desplegara un menú con opciones:

<p align="center">
  <img src="graphic_rsrc/new_project.png">
</p>

Para el nombre del proyecto / **Project Name**, se puede escoger cualquiera, en el caso de este tutorial se eligió: _eucDis__. En la ubicación es recomendable escoger la carpeta _vitis_hls_ que se encuentra dentro de los archivos del repositorio.  En el caso de este ejemplo la carpeta completa del repositorio ha sido clonada en la carpeta de usuario (/home/mauricio/). Luego de configurar estos parámetros se da click a _Next_.

<p align="center">
  <img src="graphic_rsrc/add_sources.png">
</p>

En este menú se podrán añadir los códigos fuentes, en este caso, corresponden a los códigos en C++ que describen la funcionalidad que se busca, un módulo de cálculo de distancia Euclidiana. **En primer lugar**, haciendo click en _Add Files_, se añaden los archivos: _eucMod.cpp_ y _eucMod.h_, que se encuentran dentro de la carpeta [vitis_hls](vitis/hls). **Luego de esto**, en el apartado denominado _Top Function_, se hace click en _Browse_ para escoger la función principal, que en este caso corresponde a la denominada _eucDis_.
