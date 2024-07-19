/* @author LE HOANG ANH DINH
KIT205 - Database Assignment*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Initialize the hash table and dictionary size counter
node* table[TABLE_SIZE] = { NULL };
unsigned int dictionary_size = 0;

// Hash function to map a word to an index in the hash table
unsigned int hash(const char* word) {
    unsigned int hash = 0;
    // Iterate over each character in the word
    while (*word) {
        hash = (hash << 2) ^ *word++;
    }

    return hash % TABLE_SIZE;
}

// Load function to read words from a file and store them in the hash table
bool load(const char* dictionary) {
    // Open the dictionary file for reading
    FILE* file = fopen(dictionary, "r");
    if (!file) {
        perror("Error opening dictionary file");
        return false;
    }

    char word[LENGTH + 1];
    // Read each word from the file
    while (fscanf_s(file, "%45s", word, (unsigned)_countof(word)) != EOF) {
        node* new_node = malloc(sizeof(node));
        if (!new_node) {
            fclose(file);
            perror("Error allocating memory for new node");
            return false;
        }
        strcpy_s(new_node->word, sizeof(new_node->word), word);
        unsigned int index = hash(word);
        // Insert the node at the beginning of the linked list for the hash index
        new_node->next = table[index];
        table[index] = new_node;
        dictionary_size++;
    }

    fclose(file);
    return true;
}

// Check function to verify if a word is in the hash table
bool check(const char* word) {
    unsigned int index = hash(word);
    // Traverse the linked list at the hash index
    node* cursor = table[index];
    while (cursor != NULL) {
        // Compare the word with the current node's word
        if (strcmp(cursor->word, word) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}