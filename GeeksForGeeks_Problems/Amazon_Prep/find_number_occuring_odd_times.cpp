// https://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
// Input : { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 } 
// Output : 5
// 


#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int getOddOccurrence_hash(int arr[], int size)
{
	if(0 == size)
		return -1;

	map<int, int> mymap;
	int i;
	int sum = 0;
	for(i = 0; i < size; i++)
	{
		auto it = mymap.find(arr[i]);
		if (it == mymap.end()) // Element is not in map, so add to sum and insert to Map
		{
			mymap.insert({arr[i], 1});
			sum = sum + arr[i];
			if (DEBUG)
				cout << "Adding .. sum : " << sum << ", arr[i] : " << arr[i] << endl;
		}
		else // Element already in map, so remove it and modify Sum accordingly
		{
			sum = sum - it->first;
			mymap.erase(arr[i]);
			if (DEBUG)
				cout << "Removing .. sum : " << sum << ", arr[i] : " << arr[i] << endl;
		}
	}
	if (DEBUG)
		cout << "sum : " << sum << endl;
	return sum;
}

int getOddOccurrence_xor(int arr[], int size)
{
	if(0 == size)
		return -1;

	int result = 0;
	int i;

	for(i = 0; i < size; i++)
		result = result ^ arr[i];

	return result;
}

int main()
{
    int arr[] = { 2, 3, 5, 4, 5, 2, 4,
                    3, 5, 2, 4, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    cout << getOddOccurrence_hash(arr, n) << endl;
    cout << getOddOccurrence_xor(arr, n) << endl;
    return 0;
}


