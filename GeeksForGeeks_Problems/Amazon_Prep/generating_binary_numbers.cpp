// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void generatePrintBinary(int num)
{
	if (num == 0)
		return;
	
	queue<string> binaryQueue;
	int i = 0;
	string s1, s2, s3;
	binaryQueue.push("1");
	
	while(i != num)
	{
		s1 = binaryQueue.front();
		binaryQueue.pop();
		cout << s1 << endl;
		//s2 = s1.append("0");
		//s3 = s1.append("1");
		binaryQueue.push(s1 + "0");
		binaryQueue.push(s1 + "1");		
		i++;
	}
}

int main() 
{ 
    int n = 10; 
    generatePrintBinary(n); 
    return 0; 
}
