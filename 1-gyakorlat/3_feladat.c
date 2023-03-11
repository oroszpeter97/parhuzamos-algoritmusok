#include <stdio.h>
#include <unistd.h>

/**
 * Write an example for the \a sleep() function.
 * 
 * How to compile:
 * 
 * gcc .\3_feladat.c -o 3_feladat.exe
 */
int main() {
    printf("Text before waiting.\n");

    // Sleep for 3 seconds
    sleep(3);

    printf("Waited 3 seconds.\n");

    return 0;
}
