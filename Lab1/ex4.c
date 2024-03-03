#include <stdio.h>
#include <stdlib.h>

// Write a program which reads an int number and checks if it's a palindrome or not
// A palindrome number is symmetrical, ex: 131, 22122
// Use functions!

int is_palindrome(int x) {
    int original = x;
    int reversed = 0;
    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    int x;

    printf("Insert x: ");
    scanf("%d", &x);

    if (is_palindrome(x)) {
        printf("x = %d is a palindrome", x);
    } else {
        printf("x = %d is not a palindrome", x);
    }

    return 0;
}
