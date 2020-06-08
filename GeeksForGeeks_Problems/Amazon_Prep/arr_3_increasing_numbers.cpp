// https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0

using namespace std;

void find3Numbers(int arr[], int n)
{
	int min[n], max[n];
	
	int i, temp;
	
	min[0] = -1;
	temp = arr[0];
	for(i = 1; i < n; i++)
	{
		if(arr[i] < temp)
		{
			temp = arr[i];
			min[i] = -1;
		}
		else
		{
			min[i] = temp;
		}
	}
	
	max[n-1] = -1;
	temp = arr[n-1];
	
	for(i = n -1; i >= 0; i--)
	{
		if(arr[i] > temp)
		{
			temp = arr[i];
			max[i] = -1;
		}
		else
		{
			max[i] = temp;
		}
	}
	
	for(i = 0; i < n; i++)
	{
		if((min[i] != -1) && (max[i] != -1))
		{
			cout << min[i] << " " << arr[i] << " " << max[i] << endl;
			break;
		}
	}
}

int main() 
{ 
    int arr[] = { 12, 11, 10, 5, 6, 2, 30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    find3Numbers(arr, n); 
    return 0; 
} 

