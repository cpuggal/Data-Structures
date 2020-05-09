// https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	

using namespace std;

class Node 
{ 
	public: 
	int data; 
	Node *next; 
}; 

/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(Node *head) 
{ 
	Node *temp = head; 
	while (temp != NULL) 
	{ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
	cout<<endl; 
} 

void skipMdeleteN(Node *head, int M, int N) 
{
	if(head == NULL)
		return;
	
	if(N == 0) // no deletion required.
		return;
	
	int m_count = 0, n_count = 0;
	Node *curr = head;
	Node *prev = head;
	Node *temp = head;
	
	while(curr != NULL)
	{
		if(m_count == M)
		{
			if(n_count == N)
			{
				m_count = 0;
				n_count = 0;
			}
			else
			{
				temp = curr;
				curr = curr->next;
				prev->next = curr;
				delete temp;
				n_count++;
			}
		}
		else
		{
			m_count++;
			prev = curr;
			curr = curr->next;
		}
	}
}

// Driver code 
int main() 
{ 
	/* Create following linked list 
	1->2->3->4->5->6->7->8->9->10 */
	Node* head = NULL; 
	int M=2, N=3; 
	push(&head, 10); 
	push(&head, 9); 
	push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	cout << "M = " << M<< " N = " << N << "\nGiven Linked list is :\n"; 
	printList(head); 

	skipMdeleteN(head, M, N); 

	cout<<"\nLinked list after deletion is :\n"; 
	printList(head); 

	return 0; 
} 



