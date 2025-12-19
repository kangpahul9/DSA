#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto v : l[i])
            {
                cout << v << ", ";
            }
            cout << endl;
        }
    }
    bool isCycleUndir()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i]){
            if (isCycleUndirHelper(i,-1,visited))
            {
                return true;
            }
        }
        }
        return false;
    }
    bool isCycleUndirHelper(int src, int par, vector<bool> &visited)
    {
        visited[src] = true;
        for (auto i : l[src])
        {
            if (!visited[i])
            {
                
                if (isCycleUndirHelper(i, src, visited))
                {
                    return true;
                }
            }
            else
            {
                if (par != i)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleDirHelper(int src, vector<bool> &visited, vector<bool>&recPath){
        visited[src] = true;
        recPath[src] = true;

        for (auto i : l[src])
        {
            if (!visited[i])
            {
                if (isCycleDirHelper(i, visited,recPath))
                {
                    return true;
                }
            }
            else
            {
                if (recPath[i])
                {
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }   
    bool isCycleDir(){
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i]){
            if (isCycleDirHelper(i,visited,recPath))
            {
                return true;
            }
        }
        }
        return false;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    cout << g.isCycleUndir()<<endl;

     Graph g2(4,false);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);
    cout<<g2.isCycleDir();
}