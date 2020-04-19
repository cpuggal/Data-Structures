//https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/


// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

void printPrevSmaller(int arr[], int size)
{
	if (size == 0)
		return;

	stack<int> mystack;
	int i = 0, top = 0;
	string def_string = "_";

	mystack.push(arr[0]);
	cout << def_string << ", ";

	for (i = 1; i < size; i++)
	{
		while ((!mystack.empty()) && (mystack.top() > arr[i]))
		{
			mystack.pop();
		}

		if (!mystack.empty())
			cout << mystack.top() << ", ";
		else
			cout << def_string << ", ";
		mystack.push(arr[i]);
	}
	cout << endl;
}

/* Driver program to test above functions*/
int main()
{
	int arr[] = {1, 3, 0, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int arr1[] = {1, 6, 4, 10, 2, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    printPrevSmaller(arr1, n1);
    printPrevSmaller(arr, n);
    return 0;
}

