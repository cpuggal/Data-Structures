// https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/

// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

bool isProduct(int arr[], int size, int n)
{
	if (size == 0)
		return false;

	set <int> myset;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			if (myset.find(n/arr[i]) == myset.end())
				myset.insert(arr[i]);
			else
				return true;
		}
	}
	return false;
}

/* Driver program to test above functions*/
int main()
{
	int arr[] = {10, 20, 9, 40};
    int x = 400;

    int n = sizeof(arr)/sizeof(arr[0]);
    isProduct(arr, n, x)? cout << "Yes\n"
                       : cout << "No";

    x = 190;
    isProduct(arr, n, x)? cout << "Yes\n"
                        : cout << "No";

    return 0;
}

