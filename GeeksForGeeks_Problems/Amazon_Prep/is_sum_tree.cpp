//  https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node* right;
};

struct node* newNode(int data) 
{ 
    struct node* node = 
        (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
}

int isSumTree(node *root)
{
	if (root == NULL)
		return 0;
	
	int left = isSumTree(root->left);
	int right = isSumTree(root->right);
	
	if ((left == 0) && (right == 0))
		return root->data;

	else if ((left == -1) || (right == -1))
		return -1;
		
	else if (left != 0 && right != 0)
	{
		if (left + right == root->data)
		{
//			cout << "lr : " << left + right << endl;
			return (2 * root->data);
		}
		else
		{
//			cout << "-1 between for : " << root->data << endl;
			return -1;
		}
	}
	else if ((left) && (left == root->data))
	{
//		cout << "l: " << left << endl;
		return (2 * root->data);
	}
	else if ((right) && (right == root->data))
	{
//		cout << "r: " << right << endl;
		return (2 * root->data);
	}
	else
	{
//		cout << "-1 last for : " << root->data << endl;
		return -1;
	}
}

bool isLeaf(node *root)
{
	if ((root->left == NULL) && (root->right == NULL))
		return true;
	else
		return false;
}

bool isSumTree_Bool(node * root)
{
	if ((root == NULL) || isLeaf(root)) // last node or leaf node are good to recur
		return true;

	if (isSumTree_Bool(root->left) && isSumTree_Bool(root->right))
	{
		int left = 0, right = 0;

		if ((root->left) && (isLeaf(root->left)))
			left = root->left->data;
		else if (root->left)
			left = 2 * root->left->data;
		else 
			left = 0;

		if ((root->right) && (isLeaf(root->right)))
			right = root->right->data;
		else if (root->right)
			right = 2 * root->right->data;
		else 
			right = 0;

		if (left + right == root->data)
			return true;
		else
			return false;
	}
	return false;
}

int main() 
{ 
    struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    
    if(isSumTree(root) != -1) 
        cout << "The given tree is a SumTree " << endl; 
    else
        cout << "The given tree is not a SumTree " << endl; 
	
	cout << "Boolean Logic: " << endl;
    
    if(isSumTree_Bool(root)) 
        cout << "The given tree is a SumTree " << endl; 
    else
        cout << "The given tree is not a SumTree " << endl; 

    return 0; 
}  