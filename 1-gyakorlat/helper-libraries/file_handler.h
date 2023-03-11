#ifndef FILE_HANDLER_H_ 
#define FILE_HANDLER_H_

int check_file_size(const char *file_path);
int* read_int_file_contents(const char* file_path, int* num_elements);
long* read_long_file_contents(const char* file_path, int* num_elements);
float* read_float_file_contents(const char* file_path, int* num_elements);
int write_int_array_to_file(int arr[], int size, const char* filename);
int write_long_array_to_file(long arr[], int size, const char* filename);
int write_float_array_to_file(float arr[], int size, const char* filename);

#endif //FILE_HANDLER_H_