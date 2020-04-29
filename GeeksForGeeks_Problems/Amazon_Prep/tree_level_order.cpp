// https://www.geeksforgeeks.org/level-order-tree-traversal/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

class node {
	public:
		int data;
		node *left;
		node *right;
};

node *newNode(int val)
{
	node *new_node = new node();
	new_node->data = val;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void printLevelOrder(node *root)
{
	if (NULL == root)
		return;
	
	queue<node*> treeQueue;
	node *temp;
	
	treeQueue.push(root);
	
	while(!(treeQueue.empty()))
	{
		temp = treeQueue.front();
		cout << temp->data << " ";
		treeQueue.pop();
		
		if (temp->left)
			treeQueue.push(temp->left);
		if (temp->right)
			treeQueue.push(temp->right);
	}
	cout << endl;
}

int main()  
{  
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
  
    cout << "Level Order traversal of binary tree is \n";  
    printLevelOrder(root);  
  
    return 0;  
}
