// https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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
		
		void PrintBoundary()
		{
			if (root == NULL)
				return;
			
			queue <node* >myQueue;

			myQueue.push(root);
			myQueue.push(NULL);
			
			stack <node *> myStack;
			
			node *temp = NULL;
			node *prev = NULL;
			
			while(!myQueue.empty())
			{
				temp = myQueue.front();
				myQueue.pop();
				
				if(DEBUG)
				{
					if(temp)
						cout << temp->data << " ";
					else
						cout << "NULL ";
				}
				
				if(myQueue.empty()) // last NULL poped out
					break;
				
				if(temp == NULL)
				{
					myQueue.push(NULL);
					
					if(prev != root)
						myStack.push(prev); // last element of this level
				}
				else
				{
					if (prev == NULL) // first element of this level
						cout << temp->data << " ";
					
					if (temp->left)
						myQueue.push(temp->left);
						
					if (temp->right)
						myQueue.push(temp->right);	
				}
				prev = temp;
			}
			
			if(prev != root)
				myStack.push(prev);
				
			while(!myStack.empty())
			{
				temp = myStack.top();
				cout << temp->data << " ";
				myStack.pop();
			}
			cout << endl;
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
    
// https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

	Tree tree1(20); 
	root = tree1.getRoot();
	
    root->left = tree.newNode(8); 
    root->left->left = tree.newNode(4); 
    root->left->right = tree.newNode(12); 
    root->left->right->left = tree.newNode(10); 
    root->left->right->right = tree.newNode(14); 
    root->right = tree.newNode(22); 
    root->right->right = tree.newNode(25);
    tree1.PrintInOrder();
    tree1.PrintBoundary();
   
	return 0;
}
