// https://www.geeksforgeeks.org/level-order-tree-traversal/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

class QNode{
	public:
		int data;
		QNode *next;
};

class Queue{
	public:
		QNode *rear;
		QNode *front;
	public:
		Queue()
		{
			rear = NULL;
			front = NULL;
		}
		QNode *newNode(int val)
		{
			QNode * new_node = new QNode();
			new_node->data = val;
			new_node->next = NULL;
			return new_node;
		}
		
		void enQueue(int val)
		{
			QNode *new_node = newNode(val);
			if (front == NULL)
			{
				if (DEBUG)
					cout << "enQueue : Empty Queue already " << endl;

				front = new_node;
				rear = new_node;
			}
			else
			{
				rear->next = new_node;
				rear = rear->next;
			}
		}
		int deQueue()
		{
			if (front == NULL)
			{
				if (DEBUG)
					cout << "deQueue: Empty Queue already " << endl;

				return -1;
			}
			else
			{
				int val = front->data;
				QNode *temp = front;
				front = front->next;
				delete temp;
				
				return val;
			}
		}
};

int main() 
{ 
    Queue q; 
    q.enQueue(10); 
    q.enQueue(20); 
    q.deQueue(); 
    q.deQueue(); 
    q.enQueue(30); 
    q.enQueue(40); 
    q.enQueue(50); 
    cout << "Queue Front : " << (q.front)->data << endl; 
    cout << "Queue Rear : " << (q.rear)->data << endl; 
} 
