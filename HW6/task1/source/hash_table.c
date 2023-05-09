#include "../include/hash_table.h"

int hash(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % size;
}

Node_t *create_node(char *key, int value) {
    Node_t *new_node = (Node_t *) malloc(sizeof(Node_t));
    new_node->key = (char *) malloc(strlen(key) + 1);
    strcpy(new_node->key, key);
    new_node->count = value;
    new_node->next = NULL;
    return new_node;
}

HashTable_t *create_hash_table(int size) {
    HashTable_t *hash_table = (HashTable_t *) malloc(sizeof(HashTable_t));
    hash_table->size = size;
    hash_table->table = (Node_t **) malloc(sizeof(Node_t *) * hash_table->size);
    for (int i = 0; i < hash_table->size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

void destroy_node(Node_t *node) {
    free(node->key);
    free(node);
}

void destroy_hash_table(HashTable_t *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        Node_t *node = hash_table->table[i];
        while (node != NULL) {
            Node_t *temp = node;
            node = node->next;
            destroy_node(temp);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

void increment_substring_count(HashTable_t *hash_table, char *key) {
    int index = hash(key, hash_table->size);
    Node_t *node = hash_table->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }
    Node_t *new_node = create_node(key, 1);
    new_node->next = hash_table->table[index];
    hash_table->table[index] = new_node;
}

void slice(const char *string, char *result, int start, int end) {
    int j = 0;
    for (size_t i = start; i < end; ++i) {
        result[j++] = string[i];
    }
}

void count_substrings(HashTable_t *hash_table, char *string, int sub_len, int max_substrings) {
    for (int i = 0; i < max_substrings; i++) {
        char substring[sub_len];
        slice(string, substring, i, i + sub_len);
        increment_substring_count(hash_table, substring);
    }
}

void print_substrings(HashTable_t *hash_table, int output_rep) {
    for (int i = 0; i < hash_table->size; i++) {
        Node_t *node = hash_table->table[i];
        while (node != NULL) {
            if (node->count >= output_rep)
                printf("Substring - %s, Repeat count - %d\n", node->key, node->count);
            node = node->next;
        }
    }
}