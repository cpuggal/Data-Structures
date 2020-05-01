// https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  

int maxDepth(node* root)  
{  
    if (NULL == root)
    	return 0;

    if ((root->left == NULL) && (root->right == NULL))
    	return 1;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return max(left, right) + 1;
}  
  
/* Helper function that allocates a new node with the  
given data and NULL left and right pointers. */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  
      
// Driver code     
int main()  
{  
    node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Height of tree is " << maxDepth(root) << endl;  
    return 0;  
}  
