#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Node {
    private:
        int data;
        Node *next;

    public:
        void setData(int d)
        {
        	cout<<"[Node][setData] value"<<d<<endl;
            this->data = d;
        }

        void setNextElement(Node *n)
        {
            this->next = n;
            cout<<"[Node][SetNextElem] value "<<n<<endl;
        }
        int getData()
        {
        	cout<<"[Node][getData] value "<<this->data<<endl;
            return this->data;
        }

        Node *getNextElement()
        {
        	cout<<"[Node][getNextElement] value "<<this->next<<endl;
            return this->next;
        }
};

class LinkedList {
    private:
        int size;
        static LinkedList *list;
        Node *head;

        LinkedList() //Constructor
        {
            this->size = 0;
            this->head = NULL;
        }

    public:
        static LinkedList *getInstance()
        {
            if(list != NULL)
                return list;        
            else
             {
                list = new LinkedList();
                return list;
            }
        }

        int getSize()
        {
        	cout<<"[LinkedList][getSize] value"<<this->size<<endl;
            return this->size;
        }

        void addNode(int value)
        {
            Node *newnode = new Node();
            newnode->setData(value);
            newnode->setNextElement(NULL);
			cout<<"[LinkedList] Adding node "<<value<<endl;
			
            if (this->size == 0)
                list->head = newnode;
            else
            {
                newnode->setNextElement(list->head);
                list->head = newnode;
            }

            this->size++;
        }

        bool Search(int value)
        {
            if(this->size == 0)
            {
                cout<<"[LinkedList][Search] List is empty "<<endl;
                return false;
            }

            Node *temp = list->head;

            while(temp!=NULL)
            {
                if (temp->getData() == value)
                {
                    cout<<"[LinkedList][Search] Value "<<value <<" is present in list"<<endl;
                    return true;
                }
                temp = temp->getNextElement();
            }
            cout<<"[LinkedList][Search] Value "<<value <<" is absent in list"<<endl;
            return false;
        }
};

LinkedList *LinkedList::list = NULL;

int main()
{
    cout<<"***** Welcome to Class based Linked List *****"<<endl;
    LinkedList *ll = LinkedList::getInstance();
    ll->addNode(10);
    ll->addNode(5);
    ll->Search(9);
    ll->Search(10);

    return 0;
}
