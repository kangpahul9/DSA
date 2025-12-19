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
    void calcIndegree(vector<int> &indeg){
        for (int u = 0; u < V; u++){
        for (auto v : l[u]) {
            indeg[v]++;
        }
    }
        
    }
    void topo2(){
        vector<int> indeg(V,0);
        calcIndegree(indeg);
        queue<int>q;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i]==0)
            {
                q.push(i);
            }
        }
        while (q.size()>0)
        {
            int curr = q.front();
            q.pop();
            cout<< curr << " ";
            for (auto i : l[curr])
            {
                indeg[i]--;
                if (indeg[i]==0)
                {
                    q.push(i);
                }
            }
            
        }
        
        
    }
};

int main()
{
    Graph g(6,false);
     g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.topo2();
}