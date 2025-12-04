#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define TABLE_SIZE 100  

typedef struct Symbol {
    char identifier[64]; /* string del identificador */
    char type[32];       /* tipo del simbolo: int, float, etc. */
    char scope[32];      /* ambito: global, local, etc. */
    char value[128];     /* valor o representacion */
    struct Symbol *next; /* lista ligada para colisiones */
} Symbol;

void init_table(Symbol *table[]);
unsigned int hash_key(const char *key);

int insert_symbol(Symbol *table[], const char *id, const char *type, const char *scope, const char *value);

Symbol *search_symbol(Symbol *table[], const char *id, int *index_out);

int delete_symbol(Symbol *table[], const char *id);

void print_table(Symbol *table[]);
void free_table(Symbol *table[]);

#endif
