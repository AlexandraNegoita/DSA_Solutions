#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Write a function primeNumbers which receives a number (n) as a parameter and displays the first n prime numbers.
// Test your function in the main.


bool is_prime(int x) {
    if (x > 2 && x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i+=2) {
        if (x % i == 0) return false;
    }
    return true;
}

void primeNumbers(int n) {
    int i = 0;
    int x = 2;
    while (i < n) {
        if (is_prime(x)) {
            printf("%d ", x);
            i++;
        }
        x++;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are: ", n);
    primeNumbers(n);

    return 0;
}
