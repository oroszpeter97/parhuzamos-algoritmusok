/*
    Write a program that writes the contents of an array into a file.
    - Do it in a seperate function.
    - Make a seperate function for 'int', 'long' and 'float'.
    - Check the size of the files created.
    - Make a seperate function for the reading of these files.
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

// function takes a file path as its parameter and returns an int array with the file contents. The number of elements in the array is stored in the int_file_elements variable.
int* read_int_file_contents(const char* file_path, int* num_elements) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
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

// function takes a file path as its parameter and returns a long array with the file contents. The number of elements in the array is stored in the long_file_elements variable.
long* read_long_file_contents(const char* file_path, int* num_elements) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
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

// function takes a file path as its parameter and returns a float array with the file contents. The number of elements in the array is stored in the float_file_elements variable.
float* read_float_file_contents(const char* file_path, int* num_elements) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
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

// returns the files size or '-1' if it doesnt exist or not a regular file
int check_file_size(const char *file_path) {
    struct stat st;

    // Check if the file exists
    if (stat(file_path, &st) != 0) {
        printf("File does not exist.\n");
        return -1;
    }

    // Check if the file is a regular file
    if (!S_ISREG(st.st_mode)) {
        printf("File is not a regular file.\n");
        return -1;
    }

    // Get the file size
    int file_size = st.st_size;

    return file_size;
}

void write_int_array_to_file(int arr[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w"); // opening file in write mode

    if (fp == NULL) {
        printf("Error: Cannot open file!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d ", arr[i]); // writing each array element to file
    }
    fclose(fp); // closing the file

    printf("Int array contents written to file successfully!\n");
}

void write_long_array_to_file(long arr[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w"); // opening file in write mode

    if (fp == NULL) {
        printf("Error: Cannot open file!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%ld ", arr[i]); // writing each array element to file
    }
    fclose(fp); // closing the file

    printf("Long array contents written to file successfully!\n");
}

void write_float_array_to_file(float arr[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w"); // opening file in write mode

    if (fp == NULL) {
        printf("Error: Cannot open file!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%f ", arr[i]); // writing each array element to file
    }
    fclose(fp); // closing the file

    printf("Float array contents written to file successfully!\n");
}

int main() {
    const char* int_file_path = "8-feladat-int.txt";
    const char* long_file_path = "8-feladat-long.txt";
    const char* float_file_path = "8-feladat-float.txt";
    int int_file_elements;
    int long_file_elements;
    int float_file_elements;

    // int test
    int int_arr[] = {1, 2, 3, 4, 5};
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);
    write_int_array_to_file(int_arr, int_size, int_file_path);
    printf("Int file size is: %d byte(s)\n\n", check_file_size(int_file_path));
    
    // long test
    long long_arr[] = {1, 2, 3, 4, 5};
    int long_size = sizeof(long_arr) / sizeof(long_arr[0]);
    write_long_array_to_file(long_arr, long_size, long_file_path);
    printf("Long file size is: %d byte(s)\n\n", check_file_size(long_file_path));
    
    // float test
    float float_arr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int float_size = sizeof(float_arr) / sizeof(float_arr[0]);
    write_float_array_to_file(float_arr, float_size, float_file_path);
    printf("Float file size is: %d byte(s)\n", check_file_size(float_file_path));


    // read the written int file back
    printf("\n\nRe-read files to check if it's correct.\n");

    int* int_arr_read = read_int_file_contents(int_file_path, &int_file_elements);
    if (int_arr_read != NULL) {
        for (int i = 0; i < int_file_elements; i++) {
            printf("%d ", int_arr_read[i]);
        }
        printf("\n");
        free(int_arr_read);
    }

    // read the written long file back
    long* long_arr_read = read_long_file_contents(long_file_path, &long_file_elements);
    if (long_arr_read != NULL) {
        for (int i = 0; i < long_file_elements; i++) {
            printf("%ld ", long_arr_read[i]);
        }
        printf("\n");
        free(long_arr_read);
    }

    // read the written int file back
    float* float_arr_read = read_float_file_contents(float_file_path, &float_file_elements);
    if (float_arr_read != NULL) {
        for (int i = 0; i < float_file_elements; i++) {
            printf("%f ", float_arr_read[i]);
        }
        printf("\n");
        free(float_arr_read);
    }
    return 0;
}