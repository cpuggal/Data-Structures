// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
// Input : 
// Output : 
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG	0	

using namespace std;

bool isValidStartInput(char ch)
{
	if ((ch == '{') || (ch == '[') || (ch == '('))
		return true;
	else
		return false;
}

bool isCorrectMatch(char x, char y)
{
	if (((x == '{') && (y == '}')) ||
		 ((x == '(') && (y == ')')) ||
		 ((x == '[') && (y == ']')))
		 return true;
	else
		return false;
}

bool areParanthesisBalanced(string str)
{
	if(str.length() == 0)
		return true;
	bool res = false;
	int i;
	char ch, top;
	stack <char > myStack;
	
	for(i = 0; i < str.length(); i++)
	{
		ch = str[i];
		
		if(DEBUG)
			cout << ch << " ";
			
		if((myStack.empty()) || (isValidStartInput(ch)))
			myStack.push(ch);
		else
		{
			top = myStack.top();
			if(isCorrectMatch(top, ch))
				myStack.pop();
			else
				return false;
		}
	}

	return true;
}

int main() 
{ 
    string expr = "{()}[]"; 
  
    if (areParanthesisBalanced(expr)) 
        cout << "Balanced" << endl; 
    else
        cout << "Not Balanced" << endl; 
    return 0; 
}
