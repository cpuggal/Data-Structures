// https://www.geeksforgeeks.org/extract-maximum-numeric-value-given-string/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0

using namespace std;

bool is_number(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

int get_max_num(string str)
{
	if(str.length() == 0)
		return -1;
		
	int i = 0;
	int num = 0;
	int ans = 0;
	int curr_num = 0;
	
	for(i = 0; i < str.length(); i++)
	{
		if(is_number(str[i]))
		{
			if(DEBUG)
				cout << str[i] << " ";
			curr_num = int(str[i] - '0');
			num = num * 10 + curr_num;
		}
		else
		{
			if(ans < num)
				ans = num;
			
			num = 0;
		}
	}
	return ans;
}

string find_max(string s1, string s2)
{
	if (s1.length() > s2.length())
		return s1;
	else if (s2.length() > s1.length())
		return s2;
	else
	{
		int i = 0;
		while(i < s1.length())
		{
			if(s1[i] == s2[i])
				i++;
			else if(s1[i] > s2[i])
				return s1;
			else 
				return s2;
		}
	}
	return "";
}

string get_max_num_long_int(string str)
{
	if(str.length() == 0)
		return "-1";
		
	int i = 0, len = str.length();
	string curr_res = "";
	string ans = "";
	
	while(i < len)
	{
		while(i < len && str[i] == '0')
			i++;
		
		while(i < len && str[i] >= '0' && str[i] <= '9' )
		{
			curr_res = curr_res + str[i];
			i++;
		}
		
		if(curr_res.length() > 0)
			ans = find_max(curr_res, ans);
		else
			i++;
		
		curr_res = "";
	}
	return ans;
}

int main() {
	// your code goes here
	string str = "100klh564abc365bg";
	
	cout << get_max_num(str) << endl;
	cout << get_max_num("1001111klh564abc365bg") << endl;
	cout << get_max_num("100123klh542264abc312365bg") << endl;
	
	// Incorrect result since integer overflow and make negative ans
	cout << get_max_num("1001239999999999999klh542264abc312365bg") << endl;

	// Correct result since string doesn't overflow
	cout << get_max_num_long_int("1001239999999999999klh542264abc312365bg") << endl;
	return 0;
}

