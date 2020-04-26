// https://www.geeksforgeeks.org/find-minimum-difference-pair/
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int findMinDiff(int arr[], int size)
{
	if(0 == size)
		return -1;

	sort(arr, arr+size);
	int diff = INT_MAX;
	for(int i = 1; i < size; i++)
	{
		if (arr[i] - arr[i-1] < diff)
			diff = arr[i] - arr[i-1];
	}
	return diff;
}

int main()
{
   int arr[] = {1, 5, 3, 19, 18, 25};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "Minimum difference is " << findMinDiff(arr, n) << endl;
   return 0;
}


