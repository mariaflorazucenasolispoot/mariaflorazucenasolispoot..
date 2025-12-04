#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

void init_table(Symbol *table[]) {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

/* Hash djb2 para strings */
unsigned int hash_key(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + (unsigned char)c;
    return hash % TABLE_SIZE;
}

/* Insercion con encadenamiento */
int insert_symbol(Symbol *table[], const char *id, const char *type, const char *scope, const char *value) {
    if (!id || id[0] == '\0')
        return -1;

    unsigned int idx = hash_key(id);

    Symbol *node = table[idx];
    while (node) {
        if (strcmp(node->identifier, id) == 0)
            return -2; /* ya existe */
        node = node->next;
    }

    Symbol *newnode = malloc(sizeof(Symbol));
    if (!newnode)
        return -3;

    strncpy(newnode->identifier, id, sizeof(newnode->identifier) - 1);
    newnode->identifier[sizeof(newnode->identifier) - 1] = '\0';

    strncpy(newnode->type, type ? type : "", sizeof(newnode->type) - 1);
    newnode->type[sizeof(newnode->type) - 1] = '\0';

    strncpy(newnode->scope, scope ? scope : "", sizeof(newnode->scope) - 1);
    newnode->scope[sizeof(newnode->scope) - 1] = '\0';

    strncpy(newnode->value, value ? value : "", sizeof(newnode->value) - 1);
    newnode->value[sizeof(newnode->value) - 1] = '\0';

    newnode->next = table[idx];
    table[idx] = newnode;

    return (int)idx;
}

/* Busqueda */
Symbol *search_symbol(Symbol *table[], const char *id, int *index_out) {
    unsigned int idx = hash_key(id);
    Symbol *node = table[idx];

    while (node) {
        if (strcmp(node->identifier, id) == 0) {
            if (index_out)
                *index_out = idx;
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/* Eliminacion */
int delete_symbol(Symbol *table[], const char *id) {
    unsigned int idx = hash_key(id);
    Symbol *node = table[idx];
    Symbol *prev = NULL;

    while (node) {
        if (strcmp(node->identifier, id) == 0) {
            if (prev) prev->next = node->next;
            else table[idx] = node->next;
            free(node);
            return 1;
        }
        prev = node;
        node = node->next;
    }
    return 0;
}

/* Impresion de tabla hash */
void print_table(Symbol *table[]) {
    printf("Index | Symbols (identifier : type, scope, value)\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%3d: ", i);
        Symbol *node = table[i];
        if (!node) {
            printf("(empty)\n");
            continue;
        }
        while (node) {
            printf("[%s : %s, %s, %s] -> ",
                node->identifier,
                node->type,
                node->scope,
                node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

/* Liberar memoria */
void free_table(Symbol *table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *node = table[i];
        while (node) {
            Symbol *next = node->next;
            free(node);
            node = next;
        }
        table[i] = NULL;
    }
}
