#include<stdio.h>
#include<stdlib.h>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

/* https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
 *  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
 *  Output: 6  (j = 7, i = 1)
 *  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
 *  Output: 8 ( j = 8, i = 0)
 */

using namespace std;

int brute_force_soln(int arr[], int size)
{
    int i = 0, j = 0;
    int ans = 0;

    for (i = 0; i < size; i++)
        for (j = i; j < size; j++)
        {
            if ((arr[j] > arr[i]) && (j - i > ans))
                ans = j - i;
        }

    return ans;
}

int optimized_solution(int arr[], int size)
{
    int i = 0, j = 0;
    int LSmall[size], RLarge[size];
    int currMin = arr[0], currMax = arr[size-1], ans = INT_MIN;

    for (i = 0; i < size; i++)
    {
        if (arr[i] < currMin)
        {
            currMin = arr[i];
        }
        LSmall[i] = currMin;

        if (arr[size - i -1] > currMax)
        {
            currMax = arr[size - i -1];
        }
       
        RLarge[size - i -1] = currMax;
    }
/*
    for (i = 0; i < size; i++)
    {
        cout << LSmall[i] << ",";
    }
    cout << endl;

    for (i = 0; i < size; i++)
    {
        cout << RLarge[i] << ",";
    }
    cout << endl;
*/
    i = 0; j = 0;
    while (i != size-1)
    {
        if ((ans <= j - i) && (RLarge[j] > LSmall[i]))
        {
            ans = j - i;
            j++;
//           cout << ans << endl;
        }
        else
            i++;
    }
    //cout <<endl;
    return ans;
}

        
int main(void)
{
    printf("Hello, This is getMax(j-i) where arr[j] > arr[i]\n");
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Brute force answer for this problem is " << brute_force_soln(arr, size) << endl;
    cout << "Optimized answer for this problem is " << optimized_solution(arr, size) << endl;

    int arr1[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    cout << "Brute force answer for this problem is " << brute_force_soln(arr1, size1) << endl;
    cout << "Optimized answer for this problem is " << optimized_solution(arr1, size1) << endl;
    return 0;
}
