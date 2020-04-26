// https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/
//
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int binarySearch(int arr[], int start, int end)
{
	int mid = (start+end)/2;

	if (end >= start)
	{
		if (arr[mid] == mid) //found fix point
			return mid;
		else if (arr[mid] > mid) // move left (val is more than index, hence right side everything is big)
			return binarySearch(arr, start, mid - 1);
		else
			return binarySearch(arr, mid + 1, end);
	}
	return -1;
}

int main()
{
    int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Fixed Point is "<< binarySearch(arr, 0, n-1) << endl;

    int arr1[] = {0, 2, 5, 8, 17};
    cout<<"Fixed Point is "<< binarySearch(arr1, 0, sizeof(arr1)/sizeof(arr1[0])-1) << endl;

	int arr2[] = {-10, -5, 3, 4, 7, 9};
    cout<<"Fixed Point is "<< binarySearch(arr2, 0, sizeof(arr2)/sizeof(arr2[0])-1) << endl;

    return 0;
}
