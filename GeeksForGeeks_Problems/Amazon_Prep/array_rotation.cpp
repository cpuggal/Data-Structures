// https://www.geeksforgeeks.org/array-rotation/

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a%b);
}

void leftRotate(int arr[], int d, int size)
{
	int i, j, k, temp;
	int gcd = GCD(d, size);

	for (i = 0; i < gcd; i++)
	{
		j = i;
		temp = arr[i];
		while(1)
		{
			k = j + d;
			if (k >= size)
				k = k - size;

			if (k == i) // loop ended
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}

}

void printArray(int arr[], int size)
{
	int i = 0;

	for (i = 0; i < size; i ++)
		cout << arr[i] << " ";

	cout << endl;
}

int main() {
	// your code goes here
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    printArray(arr, n);
    leftRotate(arr, 2, n);
    printArray(arr, n);

	return 0;
}
