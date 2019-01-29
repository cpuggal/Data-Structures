#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *addNode(Node *head, int data)
{
    Node *newnode = (Node*) malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if(head != NULL)
        newnode->next = head; //Add new node in front
    
    return newnode;
}

bool Search(Node *head, int data)
{
    if(!head)
        return false;

    while(head != NULL)
    {
	if(head->data == data)
	    return true;
	
	head = head->next;
    }
    return false;
}

void printList(Node *head)
{
    if(!head)
        printf("List is empty\n");
    else
    {
        while(head!=NULL)
        {
            printf("%d -> ",head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

int main(void)
{
    printf("Hello, This is LinkedList Impl!\n");
    Node *head = NULL;

    head = addNode(head, 10);  
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    printList(head);

    if(Search(head, 10))
        printf("10 is present\n");
    else
        printf("10 is absent\n");

    if(Search(head, 50))
        printf("50 is present\n");
    else
        printf("50 is absent\n");

    return 0;
}
