//  https://www.geeksforgeeks.org/count-possible-groups-size-2-3-sum-multiple-3/
//
//  Input = {3, 6, 7, 2, 9}
//  Output = 8
//

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;
#define DEBUG 0

int findgroups(int arr[], int n)
{
	int count[3];
	int i = 0;
	for (i = 0; i < 3; i++)
		count[i] = 0;
		
	for (i = 0; i < n; i++)
	{
		count[arr[i] % 3]++;
	}
	int x = count[0];
	int y = count[1];
	int z = count[2];
	
	int two_pair_count = (x * (x-1))/2 + // all from x
						 y * z; // one from y one from z
	int three_pair_count = (x * (x - 1) * (x -2))/6 + // all from x
						   (y * (y - 1) * (y -2))/6 + // all from y 
						   (z * (z - 1) * (z -2))/6 + // all from x
						   (x * y * z); // one from each group
	return two_pair_count + three_pair_count;
}

int main() 
{ 
    int arr[] = {3, 6, 7, 2, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Required number of groups are " 
         << findgroups(arr,n) << endl; 
    return 0; 
} 
