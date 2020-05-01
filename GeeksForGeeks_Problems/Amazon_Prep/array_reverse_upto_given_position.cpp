// https://www.geeksforgeeks.org/reverse-an-array-upto-a-given-position/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void reverse(int arr[], int size, int k)
{
	if(0 == size)
		return;
	
	if(k > size)
	{
		cout << "Invalid K value.. Setting it to size" << endl;
		k = size;
	}
	
	int i = 0;
	k--;
	while(i < k)
	{
		swap(arr[i], arr[k]);
		i ++;
		k--;
	}
}

int main() 
{ 
    int a[] = {1, 2, 3, 4, 5, 6}; 
    int n = sizeof(a) / sizeof(int), k = 4; 

    for (int i = 0; i < n; ++i) 
        cout << a[i] << " "; 
    cout << endl;
    reverse(a, n, k); 
  
    for (int i = 0; i < n; ++i) 
        cout << a[i] << " "; 
    cout << endl;
    return 0; 
} 
