#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

#define SIZE        100
#define MAX         1000
#define STL_LRU     0
#define CPP_LRU     1

using namespace std;

#if (STL_LRU)
class LRU
{
    public: 
        list <int> queue;
        map <int, list<int>::iterator> mp;
        int cSize;

        LRU (int size)
        {
            cSize = size;
        }

        void refer(int x)
        {
            if(mp.find(x) == mp.end())
            {
                if(queue.size() == cSize)
                {
                    int back = queue.back();
                    queue.pop_back();
                    mp.erase(back);
                }
            }
            else
                queue.erase(mp[x]); // Present so delete from current position in queue and then add at front

            queue.push_front(x);
            mp[x] = queue.begin();
        }

        void display()
        {
            for (auto it : queue)
            {
                cout << it << " ";
            }
            cout << endl;
        }
};
#endif

#if (CPP_LRU)
class QueueElement
{
    public:
        int data;
        QueueElement *next;
        QueueElement *prev;

        QueueElement(int x)
        {
            data = x;
            next = NULL;
            prev = NULL;
        }
};


class LRUOfC
{
    private:
        QueueElement *head;
        QueueElement *tail;    
        QueueElement *map[MAX];
        int cSize;
        int curr_size;
        
    public:
        LRUOfC(int size)
        {
            cout << "Constructio for LRU" << endl;
            cSize = size;
            curr_size = 0;
            head = NULL;
            tail = NULL;
            
            int i = 0;
            for (i=0; i<MAX; i++)
                map[i] = NULL;
        }
        
    private:     
        QueueElement *addNode(int data)
        {
            QueueElement *temp = new QueueElement(data);
            curr_size++;

            cout << "Adding node" << endl;
            
            if (head == NULL)
            {
                temp->next = NULL;
                temp->prev = NULL;
                head = temp;
                tail = temp;
                return temp;
            }
            temp->next = head;
            head->prev = temp;
            head = temp;

            return temp;
        }
        
        void removeTailFromQueue()
        {
            QueueElement *temp = tail->prev;
            temp->next = tail->next;
            map[tail->data] = NULL;
            
            cout << "removeTailFromQueue and clean Map entry also" << endl;
            delete tail;
            tail = temp;
            curr_size--;
        }

    public:
        void refer(int data)
        {
            QueueElement *temp;
            QueueElement *prev;
            QueueElement *nxt;
            cout << "Refering LRU" << endl;

            if (map[data] == NULL) // If element is missing in Map then add it
            {
                cout << "Not inside Map!" << endl;
                if (cSize == curr_size)
                {
                    //removeMapAndQueue(data);
                    // Remove from Map and Queue
                    removeTailFromQueue();
                }
                temp = addNode(data);
                map[data] = temp;
            }
            else
            {
                cout << "Already in Map" << endl;
                temp = map[data];
                prev = temp->prev;
                nxt = temp->next;
                
                if(prev)
                    prev->next = nxt;
                if(nxt)
                    nxt->prev = prev;
                
                temp->next = head;
                head->prev = temp;
                head = temp; // Point back head as new Node which is referred 

                //free(temp); //Remove last element of Queue
            }
        }
            
            void display_Q()
            {
                QueueElement *temp = head;

                while(temp!= NULL)
                {
                    cout << temp->data << " --> ";
                    temp = temp->next;
                }
                cout << endl;
            }
};
#endif

int main()
{
#if (STL_LRU)
    LRU ca (3);

    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
#endif

#if (CPP_LRU)
    LRUOfC lru(3);
    lru.refer(1);
    lru.refer(2);
    lru.refer(3);
    lru.refer(1);
    lru.refer(4);
    lru.refer(5);

    lru.display_Q();

#endif    
    return 1;
}


