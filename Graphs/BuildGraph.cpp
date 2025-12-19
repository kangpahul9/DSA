#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph
{
private:
    int V;
    list<int> * l;
public:
    Graph(int v){this->V=v;l=new list<int>[V];}
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" -> ";
            for (auto  v : l[i])
            {
                cout<<v<< ", ";
            }
            cout<<endl;
        }
    }
    void bfsHelper(int src, vector <bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            cout<<val<<" ";
            for (auto i : l[val])
            {
                if (!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
    void bfs(){
        vector <bool>visited(V,false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfsHelper(i,visited);
                cout<<endl;
            }
        }
        
    }
    void dfs(){
        vector<bool>visited(V,false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsHelper(i,visited);
                cout<<endl;
            }
            
        }
        
    }
    void dfsHelper(int val, vector<bool> &visited){
        visited[val]=true;
        cout << val << " ";
        for (auto i : l[val])
        {
            if (!visited[i])
            {
                dfsHelper(i,visited);
            }
        }
    }
    bool hasPath(int src, int dest,vector<bool> &visited){
        if (src==dest)
        {
            return true;
        }
        
        for (auto i : l[src])
        {
            if (!visited[i])
            {
                visited[i]=true;
                if (hasPath(i,dest,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.bfs();
    cout<<endl;
    g.dfs();
    vector<bool> visited(7,false);
    cout << g.hasPath(0,6,visited);
    return 0;



}