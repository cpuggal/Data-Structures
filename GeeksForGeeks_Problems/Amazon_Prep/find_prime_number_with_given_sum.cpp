// https://www.geeksforgeeks.org/find-two-prime-numbers-with-given-sum/ 
// Input : 74
// Output : 3, 71
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void findPrimePair(int num)
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
	
	if(DEBUG)	
	{
		for(i = 1; i <= num; i++)
		{
			if (isPrime[i] == true)
				cout << i << endl;
		}
	}
	
	for(i = 2; i < num - 1; i++) // num - 1 since 1 is never a prime number
	{
		if ((isPrime[i]) && (isPrime[num - i]))
		{	
			cout << i << " and " << num - i << " are valid prime numbers combination" << endl;
			if (!DEBUG)
				return;
		}
	}
}

int main() 
{ 
    int n = 74; 
    findPrimePair(n); 
    return 0; 
} 
  
