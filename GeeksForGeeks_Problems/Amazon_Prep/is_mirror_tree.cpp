// https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/
//

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

struct Node 
{ 
    int data; 
    Node* left, *right; 
}; 

Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data  = data; 
    node->left  =  node->right  = NULL; 
    return(node); 
} 

bool areMirror(Node *t1, Node *t2)
{
	if ((t1 == NULL) && (t2 == NULL)) // both tree's reached their leaf's : true
		return true;

	if ((t1 == NULL) || (t2 == NULL)) // one have a branch (non-null val) and other tree doesn't : Failure
		return false;

	if ((t1->data == t2->data) && 
	    (areMirror(t1->left, t2->right)) && 
	    (areMirror(t1->right, t2->left)))
	{
		return true;
	}
	else
		return false;
}

int main() 
{ 
    Node *a = newNode(1); 
    Node *b = newNode(1);
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
//    a->left->left->left  = newNode(40); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 
//    b->right->right->right = newNode(40); 

  
    areMirror(a, b)? cout << "Yes" : cout << "No"; 
    cout << endl;
    return 0; 
} 
