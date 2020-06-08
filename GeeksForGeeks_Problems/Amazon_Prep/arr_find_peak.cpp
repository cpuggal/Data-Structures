// https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0

using namespace std;

int find_peak_utils(int arr[], int low, int high, int size)
{
	int mid = (low + high)/2;
	
	if (mid == 0)
		return 0;
	
	if ((mid > 0) && (arr[mid-1] < arr[mid]) && (mid < size - 1) && (arr[mid] > arr[mid +1]))
		return mid;
	
	if (arr[mid] < arr[mid - 1]) //move left
		return find_peak_utils(arr, low, mid - 1, size);
	else						//move right
		return find_peak_utils(arr, mid + 1, high, size);
}

int findPeak(int arr[], int size)
{
	if(size == 0)
		return -1;

	if((0 < size -1) && (1 < size -1) && (arr[0] > arr[1])) // first element{100, 50, .. }
		return 0;

	if((size >= 2) && (arr[size - 1] > arr[size - 2])) // last element {..25, 26}
		return size - 1;
		
	return find_peak_utils(arr, 0, size - 1, size);
}

int main() {
	int arr[] = { 1, 13, 6, 5, 4, 1, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Index of a peak point is " << findPeak(arr, n) << endl; 
    return 0; 
	return 0;
}
