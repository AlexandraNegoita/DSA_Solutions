#include <iostream>
#include "MyStack.h"
using namespace std;

// Write a program which reads a number n and n numbers of type double.
// The numbers are displayed in reversed order using the stack.


int main()
{
    Stack<double> s;
    int n, p;
    cout << "\nEnter the number of elements: ";
    cin >> n;
    cout << "\nEnter the elements: ";
    for(int i = 0; i < n; i++) {
        cout << "\n\t" << i << ": ";
        cin >> p;
        s.push(p);
    }
    cout << "Elements in reverse order: ";
    for(int i = 0; i < n; i++) {
        cout << s.pop() << " ";
    }
}




