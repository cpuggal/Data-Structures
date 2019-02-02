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



/**
 * https://www.interviewbit.com/problems/wave-array/
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
    int j; 
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int* wave(int* A, int n1, int *len1) {
    int *ans = (int*)malloc(sizeof(int)*n1);
    *len1 = n1;
    
    quickSort(A,0,n1-1);
    
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
    cout<<"***** Welcome to wave creator *****"<<endl;
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
