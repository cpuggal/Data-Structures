// https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
// Input : 
// Output : 
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG	0	
#define SIZE	10	
using namespace std;

class node{
	public :
		int data;
		node *left;
		node *right;
};

class Tree {
	public:
		node *root;
		Tree(int val) 
		{
			root = newNode(val);
		}
		
		node *newNode(int val)
		{
			node *new_node = new node();
			new_node->data = val;
			new_node->left = NULL;
			new_node->right = NULL;
			return new_node;
		}
		
		node *getRoot()
		{
			return root;
		}
		
		void PrintInOrder()
		{
			PrintInOrder_Rec(root);
			cout << endl;
		}
		
		void binaryTreeToBST()
		{
			int size = getSize(root);
			int arr[SIZE] = {0};
			int index = 0;
			binaryTreeToArr(arr, 100, &index, root);
			
			if (DEBUG)
				printArr(arr, SIZE);
			sort(arr, arr+size);
			index = 0;
			
			if (DEBUG)
				cout << SIZE << " " << size << " " << index << endl;

			if (DEBUG)
				printArr(arr, SIZE);

			arrToBST(arr, 100, &index, root);
		}
		
	private:
		void PrintInOrder_Rec(node *root)
		{
			if (NULL == root)
				return;
			
			PrintInOrder_Rec(root->left);
			cout << root->data << " ";
			PrintInOrder_Rec(root->right);
		}
		
		void binaryTreeToArr(int arr[], int size, int *index, node *root)
		{
			if(root == NULL)	
				return;

			if (root->left != NULL)
				binaryTreeToArr(arr, size, index, root->left);
			
			arr[*index] = root->data;
			(*index) ++;
			
			if (root->right != NULL)
				binaryTreeToArr(arr, size, index, root->right);
		}
		
		void arrToBST(int arr[], int size, int *index, node *root)
		{
			if(root == NULL)
				return;
			
			arrToBST(arr, size, index, root->left);
			root->data = arr[*index];
			(*index)++;
			arrToBST(arr, size, index, root->right);
		}
		
		int getSize(node *root)
		{
			if (root == NULL)
				return 0;
			
			return getSize(root->left) + getSize(root->right) + 1;
		}
		
		void printArr(int arr[], int size)
		{
			int i;
			
			for(i = 0; i < size; i++)
				cout << arr[i] << " ";
			
			cout << endl;
		}
	
};

int main() {
	// your code goes here
	Tree tree(10);
	node *root = tree.getRoot();
	root->left = tree.newNode(30); 
    root->right = tree.newNode(15); 
    root->left->left = tree.newNode(20); 
    root->right->right = tree.newNode(5);

    tree.PrintInOrder();
    tree.binaryTreeToBST();
    tree.PrintInOrder();
	return 0;
}