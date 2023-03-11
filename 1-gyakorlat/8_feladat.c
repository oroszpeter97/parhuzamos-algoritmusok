#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "helper-libraries/file_handler.h"

/**
 * Write a program that writes the contents of an \a array into a file.
 * - Do it in a seperate function.
 * - Make a seperate function for \a int , \a long and \a float.
 * - Check the size of the files created.
 * - Make a seperate function for the reading of these files.
 * 
 * How to compile :
 * 
 * gcc .\8_feladat.c .\helper-libraries\file_handler.c -o 8_feladat.exe
*/
int main() {
    const char* int_file_path = "outputs\\8-feladat-int.txt";
    const char* long_file_path = "outputs\\8-feladat-long.txt";
    const char* float_file_path = "outputs\\8-feladat-float.txt";
    int int_file_elements, long_file_elements, float_file_elements, write_int_return, write_long_return, write_float_return, file_size;
    int int_arr[] = {1, 2, 3, 4, 5};
    long long_arr[] = {1, 2, 3, 4, 5};
    float float_arr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int int_size, long_size, float_size;

    // int test
    int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    write_int_return = write_int_array_to_file(int_arr, int_size, int_file_path);
    switch (write_int_return)
    {
    case -1:
        printf("Error: Cannot open file!\n");
        break;
    default:
        printf("Int array contents written to file successfully!\n");
        break;
    }

    file_size = check_file_size(int_file_path);
    switch (file_size)
    {
    case -1:
        printf("File does not exist.\n");
        break;
    case -2:
        printf("File is not a regular file.\n");
        break;
    default:
        printf("Int file size is: %d byte(s)\n\n", file_size);
        break;
    }
    
    
    // long test
    long_size = sizeof(long_arr) / sizeof(long_arr[0]);

    write_long_return = write_long_array_to_file(long_arr, long_size, long_file_path);
    switch (write_long_return)
    {
    case -1:
        printf("Error: Cannot open file!\n");
        break;
    default:
        printf("Long array contents written to file successfully!\n");
        break;
    }

    file_size = check_file_size(long_file_path);
    switch (file_size)
    {
    case -1:
        printf("File does not exist.\n");
        break;
    case -2:
        printf("File is not a regular file.\n");
        break;
    default:
        printf("Long file size is: %d byte(s)\n\n", file_size);
        break;
    }
    
    // float test
    float_size = sizeof(float_arr) / sizeof(float_arr[0]);
    
    write_float_return = write_float_array_to_file(float_arr, float_size, float_file_path);
    switch (write_float_return)
    {
    case -1:
        printf("Error: Cannot open file!\n");
        break;
    default:
        printf("Float array contents written to file successfully!\n");
        break;
    }

    file_size = check_file_size(float_file_path);
    switch (file_size)
    {
    case -1:
        printf("File does not exist.\n");
        break;
    case -2:
        printf("File is not a regular file.\n");
        break;
    default:
        printf("Float file size is: %d byte(s)\n", file_size);
        break;
    }

    // read the written int file back
    printf("\nRe-read files to check if it's correct.\n");

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