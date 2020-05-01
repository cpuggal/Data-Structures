// https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

struct Node  
{  
    int data;  
    struct Node* next;  
};  

void push(struct Node** head_ref, int new_data)  
{  
    /* allocate node */
    struct Node* new_node =  
        (struct Node*) malloc(sizeof(struct Node));  
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
// A utility function to print a given linked list  
void printList(struct Node *ptr)  
{  
    while (ptr != NULL)  
    {  
        printf("%d->", ptr->data);  
        ptr = ptr->next;  
    }  
    printf("NULL\n");  
}  

void printMiddle(struct Node* head)
{
	if(head == NULL)
		return;
	struct Node* slow = head;
	struct Node* fast = head;
	
	while((fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	cout << "Value is " << slow->data << endl;
}
int main()  
{  
    /* Start with the empty list */
    struct Node* head = NULL;  
    int i;  
  
    for (i=5; i>0; i--)  
    {  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
    return 0;  
}
