// https://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
// 
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	
#define fo(i,n)		for(i = 0; i < n; i++)
using namespace std;

bool checkDuplicatesWithinK(int arr[], int size, int k)
{
	if((size == 0) || (k == 0))
		return true;
	
	map<int, int>myMap;
	int i = 0, val;
	
	fo(i,size)
	{
		auto it = myMap.find(arr[i]);
		if(it == myMap.end()) // mising element
		{
			myMap.insert({arr[i], i});
		}
		else
		{
			val = it->second;
			
			if (i-val <= k)
				return true;
			else
				it->second = i;
		}
	}
	return false;
}


int main () 
{ 
    int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (checkDuplicatesWithinK(arr, n, 3)) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
        
    int arr1[] = {1, 2, 3, 4, 1, 2, 3, 4};
    n = sizeof(arr1) / sizeof(arr1[0]);
    if (checkDuplicatesWithinK(arr1, n, 3)) 
        cout << "Yes" << endl;  
    else
        cout << "No" << endl; 
} 
