/*
    Define a function that takes an 'n' positive integer as its argument which calculates how many primes is in the [1, n] interval.
    Time how long it takes for it to calculate for 'n=1.000', 'n=2.000', 'n=3.000', ..., 'n=20.000'.
    Make a graph from the results. (Can be found with the name '7-feladat.xlsx')
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes(int n) {
    int number_of_primes = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            number_of_primes += 1;
        }
    }
    printf("Number of primes: %d\n", number_of_primes);
}

int main() {
    for (int n = 1000; n <= 20000; n += 1000) {
        clock_t start_time = clock();
        find_primes(n);
        clock_t end_time = clock();
        double time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time elapsed for n=%d: %.8f seconds\n\n", n, time_elapsed);
    }

    return 0;
}
