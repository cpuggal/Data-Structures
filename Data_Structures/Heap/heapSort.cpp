#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define MAX         100
#define DEBUG      0
using namespace std;

class HeapNode
{
    private:
        int data;

    public:
        int getData()
        {
            return this->data;
        }

        void setData(int d)
        {
            this->data = d;
        }

        bool compareFunction(HeapNode x, HeapNode y)
        {
            if (x.getData() > y.getData())
                return true;
            else
                return false;
        }
};

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void MaxHeapify( int arr[], int n, int idx);

void MaxHeapsort(int arr[], int n)
{
    int i = 0;
    
    for (i = n/2 -1; i >= 0; i--)
        MaxHeapify(arr, n, i);

    for (i = n -1; i>=0; i--)
    {
        swap(arr, i, 0);
        MaxHeapify(arr, i, 0);
    }
}

void MaxHeapify(int arr[], int n, int idx)
{
    int l = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if ((left < n) && (arr[left] > arr[l]))
        l = left;

    if ((right <n) && (arr[right] > arr[l]))
        l = right;

    if (l != idx)
    {
        swap(arr, l, idx);
        MaxHeapify(arr, n, l);
    }
}

void MinHeapify(int arr[], int n, int idx);

void MinHeapsort(int arr[], int n)
{
    int i = 0;

    for (i = n/2 -1; i >= 0; i--)
        MinHeapify(arr, n, i);

    for (i = n -1; i>=0; i--)
    {
        swap(arr, i, 0);
        MinHeapify(arr, i, 0);
    }
}

void MinHeapify(int arr[], int n, int idx)
{
    int l = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if ((left < n) && (arr[left] < arr[l]))
        l = left;

    if ((right < n) && (arr[right] < arr[l]))
        l = right;

    if (l != idx)
    {
        swap(arr, l, idx);
        MinHeapify(arr, n, l);
    }
}


void printHeap(int arr[], int n)
        {
            int i = 0;
            cout<<"Heap is : ";
            for (i=0; i<n;i++)
                cout<<arr[i]<<" ";

            cout<<endl;
        }

int main()
{
    cout<<"Welcome to the HeapSort !"<<endl;

    int arr[] = {10, 3, 11, 12, 9, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    MaxHeapsort(arr, size);
    
    cout<<"Max ";
    printHeap(arr,size);

    MinHeapsort(arr, size);
    cout<<"Min ";
    printHeap(arr,size);

    return 1;

}

