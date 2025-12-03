Explicación del código:
En el código incluimos las librería estándar de entrada y salida, la de utilidades que nos permite usar malloc, rand y free, la de time para el manejo del tiempo y la de unistd para detener la ejecución. 

Definimos la estructura del cliente el cual tendrá un tiempo de servicio y la estructura de la cola.

Definimos las funciones de la cola usando memoria dinámica, se verifica si esta vacía, si esta llena, se encola y se desencola. 

definimos que un cliente puede tener de 1 a 10 transacciones, asignamos una cola al azar y calculamos el tiempo de espera.  

En la función principal inicializamos la semilla para los números aleatorios, creamos las colas, los 15 clientes y los asignamos aleatoriamente a alguna de las 3 colas, al atender a los clientes los desencolamos, simulamos el tiempo de servicio y acumulamos el tiempo de espera y el numero de clientes atendidos, también calculamos el tiempo promedio de espera por cola e imprimimos la cantidad de clientes que fueron atendidos al fiunal liberamos la memoria dinámica reservada usando malloc para evitar fugas. 
  
Para compilar el programa se ejecuta por medio de la línea de comandos. 
   (verificamos encontrarnos en la dirección donde  se encuentra la carpeta del proyecto) 
   Luego, ingresamos los siguientes comandos en la terminal.
    
    1.-Para ejecutar el archivo .c y generar el .exe con nombre ada2
    gcc program.c -o ada2

    2.- Para ejecutar el archivo .exe y obtener el archivo de salida .txt 
    ./ada2.exe 