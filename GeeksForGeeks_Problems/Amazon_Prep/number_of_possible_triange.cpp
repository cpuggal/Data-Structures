// https://www.geeksforgeeks.org/find-number-of-triangles-possible/
// similar : https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int findNumberOfTriangles(int arr[], int size)
{
	if (0 == size)
		return -1;

	int i, j, k, ans = 0;

	sort(arr, arr+size);
	for(k = size - 1; k > 1; k--)
	{
		i = 0;
		j = k - 1;
		while(i < j)
		{
			if (arr[i] + arr[j] > arr[k])
			{
				ans += j - i;

				if (DEBUG)
					cout << "i : " << i << " j : " << j << " k: " << k << " ans: "<< ans << endl;

				j--;
			}
			else
				i++;
		}
	}
	return ans;
}

int main()
{
    int arr[] = { 10, 21, 22, 100, 101, 200, 300 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Total number of triangles possible is " << findNumberOfTriangles(arr, size) << endl;

    return 0;
}


