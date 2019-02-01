

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

using namespace std;

int* wave(int* A, int n1, int *len1) {
    int *ans = (int*)malloc(sizeof(int)*n1);
    *len1 = n1;
    
    int i=0;
    int prev, now, next;
    prev = -99999999;
    now = A[0];
    next = A[1];
    int state = 1; //1 - bigger both side and 2 - smaller both side
    for(i=0;i<n1-1;i++)
    {
        now = A[i];
        next = A[i+1];
        
        if (state == 1)
        {
            if (now < next)
            {
                A[i] = next;
                A[i+1] = now;
                
                now = A[i];
                next = A[i+1];
                if(prev < now)
                {    
                    state = 2;
                }
            }
            
            else if ((now>=prev) && (now >= next))
                state = 2;
        }
        else //
        {
            if (now > next)
            {
                A[i] = next;
                A[i+1] = now;
                now = A[i];
                next = A[i+1];
                
                if(prev > now)
                    state = 1;
            }
           
            state = 1;
        }
        
        prev = A[i]; 
    }
    
    return A;    
}
int main()
{
    cout<<"***** Welcome to Class based Linked List *****"<<endl;
    int Arr[] = {1,2,3,4};
    int s;
    int *answer = wave(Arr, 4, &s);
    int i = 0;
    for(i=0;i<s;i++)
    {
        cout<<answer[i]<<endl;
    }
    return 0;
}
