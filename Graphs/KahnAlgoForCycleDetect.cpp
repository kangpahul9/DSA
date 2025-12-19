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
    bool checkCycle(){
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
            for (auto i : l[curr])
            {
                indeg[i]--;
                if (indeg[i]==0)
                {
                    q.push(i);
                }
            }
            
        }
        for (int i = 0; i < V; i++)
        {
            if (indeg[i]>0)
            {
                return true;
            }
            
        }
        
        return false;
        
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
    cout << g.checkCycle();

    Graph g2(4,false);
     g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(2,0);
    g2.addEdge(3,2);
    cout << g2.checkCycle();
}