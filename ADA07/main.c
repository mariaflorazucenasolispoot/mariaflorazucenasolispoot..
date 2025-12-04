#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n') s[n - 1] = '\0';
}

static void read_str(const char *msg, char *out, size_t max) {
    printf("%s", msg);
    fgets(out, (int)max, stdin);
    trim_newline(out);
}

int main() {
    Symbol *table[TABLE_SIZE];
    init_table(table);

    char option[8];

    while (1) {
        printf("\n--- Symbol Table (Hash Table + Linked Lists) ---\n");
        printf("1) Add symbol\n");
        printf("2) Search symbol\n");
        printf("3) Delete symbol\n");
        printf("4) Show table\n");
        printf("5) Exit\n");
        printf("Option: ");
        fgets(option, sizeof(option), stdin);

        int op = atoi(option);

        if (op == 1) {
            char id[64], type[32], scope[32], value[128];

            read_str("Identifier: ", id, sizeof(id));
            read_str("Type: ", type, sizeof(type));
            read_str("Scope: ", scope, sizeof(scope));
            read_str("Value: ", value, sizeof(value));

            int r = insert_symbol(table, id, type, scope, value);
            if (r >= 0) printf("Inserted at index %d.\n", r);
            else if (r == -2) printf("Identifier already exists.\n");
            else printf("Error inserting.\n");

        } else if (op == 2) {
            char id[64];
            read_str("Identifier to search: ", id, sizeof(id));

            int idx;
            Symbol *s = search_symbol(table, id, &idx);

            if (s) {
                printf("Found at index %d:\n", idx);
                printf("  %s : %s, %s, %s\n",
                    s->identifier, s->type, s->scope, s->value);
            } else {
                printf("Not found.\n");
            }

        } else if (op == 3) {
            char id[64];
            read_str("Identifier to delete: ", id, sizeof(id));

            if (delete_symbol(table, id))
                printf("Deleted.\n");
            else
                printf("Not found.\n");

        } else if (op == 4) {
            print_table(table);

        } else if (op == 5) {
            free_table(table);
            break;

        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}

