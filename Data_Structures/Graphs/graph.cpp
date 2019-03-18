#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h" 

#define MAX         100
#define DEBUG      0

using namespace std;

enum Color {WHITE, RED, BLUE};

class Graph {
    private:
        bool adj[MAX][MAX];
        int size;
        bool visited[MAX]; 
        Color col[MAX];

    public: 
        Graph(int size)
        {
            int i,j;
            this->size = size;

            for (i = 0; i < MAX; i++)
            {
                visited[i] = false;
            
                for (j = 0; j < MAX; j++)
                {
                    adj[i][j] = false;
                }
            }
        }

        void addEdge(int i, int j)
        {
            adj[i][j] = true;
            adj[j][i] = true;
        }
    
        void removeEdge(int i, int j)
        {
            adj[i][j] = false;
            adj[j][i] = false;
        }

        bool isEdge(int i, int j)
        {
            return adj[i][j];
        }
   
        bool isVisited(int i)
        {
            return this->visited[i];
        }

        void setVisited(int i)
        {
            this->visited[i] = true;
        }

        void cleanVisited()
        {
            int i;
            for (i = 0; i < MAX; i++)
            {
                this->visited[i] = false;        
                this->col[i] = WHITE;                
            }
        }
        void BFS(int node)
        {
            queue<int> q;
            q.push(node);
            int i, curr;
            
            cleanVisited();

            setVisited(node);
            cout<<"BFS of this graph is "<<endl;
            while(q.size() > 0)
            {
                curr = q.front();
                cout<<q.front()<<" ";
//                setVisited(curr);
                q.pop();

                for (i=0; i<this->size; i++)
                {
//                    cout<<"Here1 visited "<<isVisited(i)<<";
                    if (!isVisited(i) && (this->isEdge(curr,i)))
                    {
//                        cout<<"Here 2";
                        q.push(i);
                        setVisited(i);
                    }
                }
            }
            cout<<endl;
        }
        
        void DFS(int node)
        {
            stack<int> s;
            s.push(node);
            cleanVisited();
            cout<<"DFS of this graph is "<<endl;
            DFSUtils(s);
            cout<<endl;
        }

        void DFSUtils(stack<int> s)
        {
            int i, curr = s.top();
            s.pop();
            visited[curr] = true;
            
            cout<<curr<<" ";
            for (i = 0; i < this->size; i++)
            {
                if (!isVisited(i) && (this->isEdge(curr,i)))
                {
                    s.push(i);
                    DFSUtils(s);
                }
            }
        }

        bool IsPartitionPossible(int node)
        {
            Color color = RED;

            queue<int> q;
            q.push(node);

            int i, curr;

            while(q.size()>0)
            {
                curr = q.front();
                q.pop();
                this->col[curr] = color;
                this->visited[curr] = true;

                for (i=0; i<this->size; i++) 
                {               
                    if (!isVisited(i) && (this->isEdge(curr,i)))
                    {
                        q.push(i);
                    }

                    if((this->isEdge(curr,i)) && (this->col[i] == this->col[curr]))
                    {
                        cout<<"Impossible to color"<<endl;
                        return false;
                    }
                }
                if (color == RED)
                    color = BLUE;
                else
                    color = RED;
            }
            cout<<"Wonderful, It can be colored"<<endl; 
            return true;
        }
};

int main()
{
    cout<<"Welcome to Graph implementation!"<<endl;

    Graph g(10);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(4,6); 
    g.addEdge(5,6);

    g.BFS(1);
    g.DFS(1);

    g.IsPartitionPossible(1);
    return 0;
}

