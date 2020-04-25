// https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
//
//
//
//


#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;
#define DEBUG 0 

int i = -1, j = -1; // lower and upper bounds

void countOccurrences_recu(int arr[],int start, int end, int size, int x)
{
	int mid = (start + end) / 2;
	
	if (mid == start)
	
	if (DEBUG)
	{
		cout << "start : " << start << " mid : " << mid << " end : " << end << endl;
		cout << "i : " << i << " j : " << j << endl;
	}
	
	if ((start == 0) && (arr[start] == x))
		i = start;
	
	if ((end == size - 1) && (arr[end] == x))
		j = end;

	if ((i == -1) && (arr[mid] == x))
	{
		if ((mid - 1 >= 0) && (arr[mid - 1] != x)) // || // {1, 2 with x = 2
		    //((mid == 0) && (arr[0] == x))) // {2, 2 with x = 2
			i = mid;
	}
	
	if ((j == -1) && (arr[mid] == x))
	{
		if ((mid + 1 <= size - 1) && (arr[mid + 1] != x))// || // 2,3} with x = 2
		    //((mid == size - 1) && (arr[size -1] == x))) //  2,2 } with x = 2
			j = mid;
	}
	
	if (arr[mid] == x) // go both side
	{
		if (i == -1) 
			countOccurrences_recu(arr, start, mid, size, x);
			
		if (j == -1)
			countOccurrences_recu(arr, mid, end, size, x);
	}
	else if (arr[mid] > x) // x if on left
		countOccurrences_recu(arr, start, mid, size, x);
		
	else if (arr[mid] < x)
		countOccurrences_recu(arr, mid, end, size, x);
	else
		return;
}


int countOccurrences(int arr[], int size, int x)
{
	if (size == 0) // Size if 0, empty array
		return -1;
	
	if ((arr[0] == x) && (arr[size -1] == x)) // If full array is same number
		return size - 1;
	
	if ((arr[0] > x) || (arr[size -1] < x)) // Dont search if not in array
		return -1;
	
	i = -1, j = -1;

	countOccurrences_recu(arr, 0, size - 1, size, x);
	
	if ((i != -1) && (j != -1))
	{
		if (DEBUG)
			cout << "i : " << i << " j : " << j << endl;
		return j - i + 1;
	}
	else
		return -1;
}

int countOccurrences_InBuilt(int arr[], int size, int x)
{
	int *low = lower_bound(arr, arr+size, x);
	
	if ((low == arr + size) || (*low != x))
		return -1;
	
	int *upper = upper_bound(low, arr + size, x);
	
	return upper - low;
}

int main() 
{ 
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8 };
    
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << countOccurrences(arr, n, 2) << endl; 
    cout << countOccurrences(arr, n, 8) << endl; 
    cout << countOccurrences(arr, n, 80) << endl; 
    cout << countOccurrences(arr, n, 1) << endl; 
    cout << countOccurrences(arr, n, 3) << endl; 
    cout << countOccurrences(arr, n, 0) << endl; 
	cout << " countOccurrences_InBuilt " << endl;
    cout << countOccurrences_InBuilt(arr, n, 2) << endl; 
    cout << countOccurrences_InBuilt(arr, n, 8) << endl; 
    cout << countOccurrences_InBuilt(arr, n, 80) << endl;

    return 0; 
} 

