// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
// Similar : https://www.geeksforgeeks.org/rearrange-array-in-alternating-positive-negative-items-with-o1-extra-space-set-2/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

class GFG{
	public:
		void rearrange(int arr[], int size)
		{
			if (0 == size)
				return;
			
			int i = 0, j = size - 1, temp;
			
			while(i < j) //disect arr in +ve and -ve numbers
			{
				while(arr[i] > 0) // find first -ve number left
				{
					i++;
				}
				while(arr[j] < 0) // find first +ve number from right
				{
					j--;
				}
				if (i < j)
					{
						temp = arr[j];
						arr[j] = arr[i];
						arr[i] = temp;
					}
			}
			// i now is pointing to first -ve number in arr
			j = 0; // start of +ve numbers
			while((j <= i) && (j < size) && (i < size))
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				j = j + 2;
				i++;
			}
		}
		
		void printArray(int arr[], int size)
		{
			int i;
			for(i = 0; i < size; i++)
				cout << arr[i] << " ";
			
			cout << endl;
		}
};

int main()  
{ 
    int arr[] = {-1, 2, -3, 4,  
                  5, 6, -7, 8, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    GFG test; 
    test.printArray(arr, n);
    test.rearrange(arr, n); 
    test.printArray(arr, n); 
    return 0; 
} 
