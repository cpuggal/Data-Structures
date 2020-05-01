// https://www.geeksforgeeks.org/type-array-maximum-element/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void findType(int arr[], int size)
{
	if(0 == size)
		return;
	
	bool asc = false;
	bool des = false;
	bool rotated = false;
	int i, prev = arr[0];
	int max_value = arr[0];
	
	for(i = 1; i < size; i++)
	{
		if (arr[0] < arr[1])
			asc = true;
		else		
			des = true;
		
		if ((asc == true) && (prev > arr[i]))
			rotated = true;
			
		if ((des == true) && (prev < arr[i]))
			rotated = true;
		
		prev = arr[i];
		max_value = max(max_value, arr[i]);
	}
	if (asc)
	{
		cout << "Ascending ";
		if(rotated)
			cout << "rotated with maximum element " << max_value << endl;
		else
			cout << "with maximum element " << max_value << endl;
	}
	
	if (des)
	{
		cout << "Descending ";
		if(rotated)
			cout << "rotated with maximum element " << max_value << endl;
		else
			cout << "with maximum element " << max_value << endl;
	}	
}

int main() 
{ 
    int arr1[] = { 4, 5, 6, 1, 2, 3 }; // Ascending rotated 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    findType(arr1, n); 
  
    int arr2[] = { 2, 1, 7, 5, 4, 3 }; // Descending rotated 
    n = sizeof(arr2) / sizeof(arr2[0]); 
    findType(arr2, n); 
  
    int arr3[] = { 1, 2, 3, 4, 5, 8 }; // Ascending 
    n = sizeof(arr3) / sizeof(arr3[0]); 
    findType(arr3, n); 
  
    int arr4[] = { 9, 5, 4, 3, 2, 1 }; // Descending 
    n = sizeof(arr4) / sizeof(arr4[0]); 
    findType(arr4, n); 
  
    return 0; 
} 
