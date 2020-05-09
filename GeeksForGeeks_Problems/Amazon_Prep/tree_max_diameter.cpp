// https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	

using namespace std;

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left, *right; 
}; 

/* function to create a new node of tree and returns pointer */
struct node* newNode(int data); 

/* returns max of two integers */
int max(int a, int b); 

/* function to Compute height of a tree. */
int height(struct node* node); 

int diameter_int(struct node * root, int *globalMax) 
{ 
	if(root == NULL)
		return 0;
	
	if ((root->left == NULL) && (root->right == NULL))
		return 1;
		
	int l = diameter_int(root->left, globalMax);
	int r = diameter_int(root->right, globalMax);
	int localMax = max(l, r);
	*globalMax = max(*globalMax, l + r + 1);
	
	if(DEBUG)
		cout << "data: "<< root->data << ", Max: " << *globalMax << endl;
	
	return localMax + 1;
} 

int diameter(struct node* root)
{
	int globalMax = 0;
	diameter_int(root, &globalMax);
	return globalMax;
}

/* UTILITY FUNCTIONS TO TEST diameter() FUNCTION */

/* The function Compute the "height" of a tree. Height is the 
	number f nodes along the longest path from the root node 
	down to the farthest leaf node.*/
int height(struct node* node) 
{ 
/* base case tree is empty */
if(node == NULL) 
	return 0; 

/* If tree is not empty then height = 1 + max of left 
	height and right heights */	
return 1 + max(height(node->left), height(node->right)); 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
struct node* node = (struct node*) 
					malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 

return(node); 
} 

/* returns maximum of two integers */
int max(int a, int b) 
{ 
return (a >= b)? a: b; 
}	 

/* Driver program to test above functions*/
int main() 
{ 

/* Constructed binary tree is 
			1 
		/ \ 
		2	 3 
	/ \ 
	4	 5 
*/
struct node *root = newNode(1); 
root->left	 = newNode(2); 
root->right	 = newNode(3); 
root->left->left = newNode(4); 
root->left->right = newNode(5); 
int res = diameter(root);

cout << "Diameter of the given binary tree is : " << res << endl; 

return 0; 
}