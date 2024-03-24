#include <iostream>

using namespace std;

// Implement a function to sort an array of 5 elements of type double.
// Use a swap mechanism, which has to be implemented in another function.


void swap_elements(double &x, double &y) {
    double temp;
    temp = x;
    x = y;
    y = temp;
}

void sort_array(double a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[i]) {
                swap_elements(a[i], a[j]);
            }
        }
    }
}

int main()
{
    int n = 6;
    double a[n] = {1, 3, 2, 6, 4, 0};
    sort_array(a, n);
    cout << "Sorted array: " << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
