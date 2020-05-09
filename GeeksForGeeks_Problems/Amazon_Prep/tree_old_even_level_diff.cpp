// https://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	

using namespace std;

struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// returns a new 
// tree Node 
Node* newNode(int data) 
{ 
	Node* temp = new Node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Chandan
int evenOddLevelDifference(Node* root) 
{ 
	if(NULL == root)
		return 0;
	
	int oddSum = 0, evenSum = 0, level = 1;
	Node *delim = NULL;
	Node* temp;
	queue<Node *> myQ;
	
	myQ.push(root);
	myQ.push(delim);
	
	while(!myQ.empty())
	{
		temp = myQ.front();
		myQ.pop();
		
		if(temp == delim)
		{
			level++;
			
			if(myQ.empty())
				break;
			else
				myQ.push(delim);
		}
		else
		{
			if(level % 2 == 1) // odd level
				oddSum += temp->data;
			else
				evenSum += temp->data;
				
			if(temp->left != NULL)
				myQ.push(temp->left);	
	
			if(temp->right != NULL)
				myQ.push(temp->right);		
		}
	}
	return (oddSum - evenSum);
} 


// Approach : 2

void evenOddLevelDifference_rec_int(Node* root, int level, int *odd, int *even)
{
	if(level % 2 == 1) // odd level
		*odd += root->data;
	else
		*even += root->data;
	
	if(root->left != NULL)
		evenOddLevelDifference_rec_int(root->left, level + 1, odd, even);

	if(root->right != NULL)
		evenOddLevelDifference_rec_int(root->right, level + 1, odd, even);
}

int evenOddLevelDifference_rec(Node* root)
{
	if(root == NULL)
		return 0;
	int odd = 0, even = 0, level = 1;
	
	evenOddLevelDifference_rec_int(root, level, &odd, &even);
	return (odd - even);
}

// driver program 
int main() 
{ 
	// construct a tree 
	Node* root = newNode(5); 
	root->left = newNode(2); 
	root->right = newNode(6); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 
	root->left->right->left = newNode(3); 
	root->right->right = newNode(8); 
	root->right->right->right = newNode(9); 
	root->right->right->left = newNode(7); 

	auto start = std::chrono::system_clock::now();
	cout << "diffence between sums is :: " << evenOddLevelDifference(root) << endl; 
	auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;	
	cout << "evenOddLevelDifference time: " << elapsed_seconds.count() << endl;
	
	start = std::chrono::system_clock::now();    
	cout << "diffence between sums is :: " << evenOddLevelDifference_rec(root) << endl; 
	end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;	
    cout << "evenOddLevelDifference_rec time: " << elapsed_seconds.count() << endl;
	
	return 0; 
} 

