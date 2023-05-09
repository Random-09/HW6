#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/hash_table.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        puts("Wrong number of arguments");
        exit(EXIT_FAILURE);
    }
    char *string = argv[1];
    int sub_len = strtol(argv[2], NULL, 10);
    if ((int) strlen(string) < sub_len) {
        puts("Substring is bigger than string");
        exit(EXIT_FAILURE);
    }
    int output_rep = strtol(argv[3], NULL, 10);
    int max_substrings = (int) strlen(string) - sub_len + 1;
    HashTable_t *hash_table = create_hash_table(max_substrings);
    count_substrings(hash_table, string, sub_len, max_substrings);
    print_substrings(hash_table, output_rep);
    destroy_hash_table(hash_table);
    return 0;
}

