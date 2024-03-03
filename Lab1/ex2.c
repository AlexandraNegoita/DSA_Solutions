#include <stdio.h>
#include <stdlib.h>

// Display the minimum of three float numbers, read with scanf.
// Use functions!

float min_number(float x, float y, float z) {
    if (x < y) {
        if (x < z) return x;
    } else {
        if (y < z) return y;
    }
    return z;
}

int main()
{
    float x, y, z;
    printf("Insert x, y, z: ");
    scanf("%f %f %f", &x, &y, &z);
    printf("The minimum is: %.2f", min_number(x, y, z));
    return 0;
}
