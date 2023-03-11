#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Write a program that generates two random positive integer then ask for the user to add these together! Check how long it takes for the user to succeed!
 * 
 * How to compile:
 * 
 * gcc .\6_feladat.c -o 6_feladat.exe
*/
int main() {
    int num1, num2, correct_ans, user_ans;
    double time_elapsed;
    clock_t start_time, end_time;

    // Set the random seed using current time
    srand(time(0));

    // Generate two random numbers between 1 and 100
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    // Calculate the correct answer
    correct_ans = num1 + num2;

    // Start the timer
    start_time = clock();

    // Ask the user to add the two numbers repeatedly until they get the correct answer
    user_ans;
    do {
        printf("What is %d + %d? ", num1, num2);
        scanf("%d", &user_ans);
        if (user_ans != correct_ans) {
            printf("Incorrect. Please try again.\n");
        }
    } while (user_ans != correct_ans);

    // Stop the timer
    end_time = clock();
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Correct! You took %.2f seconds.\n", time_elapsed);

    return 0;
}
