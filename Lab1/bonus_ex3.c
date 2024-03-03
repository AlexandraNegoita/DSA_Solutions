#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Write a program which checks if two numbers are relatively prime.
// Use a function which receives the two numbers as parameters and test it in the main.

bool prime(int a, int b) {
    int aux;
    while (b != 0) {
        aux = a;
        a = b;
        b = aux % b;
    }
    if (a == 1) return true;
    else return false;
}

int main() {
    int a, b;

    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    if (prime(a, b)) {
        printf("%d and %d are relatively prime", a, b);
    } else {
        printf("%d and %d are not relatively prime", a, b);
    }
    return 0;
}

