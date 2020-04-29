// Goldbach's conjecture
// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void SieveOfEratosthenes(int num)
{
	if (num == 0)
		return;

	bool isPrime[num];
	memset(isPrime, true, sizeof(isPrime));

	int i, p;

	for(p = 2; p*p <= num; p++)
	{
		if (isPrime[p] == true)
		{
			for(i = p*p; i <= num; i = i+p)
			{
				isPrime[i] = false;
			}
		}
	}

	for(i = 1; i <= num; i++)
	{
		if (isPrime[i] == true)
			cout << i << endl;
	}
}

int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}

