Dentro de la carpeta comprimida se encuentran 2 archivos del programa
Program.c
program.exe
Para la ejecución adecuada del programa se sigue lo siguiente:

Opción 1: utilizar el archivo.exe existente
 1.- Ingresar en la terminal el comando: ./program.exe

Opción 2: para generar un nuevo archivo.exe
1.- Abrir una nueva terminar 
2.- ingresar el comando: gcc Nombre_de_archivo.c -o Nombre_del_archivo_exe
    en nuestro caso: gcc Program.c -o program
3.- Una vez generado el archivo.exe se ingresa el comando: ./Nombre_de_archivo.exe
    nuestro caso: ./program.exe
 
  
                        ::::::::::::::::::::::explicacion personal::::::::::::::::
Los árboles en C son estructuras de datos donde cada elemento (nodo) puede tener "hijos". Aprendí a crearlos usando punteros, que al principio me confundieron un poco, pero luego entendí que son como "flechas" que conectan los nodos. También aprendí a insertar nuevos elementos y a recorrer el árbol de diferentes maneras (como en orden, preorden y postorden) usando funciones que se llaman a sí mismas (recursión). Lo más importante es no olvidar liberar la memoria que usé para crear los nodos, ¡para no tener problemas después!

