#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int v,bool isUndir=true)
    {
        this->V = v;
        l = new list<int>[V];
        this->isUndir=isUndir;
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if (isUndir)
        {
            l[v].push_back(u);
        }
    }
    void printTopologicalOrder(stack<int> s){
        while (!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    void topologicalSort(){
        vector<bool>visited(V,false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSortHelper(i,visited,s);
            }
            
        }
        printTopologicalOrder(s);
    }
    void topologicalSortHelper(int val, vector<bool> &visited, stack<int> &s){
        visited[val]=true;
        for (auto i : l[val])
        {
            if (!visited[i])
            {
                topologicalSortHelper(i,visited,s);
            }
        }
        s.push(val);
    }
};


int main(){
    Graph g(6,false);
     g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);
   
    g.topologicalSort();
    return 0;



}