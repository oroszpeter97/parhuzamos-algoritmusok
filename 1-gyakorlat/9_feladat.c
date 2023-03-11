#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper-libraries/file_handler.h"


/**
 * Parameters:
 * - n : Number of random numbers to be generated.
 * 
 * Returns:
 * - Pointer to the start of the array : Generated succesfully.
 * - NULL : Error in memory allocation.
*/
int* generate_random_numbers_array(int n) {
    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
}

/**
 * Write a program that takes a 'file_name' and a number 'n' as an argument.
 * - Make a function that generates 'n' random numbers to the 'file_name'.
 * - Calculate the amount of time it takes to generate the random numbers.
 * - Calculate the time it takes for the file to be written.
 * - Collect the data and make a graph from it. (Can be found with the name '9-feladat.xlsx').
 * 
 * How to compile :
 * 
 * gcc .\9_feladat.c .\helper-libraries\file_handler.c -o 9_feladat.exe
*/
int main(int argc, char* argv[]) {
    int n, write_int_return;
    int* int_arr;
    clock_t start_time, end_time;
    double time_elapsed;

    if (argc != 3) {
        printf("Usage: ./program_name file_path n\n");
        return 1;
    }

    const char* file_path = argv[1];
    n = atoi(argv[2]);
    
    start_time = clock();
    int_arr = generate_random_numbers_array(n);
    end_time = clock();
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    if(int_arr != NULL){
        printf("The amount of time it took to generate %d random numbers in seconds is: %.6f\n", n, time_elapsed);
    }else{
        printf("Error with memory allocation!");
    }

    start_time = clock();
    write_int_return = write_int_array_to_file(int_arr, n, file_path);
    end_time = clock();
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    switch (write_int_return)
    {
    case -1:
        printf("The file couldn't be created!");
        break;
    default:
        printf("The amount of time it took to write %d random numbers into a file in seconds is: %.6f\n", n, time_elapsed);
        break;
    }
    free(int_arr);
    return 0;
}
