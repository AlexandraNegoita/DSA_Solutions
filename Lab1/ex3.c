#include <stdio.h>
#include <stdlib.h>

// Write a program which sums the digits of all numbers situated in a given interval.
// The endpoints of the interval are read from keyboard.
// Use functions!

int sum_interval(int start, int end) {
    if (start > end) {
        return 0;
    } else {
        return sum_digits(start) + sum_interval(start + 1, end);
    }
}

int sum_digits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int start, end;

    printf("Insert the start and end points of the interval: ");
    scanf("%d %d", &start, &end);

    printf("Sum of digits for numbers in the interval [%d, %d] is: %d\n", start, end, sum_interval(start, end));

    return 0;
}
