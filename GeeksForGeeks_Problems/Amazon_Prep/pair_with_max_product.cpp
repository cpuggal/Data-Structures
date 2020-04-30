// https://www.geeksforgeeks.org/return-a-pair-with-maximum-product-in-array-of-integers/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int maxProduct(int arr[], int size)
{
	if(0 == size)
		return 0;
		
	if (1 == size)
		return arr[0];

	sort(arr, arr+size);
	
	int x = arr[0] * arr[1];
	int y = arr[size-1] * arr[size-2];
	
	if (x > y)
		cout << "Pair is : " << arr[0] << ", " << arr[1] << endl;
	else
		cout << "Pair is : " << arr[size-2] << ", " << arr[size-1] << endl;
		
	return max(x, y);
}
int main() 
{ 
    int arr[] = {1, 4, 3, 6, 7, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxProduct(arr, n) << " is Product" << endl; 
    
    int arr1[] = {-1, -3, -4, 2, 0, -5};
    cout << maxProduct(arr1, sizeof(arr1)/sizeof(arr1[0])) << " is Product" << endl; 
    
    int arr2[] = {4};
    cout << maxProduct(arr2, sizeof(arr2)/sizeof(arr2[0])) << " is Product" << endl;
    cout << maxProduct({}, 0) << " is Product" << endl;
    
    return 0; 
}
