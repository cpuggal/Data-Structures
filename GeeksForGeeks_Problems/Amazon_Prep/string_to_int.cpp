// https://www.geeksforgeeks.org/evaluation-of-expression-tree/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG	0	
using namespace std;

int String_to_Int(string str)
{
	int ans = 0;
	int i, start = 0;
	int sign = 1;
	
	if(str[0] == '-')
	{
		sign = -1;
		start = 1;
	}
	
	for(i = start; i < str.length(); i++)
	{
		if(DEBUG)
			cout << int(str[i]) << " ";
		 ans = ans * 10 + (int(str[i]) - 48);
	}
	
	ans = ans * sign;
	
	return ans;
}

int main() 
{ 
    string s1 = "11234";
    string s2 = "-111";
    string s3 = "0";
    cout << String_to_Int(s1) << endl;
    cout << String_to_Int(s2) << endl;
    cout << String_to_Int(s3) << endl;    
    return 0; 
} 
