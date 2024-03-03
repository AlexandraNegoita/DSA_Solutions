#include <stdio.h>
#include <stdlib.h>

// Write a program to calculate the average between two float numbers.
// The result shall be displayed with 2 decimals.
// Use scanf and printf!
// %.2f -> format parameter for float with 2 decimals

int main()
{
    float x;
    float y;

    printf("Insert x: ");
    scanf("%f", &x);

    printf("Insert y: ");
    scanf("%f", &y);

    printf("The average between x = %.2f and y = %.2f is: %.2f", x, y, (x + y) / 2);
    return 0;
}
