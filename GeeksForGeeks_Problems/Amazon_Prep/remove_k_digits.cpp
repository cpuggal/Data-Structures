// https://www.geeksforgeeks.org/build-lowest-number-by-removing-n-digits-from-a-given-number/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void buildLowestNumberInt(string str, int n, string &local)
{
	if (n == 0)
	{	local.append(str);
		return;
	}

	int len = str.length();

	if (len <= n)
		 return;

	int i = 0, minIdx = 0;

	for (i = 1; i <= n; i++)
	{
		if (str[i] < str[minIdx])
			minIdx = i;
	}
	local.push_back(str[minIdx]);


	buildLowestNumberInt(str.substr(minIdx+1, len - minIdx), n - minIdx, local);
}

string buildLowestNumber(string str, int n)
{
	if (n == 0)
		return str;

	string local = "";

	if (str.length() <= n)
		return "none";

	buildLowestNumberInt(str, n, local);

	return local;
}

string buildLowestNumberWithStack(string str, int n)
{
	if (n == 0)
		return str;

	int len = str.length();

	if (len <= n)
		return "none";

	stack <int> s;
	int temp;
	int stackLen;
	for (int i = 0; i < len; i++)
	{
		temp = str[i];
		stackLen = s. size();
		while ((!s.empty()) && (s.top() > temp))
		{
			// pop from Stack and iterate
			if (stackLen + (len - i - 1) >= len - n)
				s.pop();
			else
				break;
		}
		s.push(temp);
	}
	string result;
	int r, i = 0;
	while (!s.empty())
	{
		r = s.top();
		result.push_back(r);
		i++;
		s.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
    string str = "121198";
    int n = 2;
    cout << buildLowestNumber(str, n) << endl;
    cout << buildLowestNumber(str, n+10) << endl;
    cout << buildLowestNumberWithStack(str, n);

    return 0;
}
