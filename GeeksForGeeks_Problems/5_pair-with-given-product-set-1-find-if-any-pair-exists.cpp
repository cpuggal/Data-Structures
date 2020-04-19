// Geeksforgeeks : https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/
// Given an array of distinct elements and a number x, find if there is a pair with a product equal to x.

// Input : arr[] = {10, 20, 9, 40};
//        int x = 400;
//Output : Yes

#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;

bool isPairFound(int arr[], int size, int x)
{
    map<int,int> m;
    int i = 0;
    int temp, div;

    for (i = 0; i < size; i++)
    {
        temp = arr[i];
        
        if ((temp == 0) && (x == 0))
            return true;

        if (temp !=0)
            div = x/temp;
        else
            continue;

        if (m.find(temp) == m.end()) // Key is absent
            m.insert(pair<int,int>(temp, 1));

        if ((m.find(temp) != m.end()) && (m.find(div) != m.end()) && m.find(temp) != m.find(div))
            // m.find(temp) != m.find(div) ensure 20 * 20 is not success 
        {
            // cout << "temp "<< temp << "div " << div << endl;
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[] = {10, 20, 9, 40};
    int x = 400;

    isPairFound(arr,sizeof(arr)/sizeof(int),x) ? cout << "Yes" << endl : cout << "No" << endl;

    int arr1[] = {10, 20, 9, 40};
    x = 190;
    isPairFound(arr1,sizeof(arr1)/sizeof(int),x) ? cout << "Yes" << endl : cout << "No" << endl;

    int arr2[] = {-10, 20, 9, -40};
    x = 400;
    isPairFound(arr2,sizeof(arr2)/sizeof(int),x) ? cout << "Yes" << endl : cout << "No" << endl;

    int arr3[] = {-10, 20, 9, 40};
    x = -400;
    isPairFound(arr3,sizeof(arr3)/sizeof(int),x) ? cout << "Yes" << endl : cout << "No" << endl;

    int arr4[] = {0, 20, 9, 40};
    x = 0;
    isPairFound(arr4,sizeof(arr4)/sizeof(int),x) ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}
        
