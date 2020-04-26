// https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/
// Input : {5, 1, 3, 4, 7}
// Output : 4
//Similar : https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
// Similar : https://www.geeksforgeeks.org/find-number-of-triangles-possible/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG			0

int countTriplets (int arr[], int n, int sum)
{
	if (n == 0)
		return 0;
	
	sort(arr, arr+n);
	
	int i, j, k;
	int ans = 0;
	for(i = 0; i < n - 2; i++)
	{
		j = i + 1;
		k = n - 1;
		
		if ((arr[i] + arr[j] + arr[j+1]) < sum) // since array is sorted so if these three doesn't match then no point going on
		{
			while(j < k)
			{
				if (arr[i] + arr[j] + arr[k] < sum)
				{
					ans += k - j;
					j ++;
				}
				else
				{
					k--;
				}
			}
		}
		else
			break;
	}
	return ans;
}

int main() 
{ 
    int arr[] = {5, 1, 3, 4, 7}; 
    int n = sizeof arr / sizeof arr[0]; 
    int sum = 12; 
    cout << countTriplets(arr, n, sum) << endl; 
    return 0; 
} 

