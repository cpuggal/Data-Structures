#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>

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
        cout<<"InOrder for this Tree :"<<endl;
        inOrder(head);
        cout<<endl;
    }
    
    void leftViewOfTree()
    {
        cout<<"Left view of Tree is : " <<endl;
        leftView(head);
        cout<<endl;
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

    void leftView(Node *temp)
    {
        if (temp == NULL)
            return;

        Node *arr[100];
        Node *dummy = new Node();
        dummy->setData(-1);
        dummy->left = NULL;
        dummy->right = NULL;

        arr[0] = temp;
        arr[1] = dummy;
        int i = 0;;
        int n = 2;
        
        cout<<temp->getData()<<" "<<endl;
        
        Node *curr = arr[0];
        while(curr != NULL)
        {
            curr = arr[i];
            if (curr->getData() == -1)
            {
                arr[n++] = dummy;
                if(arr[i+1]->getData() == curr->getData())
                    break;
                cout<<arr[i+1]->getData()<<" "<<endl;
            }
            else
            {
                //cout<<"Adding value for "<<curr->getData()<<endl;
                if(curr->left != NULL)
                    arr[n++] = curr->left;
                if(curr->right != NULL)
                    arr[n++] = curr->right;
            }
     //       cout<<i<<" "<<endl;
            i++;
        }
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
    //usleep(100000);
    t.leftViewOfTree(); 
    return 0;
}
