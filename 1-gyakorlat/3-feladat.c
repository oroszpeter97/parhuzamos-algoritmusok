/*
    Write an example for the 'sleep()' function.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Text before waiting.\n");

    // Sleep for 3 seconds
    sleep(3);

    printf("Waited 3 seconds.\n");

    return 0;
}
