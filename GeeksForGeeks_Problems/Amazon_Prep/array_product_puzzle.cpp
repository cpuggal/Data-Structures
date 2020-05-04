// https://www.geeksforgeeks.org/a-product-array-puzzle/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void productArray(int arr[], int size)
{
	if (0 == size)
		return;
	
	int i = 0 ;
	int LeftArr[size];
	
	LeftArr[0] = 1;
	
	for(i = 1; i < size; i++)
	{
		LeftArr[i] = LeftArr[i-1] * arr[i-1];
	}	
	// { 1, 10, 30, 150, 900}
	
	int RightSum = 1;
	for(i = size - 1; i >= 0; i--)
	{
		LeftArr[i] = LeftArr[i] * RightSum;
		RightSum = RightSum * arr[i];
	}
		// { 1, 10, 30, 150, 900}

	for(i = 0; i < size; i++)
		cout << LeftArr[i] << " ";

	cout << endl;
}

int main() 
{ 
    int arr[] = { 10, 3, 5, 6, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "The product array is: \n"; 
    productArray(arr, n); 
} 
