// https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/

#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void printPattern_rec(string str, string buf, int i, int j, int size) // i is str index and j is buff's
{
	//cout << str << endl;
	if (i == size)
	{
		//cout<< "here " <<endl;
		cout << buf << endl;
		ans ++;
		return;
	}

	buf.push_back(str[i]);
	printPattern_rec (str, buf, i + 1, j + 1, size);

	buf.pop_back();
	//buf[j] = ' ';
	buf.push_back(' ');
	buf.push_back(str[i]);

	//buf[j+1] = str[i];
	printPattern_rec (str, buf, i + 1, j + 2, size);
}

void printPattern(string str)
{
	string buf;
	buf.push_back(str[0]);
	printPattern_rec(str, buf, 1, 1, str.length());
}

int main() {
	// your code goes here

	string str = "ABCD";
	cout << "Printed " << ans << " times" << endl;
    printPattern(str);
	return 0;
}
