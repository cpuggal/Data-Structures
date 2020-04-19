// https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/


// C++ program to check if a given tree is BST. 
#include <bits/stdc++.h> 
using namespace std; 

bool isRotated(string str, string s2)
{
	if (str.length() != s2.length())
		return false;
	
	string left_rotate = str.substr(4) + str.substr(0, 4);
	string right_rotate = str.substr(2) + str.substr(0, 2);
	
	cout << "left : " << left_rotate;
	cout << ", right : " << right_rotate << endl;
	
	return (s2.compare(left_rotate) || s2.compare(right_rotate));
}

bool isRotated(string str, string s2, int k)
{
	if (str.length() != s2.length())
		return false;
		
	int l1 = str.length();
	int l2 = l1 - k;
	
	string left_rotate = str.substr(l2) + str.substr(0, l2);
	string right_rotate = str.substr(k) + str.substr(0, k);
	
	cout << "left : " << left_rotate;
	cout << ", right : " << right_rotate << endl;
	
	return (s2.compare(left_rotate) || s2.compare(right_rotate));
}
/* Driver program to test above functions*/
int main() 
{ 
	string str = "amazon";
	string r1 = "onamaz";
	string r2 = "azonam";
	
    (isRotated(str, r1))?cout << "Yes\n":cout << "No\n"; 
    (isRotated(str, r2))?cout << "Yes\n":cout << "No\n"; 
    
    (isRotated(str, r1, 2))?cout << "Yes\n":cout << "No\n"; 
    (isRotated(str, r2, 2))?cout << "Yes\n":cout << "No\n"; 
    
	return 0; 
} 


