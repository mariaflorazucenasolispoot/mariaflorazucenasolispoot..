#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Código fuente base para el ordenamiento de arreglos dinámicos de números flotantes

// Estructura del arreglo
typedef struct {
    float *data;      // Apuntador al arreglo dinámico
    int size;         // Tamaño del arreglo
} Array;

// Funcion para crear un arreglo con números flotantes aleatorios
Array* createRandomArray(int n) {
    if (n <= 0) {
        printf("Error: Array size must be positive.\n");
        return NULL;
    }

    // Asignar memoria para la estructura del arreglo
    Array *arr = (Array*)malloc(sizeof(Array));
    if (arr == NULL) {
        printf("Error: Memory allocation failed for Array structure.\n");
        return NULL;
    }

    // Asignar memoria para el arreglo de datos
    arr->data = (float*)malloc(n * sizeof(float));
    if (arr->data == NULL) {
        printf("Error: Memory allocation failed for array data.\n");
        free(arr);
        return NULL;
    }
    
    arr->size = n;

    // Inicializar la semilla aleatoria
    srand(time(NULL));

    // Llenar el arreglo con números flotantes aleatorios (0.0 a 1000.0)
    for (int i = 0; i < n; i++) {
        arr->data[i] = ((float)rand() / RAND_MAX) * 1000.0f;
    }
    
    return arr;
}

// Funcion para crear un arreglo con valores definidos por el usuario
Array* createArray(int n) {
    if (n <= 0) {
        printf("Error: Array size must be positive.\n");
        return NULL;
    }
    
    Array *arr = (Array*)malloc(sizeof(Array));
    if (arr == NULL) {
        printf("Error: Memory allocation failed for Array structure.\n");
        return NULL;
    }
    
    arr->data = (float*)malloc(n * sizeof(float));
    if (arr->data == NULL) {
        printf("Error: Memory allocation failed for array data.\n");
        free(arr);
        return NULL;
    }
    
    arr->size = n;
    
    printf("Enter %d floating-point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%f", &arr->data[i]);
    }
    
    return arr;
}

// Funcion para desplegar el arreglo
void displayArray(Array *arr) {
    if (arr == NULL || arr->data == NULL) {
        printf("Error: Array is empty or not initialized.\n");
        return;
    }
    
    printf("\nArray (size = %d):\n", arr->size);
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%.2f", arr->data[i]);
        if (i < arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

// Funcion para copiar un arreglo (útil para probar múltiples algoritmos de ordenamiento)
Array* copyArray(Array *source) {
    if (source == NULL || source->data == NULL) {
        return NULL;
    }
    
    Array *copy = (Array*)malloc(sizeof(Array));
    if (copy == NULL) {
        return NULL;
    }
    
    copy->data = (float*)malloc(source->size * sizeof(float));
    if (copy->data == NULL) {
        free(copy);
        return NULL;
    }
    
    copy->size = source->size;
    for (int i = 0; i < source->size; i++) {
        copy->data[i] = source->data[i];
    }
    
    return copy;
}

// Funcion para liberar la memoria asignada para el arreglo
void freeArray(Array *arr) {
    if (arr != NULL) {
        if (arr->data != NULL) {
            free(arr->data);
        }
        free(arr);
    }
}

// Funcion para intercambiar dos elementos (funcion auxiliar para algoritmos de ordenamiento)
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// ============================================
// ALGORITMOS DE ORDENAMIENTO PARA IMPLEMENTAR
// ============================================

// Bubble Sort -------------------------------

void bubbleSort(Array *arr) {
    if (arr == NULL || arr->data == NULL) {
        return;
    }

    printf("Aplicando Bubble Sort...\n");

    int i, j;
    int n = arr->size;
    float *data = arr->data;

    // Se añadió un contador para el número de iteraciones (comparaciones)
    int iteraciones = 0;

    // Se añadió un contador para el número de swaps (intercambios)
    int swaps = 0;

    // Se modificó el bucle externo para recorrer todas las pasadas del algoritmo
    for (i = 0; i < n - 1; i++) {

        // Se agregó una optimización opcional: bandera para detectar si ya está ordenado
        int ordenado = 1;

        // Se recorre el arreglo comparando elementos adyacentes
        for (j = 0; j < n - i - 1; j++) {
            iteraciones++;  // Se incrementa el contador de comparaciones

            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                swaps++;       // Se incrementa el contador de swaps
                ordenado = 0;  //  Indica que se realizó un intercambio
            }
        }

        // Si en una pasada no hubo swaps, el arreglo ya está ordenado
        if (ordenado) {
            break;
        }
    }

    //  Se agregó la impresión final de estadísticas
    printf("\nEstadísticas del Bubble Sort:\n");
    printf("Iteraciones (comparaciones): %d\n", iteraciones);
    printf("Intercambios (swaps): %d\n", swaps);
}

// Selection Sort -----------------------------------

void selectionSort(Array *arr) {
    if (arr == NULL || arr->data == NULL) {
        return;
    }

    int i, j, min_idx;
    int n = arr->size;

    unsigned long long iterations = 0ULL; 

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            iterations++; 
            if (arr->data[j] < arr->data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr->data[min_idx], &arr->data[i]);
        }
    }

    printf("\nNumero de iteraciones: %llu\n", iterations);
}

// Insertion Sort -----------------------------------

void insertionSort(Array *arr) {
    // Verificamos que el puntero al arreglo y a sus datos sea válido.
    if (arr == NULL || arr->data == NULL) {
        return;
    }
    
    int i, j;
    float key; // Esta será la variable para guardar el elemento que estamos insertando
    int n = arr->size; // Obtenemos el tamaño para que el código sea más limpio

    // --- Inicio del Algoritmo ---
    
    // 1. Empezamos el bucle principal en el segundo elemento (índice 1).
    //    Imaginamos que el primer elemento (índice 0) ya es una
    //    sub-lista ordenada por sí sola.
    for (i = 1; i < n; i++) {
        
        // 2. 'key' toma el valor del elemento actual.
        //    Este es el elemento que intentaremos "insertar" en la
        //    parte izquierda (la que ya está ordenada).
        key = arr->data[i];
        
        // 3. 'j' se inicializa en el índice justo ANTES de 'key'.
        //    Usaremos 'j' para movernos "hacia atrás" (hacia la izquierda)
        //    a través de la sub-lista ya ordenada.
        j = i - 1;

        // 4. Este bucle 'while' es el corazón del algoritmo:
        //    Mientras 'j' todavía esté dentro del arreglo (j >= 0) Y
        //    el elemento en la posición 'j' (arr->data[j]) sea MÁS GRANDE
        //    que el elemento que queremos insertar (key)...
        while (j >= 0 && arr->data[j] > key) {
            
            // ... movemos el elemento grande (arr->data[j]) una posición
            //     hacia la derecha (a arr->data[j + 1]).
            //     Esto crea un "hueco" para insertar 'key' más tarde.
            arr->data[j + 1] = arr->data[j];
            
            // ... retrocedemos 'j' para revisar el siguiente elemento
            //     de la sub-lista ordenada.
            j = j - 1;
        }
        
        // 5. Cuando el bucle 'while' termina, significa que:
        //    a) Llegamos al inicio del arreglo (j = -1)
        //    b) Encontramos un elemento más pequeño (o igual) que 'key'.
        //
        //    La posición correcta para 'key' es 'j + 1' (el "hueco" que creamos).
        arr->data[j + 1] = key;
    }
    
    // No necesitamos un 'return'. El arreglo se ordena "in-place"
    // (modificando el original).
}

// Quick Sort ------------------------------------

// Función partición
int partition(float *data, int low, int high) {
    float pivot = data[(low + high) / 2];
    int i = low;
    int j = high;

    while (i <= j) {
        while (data[i] < pivot) {
            i++;
        }
        while (data[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(&data[i], &data[j]);
            i++;
            j--;
        }
    }
    return i;
}
// Función recursiva de QuickSort
void quickSortRecursive(float *data, int low, int high) {
    if (low >= high) {
        return;
    }

    int index = partition(data, low, high);

    if (low < index - 1) {
        quickSortRecursive(data, low, index - 1);
    }

    if (index < high) {
        quickSortRecursive(data, index, high);
    }
}
// Función principal de QuickSort usada en el menú
void quickSort(Array *arr) {
    if (arr == NULL || arr->data == NULL) {
        return;
    }

    int n = arr->size;
    if (n <= 1) {
        return;
    }

    quickSortRecursive(arr->data, 0, n - 1);
}

// Merge Sort---------------------------------------

void mergeSort(Array *arr) {
    if (arr == NULL || arr->data == NULL) {
        return;
    }
    
    printf("Merge Sort - To be implemented\n");
    // TODO: Implement merge sort algorithm
}


// Cocktail Sort ------------------------------------

void cocktailSort(Array *arr) {
    printf("Aplicando Cocktail Sort...\n");
     if (arr == NULL || arr->data == NULL) return;
    
    float *a = arr->data; 
    int n = arr->size;

    int s=1, ini=0, fin=n-1, i, sw=0, it=0;
    float t; 

    while(s) {
        s=0; it++;
        // Ida ->
        for(i=ini; i<fin; ++i)
            if(a[i] > a[i+1]) { 
                printf("It %d(Ida): %.2f <-> %.2f\n", it, a[i], a[i+1]); 
                t=a[i]; a[i]=a[i+1]; a[i+1]=t; // Swap inline de floats
                s=1; sw++; 
            }
        
        if(!s) break;
        
        // Vuelta <-
        fin--;
        for(i=fin-1; i>=ini; --i)
            if(a[i] > a[i+1]) { 
                printf("It %d(Vuelta): %.2f <-> %.2f\n", it, a[i], a[i+1]); 
                t=a[i]; a[i]=a[i+1]; a[i+1]=t; // Swap inline de floats
                s=1; sw++; 
            }
        ini++;
    }
    printf("\nTotal Iteraciones: %d\nTotal Swaps: %d\n----------------\n", it, sw);
}

// Funciones auxiliares para Heap Sort
void heapify(float *data, int n, int i) {
    int largest = i;       // Inicializa el nodo raíz como el más grande
    int left = 2 * i + 1;  // Hijo izquierdo
    int right = 2 * i + 2; // Hijo derecho

    // Si el hijo izquierdo es más grande que la raíz
    if (left < n && data[left] > data[largest])
        largest = left;

    // Si el hijo derecho es más grande que el más grande hasta ahora
    if (right < n && data[right] > data[largest])
        largest = right;

    // Si el más grande no es la raíz
    if (largest != i) {
        swap(&data[i], &data[largest]);
        // Recursivamente aplica heapify en el subárbol afectado
        heapify(data, n, largest);
    }
}

// Heap Sort ------------------------------------

void heapSort(Array *arr) {
    if (arr == NULL || arr->data == NULL) {
        return;
    }

    printf("Aplicando Heap Sort...\n");

    int n = arr->size;
    float *data = arr->data;

    // Construir el heap (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(data, n, i);
    }

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz actual al final
        swap(&data[0], &data[i]);

        // Llamar heapify en el heap reducido
        heapify(data, i, 0);
    }
}
// Definir estructuras y funciones auxiliares para Tree Sort


// Tree Sort ----------------------------------

// Definición de la estructura del nodo del árbol
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Definición de la estructura del array
typedef struct Array {
    int *data;
    int size;
} Array;

// Función para crear un nuevo nodo
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Función para insertar un nodo en el árbol
Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // Si el dato es igual, no se inserta (para evitar duplicados)
    return root;
}

// Función para realizar el recorrido inorden del árbol y almacenar los datos ordenados en el array
void inOrderTraversal(Node *root, int *arr, int *index) {
    if (root != NULL) {
        inOrderTraversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inOrderTraversal(root->right, arr, index);
    }
}

// Función para liberar la memoria del árbol
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Tree Sort
void treeSort(Array *arr) {
    if (arr == NULL || arr->data == NULL || arr->size <= 0) {
        fprintf(stderr, "Error: Array inválido.\n");
        return;
    }

    printf("Aplicando Tree Sort...\n");

    // Paso 1: Construir el árbol binario de búsqueda
    Node *root = NULL;
    for (int i = 0; i < arr->size; i++) {
        root = insertNode(root, arr->data[i]);
    }

    // Paso 2: Recorrer el árbol inorden para obtener los elementos ordenados
    int *sortedArray = malloc(arr->size * sizeof(int));
    if (sortedArray == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el array ordenado.\n");
        freeTree(root);
        exit(EXIT_FAILURE);
    }

    int index = 0;
    inOrderTraversal(root, sortedArray, &index);

    // Paso 3: Copiar los elementos ordenados de vuelta al array original
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = sortedArray[i];
    }

    // Paso 4: Liberar la memoria utilizada
    freeTree(root);
    free(sortedArray);

    printf("Tree Sort completado.\n");
}

// Función para imprimir el array
void printArray(Array *arr) {
    printf("Array: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}



// Funciones auxiliares para Tournament Sort
typedef struct TournamentNode {
    float value;
    int index;
} TournamentNode;

// Definir funciones auxiliares para Tournament Sort
// (Para esta implementación, usaremos un enfoque de "heap" 
// que es más directo que usar la struct de arriba)


// Tournament Sort
void tournamentSort(Array *arr) {
    if (arr == NULL || arr->data == NULL || arr->size == 0) {
        return; // No hay nada que ordenar
    }

    printf("Aplicando Tournament Sort...\n");
    
    int n = arr->size;
    float *data = arr->data;

    // Para un torneo, necesitamos un "árbol" que almacene los ganadores.
    // Usar un arreglo de tamaño 2*n es una forma clásica y eficiente
    // de simular este árbol (similar a un Heap).
    // Usaremos un índice 1-based (la raíz es 1) para facilitar las matemáticas.
    int treeSize = 2 * n;
    
    // Asignamos memoria para nuestro árbol de torneo
    float *tree = (float*)malloc(treeSize * sizeof(float));
    
    // También necesitamos un lugar temporal para poner los resultados ordenados.
    float *sorted_arr = (float*)malloc(n * sizeof(float));

    if (tree == NULL || sorted_arr == NULL) {
        printf("Error: Fallo al asignar memoria para Tournament Sort.\n");
        if (tree) free(tree);
        if (sorted_arr) free(sorted_arr);
        return;
    }

    // --- Fase 1: Construcción del Torneo ---

    // Primero, llenamos la segunda mitad del árbol (las "hojas")
    // con INFINITO. Esto asegura que los "espacios vacíos" (si 'n' no
    // es potencia de 2) nunca ganen un partido.
    // Usamos INFINITY, que está definido en <math.h> (que ya incluiste).
    for (int i = n; i < treeSize; i++) {
        tree[i] = INFINITY;
    }

    // Ahora, copiamos nuestros números reales a las hojas,
    // ocupando los primeros 'n' espacios de la segunda mitad.
    for (int i = 0; i < n; i++) {
        tree[n + i] = data[i];
    }

    // Es hora de que jueguen.
    // Construimos el torneo "hacia arriba", desde las hojas hasta la raíz.
    // Empezamos en el último nodo padre (n-1) y subimos hasta la raíz (1).
    for (int i = n - 1; i > 0; i--) {
        // El valor de un padre es simplemente el ganador (el mínimo)
        // de sus dos hijos (i*2 e i*2 + 1).
        float hijo_izq = tree[i * 2];
        float hijo_der = tree[i * 2 + 1];
        tree[i] = (hijo_izq < hijo_der) ? hijo_izq : hijo_der;
    }

    // --- Fase 2: Extracción de Ganadores (El Ordenamiento) ---

    // El torneo inicial está listo. El ganador absoluto (el número más
    // pequeño) está en la raíz (tree[1]).
    
    // Repetimos 'n' veces, una por cada elemento.
    for (int k = 0; k < n; k++) {
        
        // 1. Obtenemos al ganador actual de la raíz.
        float ganador = tree[1];
        sorted_arr[k] = ganador; // Lo ponemos en nuestro arreglo de resultados

        // 2. Ahora, debemos "descalificar" a este ganador para la siguiente
        // ronda. Para hacer esto, tenemos que encontrar su posición
        // original en las hojas y reemplazarlo con INFINITO.

        // Podemos bajar por el árbol (O(log n)) para encontrarlo.
        int idx_hoja = 1; // Empezamos en la raíz
        while (idx_hoja < n) { // Mientras no estemos en el nivel de las hojas
            
            float hijo_izq = tree[idx_hoja * 2];
            
            // Si el ganador es igual al hijo izquierdo, bajamos por ahí.
            // Si hay duplicados, esta regla (ir a la izquierda primero)
            // asegura que los manejemos consistentemente.
            if (ganador == hijo_izq) {
                idx_hoja = idx_hoja * 2; // Bajar por la izquierda
            } else {
                // Si no fue el izquierdo, tuvo que ser el derecho.
                idx_hoja = idx_hoja * 2 + 1; // Bajar por la derecha
            }
        }
        
        // Ahora `idx_hoja` es el índice de la hoja ganadora.
        // La "descalificamos" poniéndola en INFINITO.
        tree[idx_hoja] = INFINITY;

        // 3. Recalculamos el torneo. No necesitamos rehacer todo,
        // solo el camino desde la hoja que cambiamos hasta la raíz.
        int i_rebuild = idx_hoja;
        while (i_rebuild > 1) {
            // Subimos al padre
            int padre = i_rebuild / 2;
            
            // Encontramos al "hermano"
            int hermano;
            if (i_rebuild % 2 == 0) { // Si soy hijo izquierdo
                hermano = i_rebuild + 1;
            } else { // Si soy hijo derecho
                hermano = i_rebuild - 1;
            }
            
            // El padre vuelve a ser el ganador (mínimo) entre nosotros
            tree[padre] = (tree[i_rebuild] < tree[hermano]) ? tree[i_rebuild] : tree[hermano];
            
            i_rebuild = padre; // Subimos al siguiente nivel para repetir
        }
    }

    // --- Fase 3: Finalización ---

    // En este punto, `sorted_arr` tiene todos los números ordenados.
    // Solo necesitamos copiarlos de vuelta al arreglo original.
    for (int i = 0; i < n; i++) {
        data[i] = sorted_arr[i];
    }
    
    // ¡No olvides limpiar! Liberamos la memoria que usamos.
    free(tree);
    free(sorted_arr);
}

void tournamentSort(Array *arr) {

    printf("Aplicando Tournament Sort...\n");
    
}

// ============================================
// MAIN FUNCTION
// ============================================

int main() {
    int choice, size;
    Array *arr = NULL;
    
    printf("===========================================\n");
    printf("  Algoritmos de Ordenamiento - Implementación Base\n");
    printf("===========================================\n\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Crear arreglo con números aleatorios\n");
        printf("2. Crear arreglo con números personalizados\n");
        printf("3. Desplegar arreglo\n");
        printf("4. Aplicar Bubble Sort\n");
        printf("5. Aplicar Selection Sort\n");
        printf("6. Aplicar Insertion Sort\n");
        printf("7. Aplicar Quick Sort\n");
        printf("8. Aplicar Merge Sort\n");
        printf("9. Aplicar Cocktail Sort\n");
        printf("10. Aplicar Heap Sort\n");
        printf("11. Aplicar Tree Sort\n");
        printf("12. Aplicar Tournament Sort\n");
        printf("13. Salir\n");
        printf("\nIngrese su opción: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (arr != NULL) {
                    freeArray(arr);
                }
                printf("Ingrese el tamaño del arreglo: ");
                scanf("%d", &size);
                arr = createRandomArray(size);
                if (arr != NULL) {
                    printf("Arreglo creado exitosamente!\n");
                    displayArray(arr);
                }
                break;
                
            case 2:
                if (arr != NULL) {
                    freeArray(arr);
                }
                printf("Ingrese el tamaño del arreglo: ");
                scanf("%d", &size);
                arr = createArray(size);
                if (arr != NULL) {
                    printf("Arreglo creado exitosamente!\n");
                    displayArray(arr);
                }
                break;
                
            case 3:
                displayArray(arr);
                break;
                
            case 4:
                bubbleSort(arr);
                displayArray(arr);
                break;
                
            case 5:
                selectionSort(arr);
                displayArray(arr);
                break;
                
            case 6:
                insertionSort(arr);
                displayArray(arr);
                break;
                
            case 7:
                quickSort(arr);
                displayArray(arr);
                break;
                
            case 8:
                mergeSort(arr);
                displayArray(arr);
                break;
                
            case 9:
                cocktailSort(arr);
                displayArray(arr);
                break;
                
            case 10:
                heapSort(arr);
                displayArray(arr);
                break;
                
            case 11:
                treeSort(arr);
                displayArray(arr);
                break;
                
            case 12:
                tournamentSort(arr);
                displayArray(arr);
                break;
                
            case 13:
                printf("\nFreeing memory and exiting...\n");
                freeArray(arr);
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
