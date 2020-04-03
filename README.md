Guía 9: Métodos de búsqueda - Tablas Hash 

El ejercicio de la guía consistía en crear un programa el cual fuera capaz de ingresar cierta cantidad de números (en este caso 20), dentro de un arreglo utilizando la lógica de una tabla hash.  

Se utilizo como función hash, el ingresar datos por División/Modulo y al detectar colisiones el programa debe ser capaz de utilizar 4 métodos para poder solucionarlas: 

• Reasignación Prueba Lineal • Reasignación Prueba Cuadrática • Reasignación Doble Dirección Hash • Encadenamiento  

Cada método ser parte de una clase tipo Hash, la cual tendrá implementada todos estos métodos además de la función hash básica, sin embargo, para que el programa se pueda ejecutar es requerido seleccionar uno de los métodos de colisión.  

Para ejecutar el programa correctamente, es necesario pasar 1 parámetro al momento de ejecutarlo; tiene que ser solo una de estas 4 letras: L C D E, sino el programa no funcionara debido a que no se habrá seleccionado ningún método para arreglar las colisiones. 

L para prueba lineal, C para prueba cuadrática, D para doble dirección hash y E para encadenamiento 

Para poder hacer funcionar el programa utiliza un archivo makefile, el cual nos sirve para poder automatizar la compilación y posterior ejecución del programa. 

***Para utilizar el makefile correctamente y lograr ejecutar el programa de la mejor manera se recomienda: 

Abrir la consola en la carpeta donde se encuentran los archivos 

Escribir en la consola: make all 

Y luego: ./Programa “L" o “C" o “D" o “E" 

Con esto debería ser más que suficiente. 

Para la elaboración del programa se utilizó: 

-Gnome builder 

Sistema operativo: 

-Ubuntu Ubuntu 18.04.3 

Desarrolladores: 

-----------------------------------Pedro Salinas Soto------------------------------------ 
