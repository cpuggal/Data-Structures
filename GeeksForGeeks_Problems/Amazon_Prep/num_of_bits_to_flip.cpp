// https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
// Input = 10, 20
// Output = 4
//

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

int FlippedCount_BitByBit(int a, int b)
{
	int Bit1, Bit2;
	int i = 0, j = 0;
	int ans = 0;

	while (1)
	{
		if ((a == 0) && (b == 0))
			break;

			Bit1 = a & 1;
			Bit2 = b & 1;
			a = a >> 1;
			b = b >> 1;
		if (Bit1 != Bit2)
			ans ++;
	}
	return ans;
}

int FlippedCount_XoR(int a, int b)
{
	int a_xor_b = a ^ b;

	int ans = 0;

	while(a_xor_b)
	{
		if (a_xor_b & 1)
			ans ++;
		a_xor_b = a_xor_b >> 1;
	}
	return ans;
}

int FlippedCount_XoR1(int a, int b)
{
	int a_xor_b = a ^ b;

	int ans = 0;

	while(a_xor_b)
	{
		ans ++;
		a_xor_b = a_xor_b & (a_xor_b - 1);
	}
	return ans;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << FlippedCount_BitByBit(a, b) << endl;
    cout << FlippedCount_BitByBit(7, 10) << endl;
    cout << FlippedCount_XoR(a, b) << endl;
    cout << FlippedCount_XoR(7, 10) << endl;
    cout << FlippedCount_XoR1(a, b) << endl;
    cout << FlippedCount_XoR1(7, 10) << endl;

    return 0;
}

