// https://www.geeksforgeeks.org/level-order-tree-traversal/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

typedef struct node{
	int data;
	node *left;
	node *right;
};

node * newNode(int val)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = val;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void printSingles(node *root)
{
	if (NULL == root)
		return;
	
	if ((root->left == NULL) && (root->right != NULL))
	{
		cout << root->right->data << " ";
	}
	if ((root->left != NULL) && (root->right == NULL))
	{
		cout << root->left->data << " ";
	}
	
	printSingles(root->left);
	printSingles(root->right);
}

int main() 
{ 
    // Let us create binary tree given in the above example 
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->left->left = newNode(6); 
    printSingles(root);
		cout << endl;
    return 0; 
}
