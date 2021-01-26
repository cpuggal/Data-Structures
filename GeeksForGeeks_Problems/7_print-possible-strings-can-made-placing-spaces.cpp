//https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
#include <iostream>
#include <bits/stdc++.h>
// Geeksforgeeks : https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/
// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

//Input:  str[] = "ABC"
//Output: ABC
//        AB C
//        A BC
//        A B C

using namespace std;

// i = str index
// j = buf index


void printer(string &str, string buf, int len, int i, int j)
{
    if (i == len) {
        // String is over
        //buf.c_str();
        cout << buf << endl;
        return;
    }
    if ((i > len) || (j > len))
		return;
// two possibilies, consider char or add space and char

	//consider char
  buf[j] = str[i];
  printer(str, buf, len, i + 1, j + 1);

	// add space
  buf[j] = ' ';
  buf[j + 1] = str[i];
  printer(str, buf, len, i + 1, j + 2);
}

void printPossibilities(string &str)
{
    int len = str.length();

    if (len == 0)
        cout << "String is empty" << endl;
    else
    {
        string buf(2*len, ' '); // Mistake here
        buf[0] = str[0];
        //cout << buf << " " << endl;
        printer(str, buf, len, 1, 1);
    }
}


int main()
{
    string str = "Chand";
    printPossibilities(str);
    return 0;
}
