// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void permute(string str, int l, int r)
{
	if(l == r)
	{
		cout << str << endl;
		return;
	}
	int i;
	for(i = l; i <= r; i++)
	{
		swap(str[l], str[i]);
		permute(str, l+1, r);
		swap(str[i], str[l]);
		
	}
}
int main()  
{  
    string str = "ABC";  
    int n = str.size();  
    permute(str, 0, n-1);  
    cout << endl;
    return 0;  
} 
