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
};

class MinHeap
{
    private:
        HeapNode *arr;
        int size;
        int curr_idx;

    public: 
        MinHeap(int size)
        {
            this->size = size;
            arr = new HeapNode[size];
            curr_idx = 0;

            int i = 0;

            for (i = 0; i < MAX; i++)
               arr[i].setData(-1); 
        }
        
        int getValue(int i)
        {
            return arr[i].getData();
        }
        
        int parent(int idx)
        {
             return (idx-1)/2;
            //return arr[i].getData();
        }

        int leftChild(int idx)
        {
            return idx*2+1;
            //return arr[i].getData();        
        }

        int rightChild(int idx)
        {
            return idx*2+2;
            //return arr[i].getData();
        }
        void swap(int i, int j)
        {
            int t1 = arr[i].getData();
            int t2 = arr[j].getData();

            arr[i].setData(t2);
            arr[j].setData(t1);        
        }

        void insert(int val)
        {
            arr[curr_idx++].setData(val);

            int i = curr_idx-1;
            //cout<<i<<" "<<getValue;
            while ((i >= 0) && (getValue(parent(i)) > getValue(i)))
            {
#if DEBUG
               cout<<"i is "<< i<<" with value "<<getValue(i)<<" and parent(i) is "<<getValue(parent(i))<<endl; 

#endif
                swap(i,parent(i));
                i = parent(i);
            }
        }
        
        void printMinHeap()
        {
            int i = 0;
            cout<<"Min Heap is ";
            for (i=0; i<curr_idx;i++)
                cout<<arr[i].getData()<<" ";

            cout<<endl;

        }
};

int main(void)
{
    printf("Hello, This is Heap Impl!\n");
    MinHeap h(100);

    h.insert(10);
    h.insert(1);
    h.insert(150);
    h.insert(20);
    h.insert(100);    
    h.insert(0);

    h.printMinHeap();

    return 0;
}
//        1
//    10       100      
//20              150
