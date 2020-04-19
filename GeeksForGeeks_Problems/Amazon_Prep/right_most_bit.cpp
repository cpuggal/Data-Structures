// https://www.geeksforgeeks.org/position-of-rightmost-set-bit/

#include <bits/stdc++.h>
using namespace std;

int getFirstSetBitPos(int n)
{
	if (n == 0)
		return 0;
	else if (n % 2 == 1) // odd
		return 1;
	else	
		return (log2(n & -n) + 1); // 2's complement 
}

int getFirstSetBitPosLeftShift(int n)
{
	if (n == 0)
		return 0;

	if (n % 2 == 1) // odd
		return 1;

	int i = 0;
		
	while(1)
	{
		if (n & 1 << i)
			return i + 1;
		else
			i++;
	}
}

int getFirstSetBitPosXOR(int n)
{
	if (n == 0)
		return 0;
	if (n % 2 == 1) // odd
		return 1;
	
	int num = ((n & (n - 1)) ^ n);
	return log2(num) + 1;
}

int main() {
	// your code goes here
	
	int n = 12;
	cout << getFirstSetBitPos(n) << endl;
	cout << getFirstSetBitPosLeftShift(n) << endl;
	cout << getFirstSetBitPosXOR(n);

	return 0;
}