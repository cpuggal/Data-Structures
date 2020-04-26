// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
// Similar : https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
// Similar : https://www.geeksforgeeks.org/find-index-first-1-sorted-array-0s-1s/
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int i = -1;
int j = -1;

void findFirstAndLast_rec(int arr[], int start, int end, int size, int num)
{
	int mid = (start+end)/2;

	if ((start == 0) && (arr[start] == num))
		i = start;

	if ((end == size - 1) && (arr[end] == num))
		j = end;

	if ((i == -1) && (arr[mid] == num) && (mid - 1 >= 0) && (arr[mid-1] != num)) //i is found
		i = mid;

	if ((j == -1) && (arr[mid] == num) && (mid + 1 <= size -1) && (arr[mid+1] != num)) //j is found
		j = mid;

	if (arr[mid] == num)
	{
		if(i == -1)
			findFirstAndLast_rec(arr, start, mid, size, num);
		if(j == -1)
			findFirstAndLast_rec(arr, mid, end, size, num);
	}
	else if (arr[mid] > num) //go left
		findFirstAndLast_rec(arr, start, mid, size, num);
	else
		findFirstAndLast_rec(arr, mid, end, size, num);
}

void findFirstAndLast(int arr[], int size, int num)
{
	if (0 == size)
		return;
	i = j = -1;
	findFirstAndLast_rec(arr, 0, size -1, size, num);

	if ((i != -1) && (j != -1))
		cout << "Start: " << i << ", end: " << j << endl;
	else
		cout << "-1" << endl;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8 };
    int n = sizeof(arr)/sizeof(int);
    int x = 8;
    findFirstAndLast(arr, n, x);
    return 0;
}


