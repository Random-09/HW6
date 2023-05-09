#ifndef TASK1_HASH_TABLE_H
#define TASK1_HASH_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char *key;
    int count;
    struct Node *next;
} Node_t;

typedef struct HashTable {
    int size;
    Node_t **table;
} HashTable_t;

int hash(char *key, int size);

Node_t *create_node(char *key, int value);

HashTable_t *create_hash_table(int size);

void destroy_node(Node_t *node);

void destroy_hash_table(HashTable_t *hash_table);

void increment_substring_count(HashTable_t *hash_table, char *key);

void slice(const char *string, char *result, int start, int end);

void count_substrings(HashTable_t *hash_table, char *string, int sub_len, int max_substrings);

void print_substrings(HashTable_t *hash_table, int output_rep);

#endif