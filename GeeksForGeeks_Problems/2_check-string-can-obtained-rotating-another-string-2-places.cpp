// Geeksforgeeks : https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/
// Given two strings, the task is to find if a string can be obtained by rotating another string two places.


#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;

bool isRotated(string originalStr, string newStr, int position)
{
    if (originalStr.length() != newStr.length())
        return false;

    string clock_rot = "";
    string anti_clock_rot = "";
    int len = originalStr.length();

    clock_rot = clock_rot + originalStr.substr(len - 2, len) + originalStr.substr(0, len - 2);
    anti_clock_rot = anti_clock_rot + originalStr.substr(2, len) + originalStr.substr(0, 2);
    cout << "clock_rot " << clock_rot << endl << "anti_clock_rot " << anti_clock_rot << endl << "originalStr " << originalStr << endl << "newStr " << newStr << endl;

    return ((newStr.compare(clock_rot)) || (newStr.compare(anti_clock_rot)));
}

int main()
{
    string originalStr = "geeks";
    string newStr = "eksge";
    int pos = 2;

    isRotated(originalStr, newStr, pos) ? cout << "Yes, Rotated" << endl : cout << "Not rotated" << endl;

    return 0;
}
