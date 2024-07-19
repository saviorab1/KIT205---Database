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
