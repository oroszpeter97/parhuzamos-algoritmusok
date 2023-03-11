#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_handler.h"

/**
 * Parameters:
 * - file_path : A pointer to a char array where the file is located.
 * 
 * Returns:
 * - The size of the file in bytes as an integer : The file exists and a regular file.
 * - -1 : The file doesn't exist.
 * - -2 : The file exists but it's not a regular file.
 */
int check_file_size(const char *file_path) {
    struct stat st;

    // Check if the file exists
    if (stat(file_path, &st) != 0) {
        return -1;
    }

    // Check if the file is a regular file
    if (!S_ISREG(st.st_mode)) {
        return -2;
    }

    // Get the file size
    int file_size = st.st_size;

    return file_size;
}

/** 
 * Parameters:
 * - file_path : A pointer to a char array where the file is located.
 * - num_elements : A pointer to and integer where the length of the returned array is stored.   
 * 
 * Returns: 
 * - A pointer to the start of the array : File exists.
 * - NULL : File doesn't exist.
 * 
 * Details:
 * Reads a file that contains integers seperated by a space.
 */
int* read_int_file_contents(const char* file_path, int* num_elements) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        return NULL;
    }

    int max_size = 1024;
    int* arr = (int*) malloc(max_size * sizeof(int));
    int index = 0;
    int value;

    while (fscanf(file, "%d", &value) == 1) {
        arr[index++] = value;
        if (index >= max_size) {
            max_size *= 2;
            arr = (int*) realloc(arr, max_size * sizeof(int));
        }
    }

    fclose(file);
    *num_elements = index;
    return arr;
}

/** 
 * Parameters:
 * - file_path : A pointer to a char array where the file is located.
 * - num_elements : A pointer to and integer where the length of the returned array is stored.   
 * 
 * Returns: 
 * - A pointer to the start of the array.
 * - If file doesn't exist : NULL
 * 
 * Details:
 * Reads a file that contains longs seperated by a space.
 */
long* read_long_file_contents(const char* file_path, int* num_elements) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        return NULL;
    }

    int max_size = 1024;
    long* arr = (long*) malloc(max_size * sizeof(long));
    int index = 0;
    long value;

    while (fscanf(file, "%ld", &value) == 1) {
        arr[index++] = value;
        if (index >= max_size) {
            max_size *= 2;
            arr = (long*) realloc(arr, max_size * sizeof(long));
        }
    }

    fclose(file);
    *num_elements = index;
    return arr;
}

/** 
 * Parameters:
 * - file_path : A pointer to a char array where the file is located.
 * - num_elements : A pointer to and integer where the length of the returned array is stored.   
 * 
 * Returns: 
 * - A pointer to the start of the array.
 * - If file doesn't exist : NULL
 * 
 * Details:
 * Reads a file that contains floats seperated by a space.
 */
float* read_float_file_contents(const char* file_path, int* num_elements) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        return NULL;
    }

    int max_size = 1024;
    float* arr = (float*) malloc(max_size * sizeof(float));
    int index = 0;
    float value;

    while (fscanf(file, "%f", &value) == 1) {
        arr[index++] = value;
        if (index >= max_size) {
            max_size *= 2;
            arr = (float*) realloc(arr, max_size * sizeof(float));
        }
    }

    fclose(file);
    *num_elements = index;
    return arr;
}

/**
 * Parameters:
 * - arr : The int array to be written.
 * - size : The length of the array.
 * - filename : The path of the file to be created.
 * 
 * Returns:
 * - 0 : The file was created and written succesfully.
 * - -1 : The file couldn't be created.
 * 
 * Details:
 * Writes an int array to a file.
*/
int write_int_array_to_file(int arr[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w"); // opening file in write mode

    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d ", arr[i]); // writing each array element to file
    }
    fclose(fp); // closing the file

    return 0;
}

/**
 * Parameters:
 * - arr : The long array to be written.
 * - size : The length of the array.
 * - filename : The path of the file to be created.
 * 
 * Returns:
 * - 0 : The file was created and written succesfully.
 * - -1 : The file couldn't be created.
 * 
 * Details:
 * Writes a long array to a file.
*/
int write_long_array_to_file(long arr[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w"); // opening file in write mode

    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%ld ", arr[i]); // writing each array element to file
    }
    fclose(fp); // closing the file

    return 0;
}

/**
 * Parameters:
 * - arr : The float array to be written.
 * - size : The length of the array.
 * - filename : The path of the file to be created.
 * 
 * Returns:
 * - 0 : The file was created and written succesfully.
 * - -1 : The file couldn't be created.
 * 
 * Details:
 * Writes a float array to a file.
*/
int write_float_array_to_file(float arr[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w"); // opening file in write mode

    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%f ", arr[i]); // writing each array element to file
    }
    fclose(fp); // closing the file

    return 0;
}
