#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>

#define MAX     100

using namespace std;
class Stack
{
    private:
        int topOfStack;
        int arr[MAX];

    public:
        Stack()
        {
            topOfStack = -1;
        }
        void push(int data)
        {
            if(topOfStack == MAX-1)
            {
                cout<<"Size of Stack is Full"<<endl;
                return;
            }
            arr[++topOfStack] = data;    
        }

        int pop()
        {
            int data = arr[topOfStack--];
            return data;
        }

        int top()
        {
            return arr[topOfStack];
        }
        
        int size()
        {
            return topOfStack;
        }

        void printStack()
        {
            int i = topOfStack;

            while(i != -1)
            {
                cout<<arr[i]<<" " ;
                i--;
            }
            cout<<endl;
        }
};

class Queue{
    private:
        int frontOfQueue;
        int rearOfQueue;
        int arr[MAX];

    public:
        Queue()
        {
            frontOfQueue = -1;
            rearOfQueue = -1;
        }

        void push(int data)
        {
            if(rearOfQueue == MAX)
            {
                cout<<"Queue is Full"<<endl;
                return;
            } 
            arr[++rearOfQueue] = data;
            if(frontOfQueue == -1)
                frontOfQueue = 0;
        } 

        int remove()
        {
            if (frontOfQueue > rearOfQueue)
            {
                cout<<"Queue is empty!"<<endl;
                return -1;
            }
            cout<<"Removing "<<arr[frontOfQueue]<<endl;
            return arr[frontOfQueue++];
        }

        int front()
        {
            return arr[frontOfQueue];
        }

        int size()
        {
            return frontOfQueue;
        }

        void printQueue()
        {
            int i = rearOfQueue;

            while(i >= frontOfQueue)
            {
                cout<<arr[i]<<" " ;
                i--;
            }
            cout<<endl;
        }
};

int main()
{
    cout<<"Welcome to Stack & Queue"<<endl;

/*    Stack s;
    s.push(10);
    s.push(5);
    s.push(50);
    s.push(15);
    s.push(12);
    
    s.printStack();
    cout<<"top is "<<s.top()<<endl;
    cout<<s.pop()<<endl<<s.pop()<<endl;

    s.printStack();
*/
    Queue q;
    q.push(10);
    q.push(5);
    q.push(50);
    q.push(15);
    q.push(12);

    q.printQueue();
    cout<<"Front is "<<q.front()<<endl;
    q.remove();
    q.remove();
    
        q.remove();
            q.remove();
    q.remove();
        q.remove();
            q.remove();
    q.printQueue();

    return 0;
}
