// https://www.geeksforgeeks.org/find-the-missing-number/
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int getMissingNo(int arr[], int size)
{
	if(0 == size)
		return -1;

	int sum = 0;
	for(int i = 0; i < size; i++)
		sum += arr[i];

	return ((size+1) * (size + 2))/2 - sum;
}

int getMissingNo_xor(int arr[], int n)
{
	if (0 == n)
		return -1;

	int a = 1;
	int b = arr[0];
	int i;
	for (i = 2; i <= n+1; i++)
		a = a ^ i;

	for (i = 1; i < n; i++)
		b = b ^ arr[i];

	return a^b;
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNo(arr, n);
    cout << miss << endl;
    cout << getMissingNo_xor(arr, n) << endl;

} 
