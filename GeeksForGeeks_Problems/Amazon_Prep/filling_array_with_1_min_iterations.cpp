// https://www.geeksforgeeks.org/fill-array-1s-minimum-iterations-filling-neighbors/
//
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int countIterations(int arr[], int size)
{
	if(0 == size)
		return -1;

	int i, curr = 0, prev = -1;
	bool flag = false;
	bool startZero = false;
	bool endZero = false;
	int ans = 0;
	int idx_one = 0;

	int val1 = 0;
	int val2 = 0;

	if (arr[0] == 0)
		startZero = true;

	if (arr[size -1] == 0)
		endZero = true;

	for(i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			curr++;
		}
		if ((startZero) && (flag == false) && (arr[i] == 0))
		{
			val1++;
		}
		if (arr[i] == 1)
		{
			if (prev == 0)
			{
				if (ans <= curr)
				{
					ans = curr;
				}
			}
			flag = true;
			curr = 0;
			idx_one = i;
		}
		if (DEBUG)
			cout << "i: " << i << " ans: " << ans << " curr: " << curr << endl;
		prev = arr[i];
	}

	int final = (ans+1)/2;

	if (endZero)
		val2 = size - idx_one - 1;

	if (DEBUG)
		cout << "Val1: " << val1 << " val2 : " << val2 << " final: " << final << endl;

	if (flag == false) //no 1 is present
		return -1;

	if ((startZero) || (endZero))
	{
		int max1 = max (val1, val2);
		return max(final, max1);
	}
	else
		return final;
}

int main()
{
    int arr[] = {0, 1, 0, 0, 1, 0, 0,
                 0, 0, 0, 0, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countIterations(arr, n) << endl;
    int arr1[] = {0, 0, 1, 1, 0, 0, 1, 1, 0,
                    1, 1, 1, 1, 0, 0, 0, 1};
    cout << countIterations(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
    return 0;
}
