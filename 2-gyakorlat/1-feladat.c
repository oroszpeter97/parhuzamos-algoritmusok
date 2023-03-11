#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    return 0;
}

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