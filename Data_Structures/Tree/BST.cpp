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

    void spiralViewOfTree()
    {
        cout<<"spiralView of Tree is "<<endl;
        spiralView(head);
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

    void spiralView(Node *head)
    {
        //head push                 1
        // level  =1
        // push(r,l))           3       2
        // rev                  2       3
        // 2, 3 ->push(l,r)            4   5       7
        // rev              7   5       4
        // 7 5 4 push(r,l))  8   9  10  
        // rev              10 9 8 
        //

        Node *Queue[MAX];
        Node *dummy = new Node();
        dummy->setData(-1);

        Queue[0] = head;
        Queue[1] = dummy;

        Node *temp = head;
        int level = 1; // Head is at level 1
        int curr_index = 0;
        int push_index = 1;
        
        cout<<endl<<"******* Level "<<level<<" *********"<<endl;
        while(temp != NULL) 
        {            
            temp = Queue[curr_index];
            
            if (curr_index == push_index)//Queue[curr_index]->getData() == Queue[curr_index+1]->getData())
                break;

            if (temp->getData() == -1)
            {

                int i = curr_index+1;
                int j = push_index;
                Node  *t;
               
                while(i<=j)
                {
                    t = Queue[i];
                    Queue[i] = Queue[j];
                    Queue[j] = t;
                    i++; j--;
                }
                curr_index++;
                Queue[++push_index] = dummy;
                level++;
                cout<<endl<<"******* Level "<<level<<" *********"<<endl;
                continue;
            }
            
            cout<<"\t"<<temp->getData()<<" ";
            
            if (level%2 == 0)
            {
                if (temp->left!=NULL)
                    Queue[++push_index] = temp->left;
                if (temp->right!=NULL)                
                    Queue[++push_index] = temp->right;            
            }
            else
            {
                if (temp->right!=NULL)                
                    Queue[++push_index] = temp->right;
                if (temp->left!=NULL)                
                    Queue[++push_index] = temp->left;            
            }
            curr_index++; 
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

    t.spiralViewOfTree();
    return 0;
}
