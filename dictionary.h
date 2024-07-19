#pragma once
/* @author LE HOANG ANH DINH
KIT205 - Database Assignment*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Define constants for word length and hash table size
#define LENGTH 45
#define TABLE_SIZE 1000

// Define the structure for nodes in the linked list
typedef struct node {
    char word[LENGTH + 1];  // The word stored in this node
    struct node* next;      // Pointer to the next node in the linked list
} node;

// Declare global variables
extern node* table[TABLE_SIZE];  // The hash table
extern unsigned int dictionary_size;  // Counter for the number of words in the dictionary

// Function prototypes
unsigned int hash(const char* word);

#endif // DICTIONARY_H
