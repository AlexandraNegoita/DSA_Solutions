#include <iostream>

using namespace std;

// Write a function template to sort an array of 5 elements.
// Write a different function template for swapping 2 values of the array.
// Read the values from keyboard.

template <typename T>
swapElements(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void sortArray(T (&arr)[5]) {
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        for(int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++) {
            if(arr[i] > arr[j]) {
                swapElements(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[5];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\n\t" << i + 1 << ": "; cin >> arr[i];
    }
    cout << "\nSorted array: ";

    sortArray(arr);
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
