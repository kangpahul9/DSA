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
    bool isBipartiteHelper(int src, vector <bool> &visited, vector<bool> &color){
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            for (auto i : l[val])
            {
                if (!visited[i])
                {
                    visited[i]=true;
                    color[i]=!(color[val]);
                    q.push(i);
                }
                if (color[i]==color[val])
                {
                    return false;
                }
                
            }
        }
        return true;
    }
    bool isBipartite(){
        vector <bool>visited(V,false);
        vector <bool>color(V,false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if(!isBipartiteHelper(i,visited,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
    
};


int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    // g.addEdge(3,4);
    
    cout<<g.isBipartite();
    
    return 0;



}