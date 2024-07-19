/* @author LE HOANG ANH DINH
KIT205 - Database Assignment*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "dictionary.h"

// Function to check if a file exists
bool file_exists(const char* path) {
    FILE* file = fopen(path, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

// Function to run all tests
void run_tests() {
    test_load();
}

// Test function for loading the dictionary
void test_load() {
    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();
    bool result = load("words.txt"); // Attempt to load dictionary
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (result) {
        printf("test_load passed\n");
    }
    else {
        printf("test_load failed\n");
    }
    printf("Time taken for test_load: %f seconds\n", time_taken);
    unload(); // Unload dictionary
}

int main() {
    const char* dictionary_path = "words.txt";
    const char* text_path = "test.txt";

    printf("Dictionary file path: %s\n", dictionary_path);
    printf("Text file path: %s\n", text_path);

    if (!file_exists(dictionary_path)) {
        printf("Dictionary file not found: %s\n", dictionary_path);
        return 1;
    }

    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();
    bool success = load(dictionary_path);
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to load dictionary: %f seconds\n", time_taken);

    if (!success) {
        printf("Failed to load dictionary.\n");
        return 1;
    }

    if (!file_exists(text_path)) {
        printf("Text file not found: %s\n", text_path);
        return 1;
    }

    start_time = clock();
    FILE* file = fopen(text_path, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    char word[LENGTH + 1];
    while (fscanf_s(file, "%45s", word, (unsigned)_countof(word)) != EOF) {
        if (check(word)) {
            printf("%s is correct.\n", word);
        }
        else {
            printf("%s is misspelled.\n", word);
        }
    }
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to check words: %f seconds\n", time_taken);

    fclose(file);

    start_time = clock();
    unload();
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to unload dictionary: %f seconds\n", time_taken);

    run_tests();
    return 0;
}
