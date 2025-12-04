Tabla Hash (Encadenamiento) - Tabla de Símbolos

Descripción:
Programa en C que implementa una tabla hash para almacenar identificadores (claves) con atributos: `clave`, `tipo`, `ambito`, `valor`. Se usa encadenamiento (listas ligadas) para manejar colisiones. La entrada de los atributos es manual por consola.

Archivos:
- `symbol_table.h` - Definición de `Symbol` y prototipos.
- `symbol_table.c` - Implementación de la tabla hash (insertar, buscar, eliminar, imprimir, liberar).
- `main.c` - Menú interactivo para agregar/buscar/eliminar/mostrar.

Compilación (terminal):

gcc main.c symbol_table.c -o symtable.exe

Ejecución:

./symtable.exe

Notas:
- `TABLE_SIZE` está definido en `symbol_table.h` y puede ajustarse.
- Hash utilizado: metodo `djb2`.
- Para colisiones se usa encadenamiento; las operaciones son O(1) en promedio.
