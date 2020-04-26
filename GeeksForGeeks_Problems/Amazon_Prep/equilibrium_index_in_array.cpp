// https://www.geeksforgeeks.org/equilibrium-index-of-an-array/ 
//
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int equilibrium(int arr[], int size)
{
	if (0 == size)
		return -1;

	int res = -1, i, j;
	int sum = 0;
	int leftSum = 0;

	for(i = 0; i < size; i++)
		sum +=arr[i];

	for(i = 0; i < size; i++)
	{
		sum = sum - arr[i];

		if(DEBUG)
			cout << "sum: " << sum <<" leftSum: " << leftSum << " i: " << i << endl;

		if (sum == leftSum)
			return i;

		leftSum += arr[i];
	}
	return -1;
}

int equilibrium_arrays(int arr[], int size)
{
	if (0 == size)
		return -1;
	int left[size], right[size];
	int i, j;

	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));

	left[0] = arr[0];
	right[size-1] = arr[size-1];

	for(i = 1; i < size; i++)
	{
		left[i] = left[i-1] + arr[i];
		right[size - i - 1] = right[size - i] +  arr[size - i - 1];
	}

	if (DEBUG)
	{
		for(i = 0; i < size; i++)
			cout << "left[i]: " << left[i] << " right[i]: " << right[i] << endl;
	}

	for(i = 1; i < size -1; i++)
	{
		if (left[i] == right[i])
			return i;
	}

	return -1;
}

int main()
{
    int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "First equilibrium index is " << equilibrium(arr, arr_size) << endl;
    cout << equilibrium_arrays(arr, arr_size) << endl;
    return 0;
}
