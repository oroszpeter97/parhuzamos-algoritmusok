#include <stdio.h>
#include <time.h>

/**
 * Check if given int parameter is a prime.
 * 
 * Returns:
 * - 0 : Not a prime.
 * - 1 : Is a prime.
*/
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

/**
 * Counts how many prime numbers are in a range of [1, \a n].
*/
void count_primes(int n) {
    int number_of_primes = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            number_of_primes += 1;
        }
    }
    printf("Number of primes: %d\n", number_of_primes);
}

/**
 * Define a function that takes an \a n positive integer as its argument which calculates how many primes is in the [1, \a n ] interval.
 * 
 * Time how long it takes for it to calculate for 'n=1.000', 'n=2.000', 'n=3.000', ..., 'n=20.000'.
 * 
 * Make a graph from the results. (Can be found with the name 'measurements/7-feladat.xlsx')
 * 
 * How to compile:
 * 
 * gcc .\7_feladat.c -o 7_feladat.exe
*/
int main() {
    double time_elapsed;
    clock_t start_time, end_time;

    for (int n = 1000; n <= 20000; n += 1000) {
        start_time = clock();
        count_primes(n);
        end_time = clock();
        time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time elapsed for n=%d: %.8f seconds\n\n", n, time_elapsed);
    }

    return 0;
}
