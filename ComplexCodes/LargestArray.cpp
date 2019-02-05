/**
 * https://www.interviewbit.com/problems/wave-array/
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>

using namespace std;

int findLen(int a)
{
    int len = 1;
    while (a/10!=0)
    {
        a = a/10;
        len++;
    }
    
    return len;
}

char* largestNumber(const int* A, int n1) 
{
    int i;
    int prev = A[0];
    int l1,l2;
    int a1, a2;

    for(i=1;i<n1;i++)
    {
        l1 = findLen(prev);
        l2 = findLen(A[i]);
        
       cout<<"l1 "<<l1<<" l2 "<<l2<<endl;
        
       if (prev < A[i])
       {
            a1 = pow(10,l1+l2-1) * prev + A[i];
            a2 = pow(10,l1+l2-1) * A[i] + prev;
       }
               cout<<"a1 "<<a1<<" a2 "<<a2<<endl;

        if (a1 > a2)
            prev = a1;
        else
            prev = a2;

        cout<<prev<<endl;
    }
    
    printf("%d\n", prev);
    
    return (char*)prev;
}



int main()
{
    cout<<"***** Welcome to wave creator *****"<<endl;
    int Arr[] = {1,2,3,4};
    int s;
    largestNumber(Arr,4);
    return 0;

}
