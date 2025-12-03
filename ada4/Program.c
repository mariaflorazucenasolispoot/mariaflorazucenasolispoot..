#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------ESTRUCTURAS -------
typedef struct { //ESTRUCTURA ESTUDIANTE
    int matricula;
    char nombre[50];
    char apellido[50];
    float *calificaciones;
    int num_calificaciones;
} Estudiante;

typedef struct NodoArbol { //ESTRUCTURA NODO ARBOL
    Estudiante estudiante;
    struct NodoArbol *izquierda;
    struct NodoArbol *derecha;
} NodoArbol;

//estructura para lista dinamica de estudiantes
typedef struct {
    Estudiante *arr;
    int size;
} ListaEstudiantes;

// -------´PROTOTIPOS DE LAS FUNCIONES DE ARBOL ABB -------

//funciones para operaciones con la estructura estudiante
Estudiante crearEstudiante();
float calcularPromedio(float *calificaciones, int num_calificaciones);
NodoArbol* crearNodo(Estudiante e);
NodoArbol* insertarEstudiante(NodoArbol *raiz, Estudiante e);
NodoArbol* buscarEstudiante(NodoArbol* raiz, int matricula);
//funciones para reportes
void generarReportePorPromedio(NodoArbol* raiz);    
void reportePromedioMenor(NodoArbol* raiz);
void reportePromedioMayorIgual(NodoArbol* raiz);
void generarReportePorMatricula(NodoArbol* raiz);
int contarPromediosMenoresQue(NodoArbol* raiz, float valor);
void contarMenoresAEstudiante(NodoArbol* raiz);
void mostrarNivel(NodoArbol* raiz, int nivel, int actual);
//funciones para eliminar, actualizar y visualizar
NodoArbol* eliminarEstudiante(NodoArbol* raiz, int matricula);
void actualizarUnaCalificacion(NodoArbol* raiz, int matricula);
void imprimirArbolVisual(NodoArbol* raiz, int espacio);
//funciones auxiliares
int compararPromedio(const void *a, const void *b);
int compararMatricula(const void *a, const void *b);




// MAIN
int main() {
    NodoArbol *raiz = NULL;
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Agregar estudiante\n");
        printf("2. Reporte por promedio (ordenado)\n");
        printf("3. Reporte promedios < 70\n");
        printf("4. Reporte promedios >= 70\n");
        printf("5. Reporte por matricula (ordenado)\n");
        printf("6. Contar alumnos con promedio menor al de una matricula\n");
        printf("7. Mostrar nodos de un nivel\n");
        printf("8. Eliminar estudiante\n");
        printf("9. Actualizar una calificacion\n");
        printf("10. Mostrar estructura del arbol ABB\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Estudiante nuevo = crearEstudiante();
                raiz = insertarEstudiante(raiz, nuevo);
                break;
            }
            case 2: generarReportePorPromedio(raiz); break;
            case 3: reportePromedioMenor(raiz); break;
            case 4: reportePromedioMayorIgual(raiz); break;
            case 5: generarReportePorMatricula(raiz); break;
            case 6: contarMenoresAEstudiante(raiz); break;
            case 7: {
                int nivel;
                printf("Ingrese nivel: ");
                scanf("%d", &nivel);
                printf("Nodos en el nivel %d: ", nivel);
                mostrarNivel(raiz, nivel, 0);
                printf("\n");
                break;
            }
            case 8: {
                int m;
                printf("Ingrese matricula a eliminar: ");
                scanf("%d", &m);
                raiz = eliminarEstudiante(raiz, m);
                break;
            }
            case 9: {
                int m;
                printf("Ingrese matricula: ");
                scanf("%d", &m);
                actualizarUnaCalificacion(raiz, m);
                break;
            }
            case 10: {
                printf("\n--- Estructura del arbol ABB ---\n");
                imprimirArbolVisual(raiz, 0);
                break;
            }
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}


//
float calcularPromedio(float *calificaciones, int num_calificaciones) {
    if (num_calificaciones == 0) return 0.0;
    float suma = 0;
    for (int i = 0; i < num_calificaciones; i++)
        suma += calificaciones[i];
    return suma / num_calificaciones;
}

//
Estudiante crearEstudiante() {
    Estudiante e;
    printf("Ingrese matricula: ");
    scanf("%d", &e.matricula);
    printf("Ingrese nombre: ");
    scanf("%s", e.nombre);
    printf("Ingrese apellido: ");
    scanf("%s", e.apellido);

    e.calificaciones = NULL;
    e.num_calificaciones = 0;
    float nota;
    printf("Ingrese calificaciones [0-10] (-1 para terminar):\n");
    while (1) {
        printf("Calificacion %d: ", e.num_calificaciones + 1);
        scanf("%f", &nota);
        if (nota == -1) break;
        //se agrega la calificacion al arreglo dinamico
        e.calificaciones = realloc(e.calificaciones, (e.num_calificaciones + 1) * sizeof(float));
        e.calificaciones[e.num_calificaciones] = nota;//asignar la nueva calificacion
        e.num_calificaciones++;//incrementar el contador de calificaciones
    }
    return e;
}

//
NodoArbol* crearNodo(Estudiante e) {
    NodoArbol *nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));//asignar memoria para el nuevo nodo
    nuevo->estudiante = e;//asignar el estudiante al nodo
    nuevo->izquierda = nuevo->derecha = NULL;//inicializar los punteros hijos a NULL
    return nuevo;
}

//
NodoArbol* insertarEstudiante(NodoArbol *raiz, Estudiante e) {
    if (raiz == NULL) return crearNodo(e);//si el arbol esta vacio, crear un nuevo nodo
    if (e.matricula < raiz->estudiante.matricula)//insertar en el subarbol izquierdo
        raiz->izquierda = insertarEstudiante(raiz->izquierda, e);//insertar en el subarbol derecho
    else if (e.matricula > raiz->estudiante.matricula)//evitar duplicados
        raiz->derecha = insertarEstudiante(raiz->derecha, e);
    return raiz;
}

//
NodoArbol* buscarEstudiante(NodoArbol* raiz, int matricula) {
    if (raiz == NULL || raiz->estudiante.matricula == matricula) return raiz;//encontrado o no existe
    if (matricula < raiz->estudiante.matricula)//buscar en el subarbol izquierdo
        return buscarEstudiante(raiz->izquierda, matricula);
    else
        return buscarEstudiante(raiz->derecha, matricula);//buscar en el subarbol derecho
}

//funciones estructura auxiliar
void recolectarEstudiantes(NodoArbol *raiz, ListaEstudiantes *lista) {
    if (raiz == NULL) return;
    recolectarEstudiantes(raiz->izquierda, lista);
    lista->arr = realloc(lista->arr, (lista->size + 1) * sizeof(Estudiante));
    lista->arr[lista->size] = raiz->estudiante;
    lista->size++;
    recolectarEstudiantes(raiz->derecha, lista);
}

//
int compararPromedio(const void *a, const void *b) {
    Estudiante *ea = (Estudiante*)a;
    Estudiante *eb = (Estudiante*)b;
    float pa = calcularPromedio(ea->calificaciones, ea->num_calificaciones);
    float pb = calcularPromedio(eb->calificaciones, eb->num_calificaciones);
    if (pa < pb) return -1;
    else if (pa > pb) return 1;
    return 0;
}
//
int compararMatricula(const void *a, const void *b) {
    Estudiante *ea = (Estudiante*)a;
    Estudiante *eb = (Estudiante*)b;
    return ea->matricula - eb->matricula;
}
//
void generarReportePorPromedio(NodoArbol* raiz) {
    ListaEstudiantes lista = {NULL, 0};
    recolectarEstudiantes(raiz, &lista);
    qsort(lista.arr, lista.size, sizeof(Estudiante), compararPromedio);

    printf("\n--- Reporte por promedio (menor a mayor) ---\n");
    for (int i = 0; i < lista.size; i++) {
        float prom = calcularPromedio(lista.arr[i].calificaciones, lista.arr[i].num_calificaciones);
        printf("Matricula: %d, Promedio: %.2f, Nombre: %s %s\n",
               lista.arr[i].matricula, prom, lista.arr[i].nombre, lista.arr[i].apellido);
    }
    free(lista.arr);
}
//
void reportePromedioMenor(NodoArbol* raiz) {
    ListaEstudiantes lista = {NULL, 0};
    recolectarEstudiantes(raiz, &lista);
    qsort(lista.arr, lista.size, sizeof(Estudiante), compararPromedio);

    printf("\n--- Reporte de promedios menores a 7.0 ---\n");
    for (int i = 0; i < lista.size; i++) {
        float prom = calcularPromedio(lista.arr[i].calificaciones, lista.arr[i].num_calificaciones);
        if (prom < 7.0)
            printf("Matricula: %d, Promedio: %.2f, Nombre: %s %s\n",
                   lista.arr[i].matricula, prom, lista.arr[i].nombre, lista.arr[i].apellido);
    }
    free(lista.arr);
}
//
void reportePromedioMayorIgual(NodoArbol* raiz) {
    ListaEstudiantes lista = {NULL, 0};
    recolectarEstudiantes(raiz, &lista);
    qsort(lista.arr, lista.size, sizeof(Estudiante), compararPromedio);

    printf("\n--- Reporte de promedios mayores o iguales a 7.0 ---\n");
    for (int i = 0; i < lista.size; i++) {
        float prom = calcularPromedio(lista.arr[i].calificaciones, lista.arr[i].num_calificaciones);
        if (prom >= 7.0)
            printf("Matricula: %d, Promedio: %.2f, Nombre: %s %s\n",
                   lista.arr[i].matricula, prom, lista.arr[i].nombre, lista.arr[i].apellido);
    }
    free(lista.arr);
}

//
void generarReportePorMatricula(NodoArbol* raiz) {
    ListaEstudiantes lista = {NULL, 0};
    recolectarEstudiantes(raiz, &lista);
    qsort(lista.arr, lista.size, sizeof(Estudiante), compararMatricula);

    printf("\n--- Reporte de estudiantes ordenados por matricula ---\n");
    for (int i = 0; i < lista.size; i++) {
        printf("Matricula: %d, Nombre: %s %s\n",
               lista.arr[i].matricula, lista.arr[i].nombre, lista.arr[i].apellido);
    }
    free(lista.arr);
}
//
int contarPromediosMenoresQue(NodoArbol* raiz, float valor) {
    if (raiz == NULL) return 0;
    float prom = calcularPromedio(raiz->estudiante.calificaciones, raiz->estudiante.num_calificaciones);
    int count = (prom < valor) ? 1 : 0;
    count += contarPromediosMenoresQue(raiz->izquierda, valor);
    count += contarPromediosMenoresQue(raiz->derecha, valor);
    return count;
}
//
void contarMenoresAEstudiante(NodoArbol* raiz) {
    int matricula;
    printf("Ingrese matricula para comparar: ");
    scanf("%d", &matricula);
    NodoArbol* nodo = buscarEstudiante(raiz, matricula);
    if (nodo == NULL) {
        printf("No se encontro la matricula %d.\n", matricula);
        return;
    }
    float promRef = calcularPromedio(nodo->estudiante.calificaciones, nodo->estudiante.num_calificaciones);
    int menores = contarPromediosMenoresQue(raiz, promRef);
    printf("Hay %d alumnos con promedio menor que el estudiante %d (%.2f).\n", menores, matricula, promRef);
}
//
void mostrarNivel(NodoArbol* raiz, int nivel, int actual) {
    if (raiz == NULL) return;
    if (actual == nivel)
        printf("%d ", raiz->estudiante.matricula);
    else {
        mostrarNivel(raiz->izquierda, nivel, actual + 1);
        mostrarNivel(raiz->derecha, nivel, actual + 1);
    }
}

//
NodoArbol* eliminarEstudiante(NodoArbol* raiz, int matricula) {
    if (raiz == NULL) return NULL;//arbol vacio
    if (matricula < raiz->estudiante.matricula)//buscar en el subarbol izquierdo
        raiz->izquierda = eliminarEstudiante(raiz->izquierda, matricula);//buscar en el subarbol derecho
    else if (matricula > raiz->estudiante.matricula)//buscar en el subarbol derecho
        raiz->derecha = eliminarEstudiante(raiz->derecha, matricula);//nodo encontrado
    else {//nodo encontrado
        if (raiz->izquierda == NULL) {//caso 1 y 2: sin hijo o un hijo
            NodoArbol* temp = raiz->derecha;
            free(raiz->estudiante.calificaciones);
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {//caso 1 y 2: sin hijo o un hijo
            NodoArbol* temp = raiz->izquierda;
            free(raiz->estudiante.calificaciones);
            free(raiz);
            return temp;
        }
        NodoArbol* sucesor = raiz->derecha;//caso 3: dos hijos
        while (sucesor->izquierda != NULL)
            sucesor = sucesor->izquierda;
        raiz->estudiante = sucesor->estudiante;
        raiz->derecha = eliminarEstudiante(raiz->derecha, sucesor->estudiante.matricula);//eliminar sucesor
    }
    return raiz;
}
//
void actualizarUnaCalificacion(NodoArbol* raiz, int matricula) {
    NodoArbol* nodo = buscarEstudiante(raiz, matricula);//buscar el estudiante por matricula
    if (nodo == NULL) {
        printf("No se encontro la matricula %d\n", matricula);
        return;
    }

    printf("El estudiante tiene %d calificaciones.\n", nodo->estudiante.num_calificaciones);
    for (int i = 0; i < nodo->estudiante.num_calificaciones; i++)//mostrar calificaciones
        printf("%d) %.2f\n", i + 1, nodo->estudiante.calificaciones[i]);

    int pos;
    printf("Seleccione el numero de calificacion a modificar: ");
    scanf("%d", &pos);//ajustar indice
    pos--;//

    if (pos >= 0 && pos < nodo->estudiante.num_calificaciones) {
        float nueva;
        printf("Ingrese nueva calificacion (0-10): ");
        scanf("%f", &nueva);
        nodo->estudiante.calificaciones[pos] = nueva;
        printf("Calificacion actualizada correctamente.\n");
    } else {
        printf("Numero de calificacion invalido.\n");
    }
}
//
void imprimirArbolVisual(NodoArbol* raiz, int espacio) {
    if (raiz == NULL) return;

    espacio += 8;
    imprimirArbolVisual(raiz->derecha, espacio);

    printf("\n");
    for (int i = 8; i < espacio; i++)
        printf(" ");
    printf("%d\n", raiz->estudiante.matricula);

    imprimirArbolVisual(raiz->izquierda, espacio);
}
