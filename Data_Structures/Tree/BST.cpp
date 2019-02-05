#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#define MAX     100

using namespace std;

class Node{

    private:
       int data;
    public:
        Node *left;
        Node *right;

    public: 
        int getData()
        {
            return this->data;
        }

       void setData(int d)
       {
            this->data = d;
       } 
};

class Tree{
    public:
        Node *head;
        int size;
    
    void addNode(int d)
    {
        Node *newnode = new Node();
        
        newnode->setData(d);
        newnode->left = NULL;
        newnode->right = NULL;

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        Node *prev = head;
        Node *temp = head;

        while(temp!=NULL)
        {
            prev = temp;
            if(temp->getData() > d)
                temp = temp->left;
            else 
                temp = temp->right;
        }
        
        if(prev->getData() > d)
            prev->left = newnode;
        else
            prev->right = newnode;
    }
    
    bool searchNOde(int d)
    {
        Node *prev = head;
        Node *temp = head;

        while(temp!=NULL)
        {
            prev = temp;
            if(temp->getData() > d)
                temp = temp->left;
            else if(temp->getData() < d)
                temp = temp->right;
            else
            {
                cout<<"Found node "<<d<<endl;   
                return true;
            }
        }
        return false;
    }

    bool deleteNode(int d)
    {
        return false;
    }

    void inOrderTraversal()
    {
        inOrder(head);
        cout<<endl;;
    }

    private:
    void inOrder(Node *n)
    {
        if(n == NULL)
            return;
        inOrder(n->left);
        cout<<n->getData()<<" ";
        inOrder(n->right);
    }
};


int main()
{
    cout<<"Welcome to BST"<<endl;

    Tree t;
    t.addNode(100);
    t.addNode(50);
    t.addNode(150);
    t.addNode(400);
    t.addNode(70);
    t.addNode(130);
    t.addNode(180);
    t.inOrderTraversal();
    
    return 0;
}
