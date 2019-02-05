#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#define MAX     100

using namespace std;



void printArr(int a[], int sz)
{
    int i = 0;

    for (i=0; i<sz; i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

void heapify(int a[]

void heapSort(int a[], int sz)
{




}


int main()
{
    cout<<"Welcome to HeapSort "<<endl;
    int arr[] = {10,9,5, 14,1,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, size);

    heapSort(arr, size);
    printArr(arr, size);
    return 0;
}
