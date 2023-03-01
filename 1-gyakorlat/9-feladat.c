/*
    Write a program that takes a 'file_name' and a number 'n' as an argument.
    - Make a function that generates 'n' random numbers to the 'file_name'.
    - Calculate the amount of time it takes to generate the random numbers.
    - Calculate the time it takes for the file to be written.
    - Collect the data and make a graph from it. (Can be found with the name '9-feladat.xlsx').  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_random_numbers_array(int n) {
    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
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

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./program_name file_path n\n");
        return 1;
    }

    const char* file_path = argv[1];
    int n = atoi(argv[2]);
    
    clock_t start_time = clock();
    int* int_arr = generate_random_numbers_array(n);
    clock_t end_time = clock();
    double time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("The amount of time it took to generate %d random numbers in seconds is: %.6f\n", n, time_elapsed);

    start_time = clock();
    write_int_array_to_file(int_arr, n, file_path);
    end_time = clock();
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("The amount of time it took to write %d random numbers into a file in seconds is: %.6f\n", n, time_elapsed);

    free(int_arr);
    return 0;
}
