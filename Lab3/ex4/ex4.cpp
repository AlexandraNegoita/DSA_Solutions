#include <iostream>

using namespace std;

#include "LargeStack.h"

int main()
{
    LargeStack<int> ls_before, ls_after;
	ls_before.push(1); 	ls_after.push(1);
	ls_before.push(2);	ls_after.push(2);
	ls_before.push(3);	ls_after.push(3);
	ls_before.push(4);	ls_after.push(4);
	while (!ls_before.isEmpty())
		cout << ls_before.pop() << " ";

	cout << "\nAfter swap: " << endl;
	ls_after.swap(1, 2);
	while (!ls_after.isEmpty())
		cout << ls_after.pop() << " ";
    return 0;
}
