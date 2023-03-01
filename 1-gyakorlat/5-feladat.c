/*
    Write a program that for its input paramter gets two numbers for an interval (lower and upper bound) then generates a random number in this interval!
    Check for the correct arguments and throw an error if incorrect!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Check for correct number of command line arguments
    if (argc != 3) {
        printf("Usage: %s lower_bound upper_bound\n", argv[0]);
        return 1;
    }

    // Convert command line arguments to integers
    int lower_bound = atoi(argv[1]);
    int upper_bound = atoi(argv[2]);

    // Check if input bounds are valid
    if (lower_bound >= upper_bound) {
        printf("Error: Invalid bounds, upper bound must be greater than lower bound.\n");
        return 1;
    }

    // Set the random seed using current time
    srand(time(0));

    // Generate random number between the lower and upper bounds
    int random_num = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    printf("Random number between %d and %d: %d\n", lower_bound, upper_bound, random_num);

    return 0;
}
