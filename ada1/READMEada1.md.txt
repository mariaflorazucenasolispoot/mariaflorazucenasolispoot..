Explicación del código:


El programa utiliza estructuras de datos como pilas que se apoyan en memoria dinámica, la pila se usa para almacenar temporalmente los operadores mientras se recorre la expresión infija.
durante la lectura de expresiones el código está preparado para leer expresiones desde archivos de texto en este caso nuestro archivo de entrada es expr_infijas.txt, después se genera las expresiones equivalentes en su forma postfija y las guarda en el archivo de salida el cual es expr_posfijas.txt.
En el algoritmo de conversión tenemos principalmente a el algoritmo "Shunting Yard" de Dijkstra, que funciona cuando encuentra un operando (letra o número), y lo manda directamente a la salida en forma postfija, si se encuentra un operador (+, -, *, /, ^), se maneja su precedencia de acuerdo al la importancia que ya habíamos declarado y se apila/desapila de acuerdo con las reglas, los paréntesis se usan para controlar el orden y se manejan aparte, una vez terminada la lectura y conversión, el resultado en notación postfija se escribe en el archivo de salida.

- los #include los usamos para la memoria, la manipulación de las cadenas y funciones como isdigit(). 

- las pilas dinámicas:
    definimos el tope, la capacidad y el arreglo dinámico de char el cual son elementos. 
    como funciones principales sobre la pila de caracteres y números tenemos, la reserva de memoria para el arreglo dinámico y lo inicializamos en -1 para hacer referencia a que esta vacía, de igual manera devolvemos si esta vacía el arreglo, insertamos c si hay un espacio, devolvemos el tope y lo decrementa, devolvemos caracteres y liberamos el arreglo. 
    (Estas operaciones están comentadas en el código.)

- Definimos el orden y los operadores que usaremos y la prioridad que cada uno de ellos tiene. 

-Para la conversión de infija a postfija 
    Creamos una pila de caracteres con capacidad strlen(infija)+1, recorremos infija caracter por caracter, si isdigit(infija[i]) entonces copiamos todos los dígitos consecutivos al postfija y se añade ' ' como separador, usamos continue para no avanzar otra vez i.
    Si tenemos '(' entonces se apila y si hay ')' entonces se desapila hasta encontrar '(' y la elimina.
    Si esOperador(infija[i]) entonces desapila operadores del stack mientras la precedencia del operador en el tope sea >= precedencia del actual, escribiéndolos en posfija con espacios, luego se apila el operador actual.
    Al final desapila todo lo que quede y termina con '\0'

-Para la evaluación de la postfija:

    Creamos un pilaNumero y recorremos postfija si se encuentran dígitos consecutivos se construye un token[], token[j] = '\0', hace apilarNumero(atof(token)), (atof convierte cadena a double). si encuentra un operador val2 = desapilarNumero(), val1 = desapilarNumero(), y hace la operación val1 operación val2, luego apilarNumero(resultado).
    En el main, se abre expr_infijas.txt en modo lectura y expr_posfijas.txt en modo escritura, si falla al abrir, imprime un mensaje de error. Se lee línea por línea con fgets(infija, sizeof(infix), entrada), Se elimina el \n con infija[strcspn(infija, "\n")] = 0;, se usa strtok(infija, ";") para separar múltiples expresiones en la misma línea usando ; como delimitador, recortamos los espacios al inicio y fin de cada expresion, si expresion no está vacía llamamos a infijaApostfija(expresion, postfija) o Llamamos a evaluarPostfija(popostfija).


- Para compilar el programa se ejecuta por medio de la linea de comandos. 
   (verificamos encontrarnos en la direcciíon donde  se encuentra la carpeta del proyecto) 
   Luego, ingresamos los siguientes comandos en la terminal.
    
    1.-Para ejecutar el archivo .c y generar el .exe con nombre app
    gcc InfijoAPostfijoApp.c -o app 

    2.- Para ejecutar el archivo .exe y obtener el archivo de salida .txt 
    ./app.exe