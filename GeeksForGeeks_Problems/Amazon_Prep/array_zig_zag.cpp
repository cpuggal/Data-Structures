// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	
#define fo(i,n)		for(i = 0; i < n; i++)

using namespace std;

void zigZag(int arr[], int size)
{
	if(0 == size)
		return;
	
	int i, curr, next;
	bool flag = true; // <
	fo(i, size-1)
	{
		curr = arr[i];
		next = arr[i+1];
		if(flag)
		{
			if(curr > next) // curr should be more than next
			{
				arr[i] = next;
				arr[i+1] = curr;
			}
			flag = false;
		}
		else
		{
			if(curr < next)
			{
				arr[i] = next;
				arr[i+1] = curr;
			}
			flag = true;
		}
	}
}

void print(int arr[], int n)
{
	int i;
	fo(i, n)
        cout << arr[i] << "  "; 
    cout << endl;
}
int main() 
{ 
    int  arr[] = {4, 3, 7, 8, 6, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    print(arr, n);
    zigZag(arr, n); 
    print(arr, n);
    return 0; 
} 

