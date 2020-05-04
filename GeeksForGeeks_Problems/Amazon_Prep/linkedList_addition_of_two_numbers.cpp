// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

/* Linked list node */
class Node 
{ 
	public: 
	int data; 
	Node* next; 
}; 

/* Function to create a new node with given data */
Node *newNode(int data) 
{ 
	Node *new_node = new Node(); 
	new_node->data = data; 
	new_node->next = NULL; 
	return new_node; 
} 

/* Function to insert a node at the 
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = newNode(new_data); 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Adds contents of two linked lists and 
return the head node of resultant list */
Node* addTwoLists (Node* first, Node* second) 
{ 
	if ((first == NULL) && (second == NULL))
		return NULL;
	
	if (first == NULL)
		return second;
	
	if (second == NULL)
		return first;
	
	Node *result = NULL;
	int carry = 0;
	int sum = 0;
	Node *temp = NULL;
	Node *prev = NULL;
	
	while((first != NULL) || (second != NULL))
	{
		if(first != NULL)
		{	
			sum += first->data;
			first = first->next;
		}
		
		if(second != NULL)
		{	
			sum += second->data;
			second = second->next;
		}
		
		if(carry == 1)
		{
			sum += 1;
			carry = 0;
		}
		
		if (sum >= 10)
		{
			sum = sum - 10;
			carry = 1;
		}
		push(&temp, sum); 
		
		if(result == NULL)
		{
			result = temp;
			prev = temp;
		}
		else
		{
			prev->next = temp;
			prev = prev->next;
		}
		temp = NULL;
		sum = 0;
	}
	return result;
} 

// A utility function to print a linked list 
void printList(Node *node) 
{ 
	while(node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout<<endl; 
} 

/* Driver code */
int main(void) 
{ 
	Node* res = NULL; 
	Node* first = NULL; 
	Node* second = NULL; 

	// create first list 7->5->9->4->6 
	push(&first, 6); 
	push(&first, 4); 
	push(&first, 9); 
	push(&first, 5); 
	push(&first, 7); 
	printf("First List is "); 
	printList(first); 

	// create second list 8->4 
	push(&second, 4); 
	push(&second, 8); 
	cout<<"Second List is "; 
	printList(second); 

	// Add the two lists and see result 
	res = addTwoLists(first, second); 
	cout<<"Resultant list is "; 
	printList(res); 

return 0; 
} 


