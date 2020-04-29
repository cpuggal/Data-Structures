// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
// Input : {1, 23, 12, 9, 30, 2, 50} with k = 3
// Output : 50, 30, 23
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0


void kLargest_sort(int arr[], int size, int k)
{
	if (0 == size)
		return;
	
	sort(arr, arr+size);
	int i = 0;
	while(i != k)
	{
		cout << arr[size-i-1] << " ";
		i++;
	}
	cout << endl;
}

void kLargest_heap(int arr[], int size, int k)
{
	if(0 == size)
	{
		cout << "Invalid Size" << endl;
		return;
	}
	
	if(k > size)
	{
		cout << "Invalid k value " << endl;
		return;
	}
	
	vector<int> vec (arr, arr+size);
	make_heap(vec.begin(), vec.end()); // will make max heap
	
	int i = 0;
	while(i != k)
	{
		
		cout << vec.front() << " ";
		//vec.erase(vec.begin());
		pop_heap(vec.begin(), vec.end()); // pop's out highest value from heap and place at end of vector 
		vec.pop_back(); // remove end element of vector
		i++;
	}
	cout << endl;	
}

struct greaters{
	bool operator()(const long& a, const long &b) 
	const{
		return a > b;
	}
};

void kSmallest_heap(int arr[], int size, int k)
{
	if(0 == size)
	{
		cout << "Invalid Size" << endl;
		return;
	}
	
	if(k > size)
	{
		cout << "Invalid k value " << endl;
		return;
	}
	
	vector<int> vec (arr, arr+size);
	make_heap(vec.begin(), vec.end(), greaters()); // will make min heap using comparator function
	
	int i = 0;
	while(i != k)
	{
		
		cout << vec.front() << " ";
		//vec.erase(vec.begin());
		pop_heap(vec.begin(), vec.end(), greaters()); // pop's out lowest value from heap and place at end of vector 
		vec.pop_back(); // remove end element of vector
		i++;
	}
	cout << endl;	
}

int main() 
{ 
    int arr[] = { 1, 23, 12, 9, 30, 2, 50 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    kLargest_sort(arr, n, k); 
    kLargest_heap(arr, n, k);
    kSmallest_heap(arr, n, k);
} 
