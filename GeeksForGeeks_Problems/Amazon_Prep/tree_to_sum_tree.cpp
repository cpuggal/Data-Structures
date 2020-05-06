//https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/// 
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

int toSumTree(Node *root)
{
	if(NULL == root)
		return 0;
	
	if((root->left == NULL) && (root->right == NULL))
	{
		root->data = 0;
		return root->data;
	}
	else
	{
		int left = 0, right = 0, sum = 0;
		int curr_data = root->data;
		if(root->left != NULL)
			left = root->left->data;
		
		if(root->right != NULL)
			right = root->right->data;
			
		sum = left + right + toSumTree(root->left) + toSumTree(root->right);
		root->data = sum;
		return root->data;
	}
}

int main() 
{ 
	Node *root; 
	root = newNode(10);  
    root->left = newNode(-2);  
    root->right = newNode(6);  
    root->left->left = newNode(8);  
    root->left->right = newNode(-4);  
    root->right->left = newNode(7);  
    root->right->right = newNode(5);  

	cout << "Inorder Before: ";
	print(root);
	cout << endl;
    
    toSumTree(root);  

	cout << "Inorder After: ";
	print(root);
	cout << endl;
	return 0; 
} 


