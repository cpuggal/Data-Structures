// https://www.geeksforgeeks.org/replace-0-5-input-integer/

#include <bits/stdc++.h>
using namespace std;

int replace0with5_rec(int num, int i)
{
	if (num == 0)
		return 0;

	int rem;

	if (num % 10 == 0)
		rem = 5;
	else
		rem = num % 10;

	return replace0with5_rec(num / 10, i+1) + rem * pow (10, i);
}

int replace0with5(int number)
{
	if (number == 0)
		return 5;

	int answer = 0, pos = 0;
	int rem = 0;
	while (number != 0)
	{
		rem = number % 10;
		if (rem == 0)
			rem = 5;

		answer = answer + rem * pow(10, pos);
		number = number / 10;
		pos ++;
	}
	return answer;
}

int main() {
	// your code goes here

	cout << replace0with5(1020) << endl;
	cout << replace0with5_rec(1020,0) << endl;

	return 0;
}
