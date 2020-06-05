//https://www.geeksforgeeks.org/element-1st-array-count-elements-less-equal-2nd-array/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	
using namespace std;

int binary_search(int arr[], int low, int high, int val)
{
	int mid;
	
	while(low <= high)
	{
		mid = (low + high)/2;
		
		if(arr[mid] <= val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high;
}

void countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
	int i, index;
	sort(arr2, arr2 + n);
	
	for(i = 0; i < m; i ++)
	{
		index = binary_search(arr2, 0, n-1, arr1[i]);
		cout << index + 1 <<" ";
	}
	cout << endl;
}

int main() 
{ 
    int arr1[] = { 1, 2, 3, 4, 7, 9 }; 
    int arr2[] = { 0, 1, 2, 1, 1, 4 }; 
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
    countEleLessThanOrEqual(arr1, arr2, m, n); 
    return 0; 
} 
