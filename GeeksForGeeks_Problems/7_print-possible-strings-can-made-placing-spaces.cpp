// Geeksforgeeks : https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/
// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

//Input:  str[] = "ABC"
//Output: ABC
//        AB C
//        A BC
//        A B C


#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;

// i = str index
// j = buf index
void printer(char *str, char *buf, int len, int i, int j)
{
    if (i == len)
    {
        // String is over
        buf[j] = '\0';
        cout << buf << endl;
        return;
    }
// two possibilies, consider char or add space and char

  buf[j] 



void printPossibilities(String str)
{
    int len = strlen(str);

    if (len == 0)
        cout << "String is empty" << endl;
    else
    {
        char buf[2*len];
        buf[0] = str[0];
        printer(str, buf, len, 1, 1);
    }
}


int main()
{
    char *str = "Chand";
    printPossibilities(str);
    return 0;
}
