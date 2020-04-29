// https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
// 
// 
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

node *newnode(int val)
{
	node *new_node = new node();
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;	
	
	return new_node;
}

void printPath_rec(node *root, string str)
{
	if (NULL == root)
		return;
		
	if ((NULL == root->left) && (NULL == root->right))
	{
		if(DEBUG)
			cout << "DEBUG: " << root->data << " " << str.length() << endl;
	
		cout << str << root->data << endl;
		return;
	}
	
	int len = str.length();
	string c = to_string(root->data);
	
	if(DEBUG)
		cout << "DEBUG: " << root->data << " " << str.length() << " " << c << endl;
		
	//str.push_back(c);
	str = str + c + ' ';
	//str.push_back(' ');
	
	printPath_rec(root->left, str);
	printPath_rec(root->right, str);
	
	str = str.substr(0, len);
}

void printPaths(node *root)
{
	if (root == NULL)
		return;
	
	string str;
	
	printPath_rec(root, str);
}

int main()  
{  
      
    /* Constructed binary tree is  
                10  
            / \  
            8 2  
        / \ /  
        3 5 2  
    */
    node *root = newnode(10);  
    root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);  
    root->right->left = newnode(2);  
      
    printPaths(root);  
    return 0;  
}  
  
