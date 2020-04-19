// Geeksforgeeks :https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
// Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.
// Input:  arr[] = {1, 6, 4, 10, 2, 5}
// Output:         {_, 1, 1,  4, 1, 2}


#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;
#define PrintArr(arr, size)     for(int i=0;i<size;i++) cout << arr[i] << " "; cout << endl;
// #define MIN     -9999
#define MIN "_"

int main()
{
    int input[] = {1, 6, 4, 10, 2, 5};
//    int input[] = {1, 6, 4, -10, 2, 5};
//    int input[] = {5000, 50, 5};
    int size = sizeof(input)/sizeof(int);
    stack<int> s;
    string output[size];
    int i = 0;

    PrintArr(input, size)
    output[0] = MIN;
    s.push(input[0]);

    for (i = 1; i < size; i++)
    {
        if (s.size() == 0) // Stack is empty, can't get s.top()
        {    
            output[i] = MIN; //Default value to fallback logic
            s.push(input[i]);
        }
        else if (s.top() > input[i])
        {
            // Top element of stack is bigger, remove it and push this one
            s.pop();
            i --;
            continue;
        }
        else
        {
            output[i] = to_string(s.top());
            s.push(input[i]);
        }
    }

    PrintArr(output, size)
    return 0;
}
