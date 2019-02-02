#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#define MAX     100

using namespace std;

void merge(int Arr[], int l, int m, int r)
{
    int i,j,k;

    int L[MAX], R[MAX];
    int n1 = m - l + 1;
    int n2 = r - m;
    for (i=0; i<n1; i++)
        L[i] = Arr[l+i];

    for (j = 0; j < n2; j++)
        R[j] = Arr[m+1+j];
    
    i = 0;
    j = 0;
    k = l;
    
    while ((i<n1) && (j<n2))
    {
        if (L[i] < R[j])
        {
            Arr[k] = L[i];
            i++;
        }
        else
        {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        Arr[k] = L[i];
        i++; k++;
    }

    while (j < n2)
    {
        Arr[k] = R[j];
        j++; k++;
    }
}

void mergesort(int Arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2;

        mergesort(Arr, l, m);
        mergesort(Arr, m+1, r);
        
        merge(Arr,l,m,r);
    }

}

void printArr(int Arr[], int size)
{
    int i=0;
//    cout<<"Printer"<<endl;    
    for(i=0;i<size;i++)
        cout<<Arr[i]<<" ";

    cout<<endl;
}

int main()
{
    cout<<"***** Welcome to Merge Sort *****"<<endl;
    
    int Arr[ ] = {100, 29, 10, 5, 12, 1, 19};
    //cout<<"Should work"<<endl;
    int sz = sizeof(Arr)/sizeof(int);

    printArr(Arr,sz);
    //   cout<<"Should work"<<endl; 
    mergesort(Arr, 0, sz-1);
    
    printArr(Arr,sz);
    cout<<"Ends here"<<endl;
    return 0;
}
