#include <stdio.h>
#include <stdlib.h>

// Write a function "factorial" which receives a number (n) as a parameter and calculates its factorial.
// Test your function in the main.

int factorial (int n) {
    int prod = 1;
    for(int i = 1; i <= n; i++) {
        prod *= i;
    }
    return prod;
}

int main()
{
    int n;
    printf("Insert a number n: ");
    scanf("%d", &n);
    printf("The factorial n! is: %d", factorial(n));
    return 0;
}
