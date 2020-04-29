// https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
// Input : {5, 5, 10, 100, 10, 5}
// Output : 110
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int FindMaxSum(int arr[], int size)
{
	if (0 == size)
		return 0;
		
	int sum1 = 0, sum2 = 0;
	int i;
	
	for(i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			sum1 += arr[i];
		else
			sum2 += arr[i];
	}
	return max(sum1, sum2);
}

int main() 
{ 
  int arr[] = {5, 5, 10, 100, 10, 5}; 
  int arr1[] = {5, 5, 10, 100, 10, 5};
  int arr2[] = {1, 2, 3};
  int arr3[] = {1, 20, 3};
  cout << FindMaxSum(arr, sizeof(arr) / sizeof(arr[0])) << endl; 
  cout << FindMaxSum(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl; 
  cout << FindMaxSum(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl; 
  cout << FindMaxSum(arr3, sizeof(arr3) / sizeof(arr3[0])) << endl; 
  return 0; 
} 
