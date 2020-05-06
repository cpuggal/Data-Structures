// https://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/ 
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	
#define fo(i,n)		for(i = 0; i < n; i++)

using namespace std;

class Node 
{ 
	public: 
	int data; 
	Node *left, *right; 
}; 

Node *head = NULL; 
Node *tail = NULL; 

// Utility function for allocating node for Binary Tree. 
Node* newNode(int data) 
{ 
	Node* node = new Node(); 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

// Utility function for printing tree in In-Order. 
void print(Node *root) 
{ 
	if (root != NULL) 
	{ 
		print(root->left); 
		cout<<root->data<<" "; 
		print(root->right); 
	} 
} 

// Utility function for printing double linked list. 
void printList(Node *head) 
{ 
	while (head) 
	{ 
		cout<<head->data<<" "; 
		head = head->right; 
	} 
} 

Node *extractLeafList(Node *root)
{
	if(NULL == root)
		return NULL;
	
	if((root->left == NULL) && (root->right == NULL))
	{
		if(head == NULL)
		{
			head = root;
			tail = root;
		}
		else
		{
			tail->right = root;
			root->left = tail;
			tail = root;
		}
		return NULL;
	}
	else
	{
		root->left = extractLeafList(root->left);
		root->right = extractLeafList(root->right);
		return root;
	}
}

int main() 
{ 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 
	root->left->left->left = newNode(7); 
	root->left->left->right = newNode(8); 
	root->right->right->left = newNode(9); 
	root->right->right->right = newNode(10); 

	cout << "Inorder Trvaersal of given Tree is:\n"; 
	print(root); 

	root = extractLeafList(root); 

	cout << "\nExtracted Double Linked list is:\n"; 
	printList(head); 

	cout << "\nInorder traversal of modified tree is:\n"; 
	print(root); 
	cout << endl;
	return 0; 
} 

// This code is contributed by rathbhupendra 

