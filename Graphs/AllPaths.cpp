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
    void allPath(int src,int dest){
        vector<bool>visited(V,false);
        vector<int>path;
        allPathHelper(src,dest,path,visited);
        }

    void printPath(vector<int>path){
        for(int i : path){
            cout<<i<<" -> ";
        }
        cout<<endl;
    }
    void allPathHelper(int src,int dest, vector<int> &path, vector<bool> &visited){
        if (src==dest)
        {
            path.push_back(src);
            printPath(path);
            return;
        }
        
        visited[src]=true;
        path.push_back(src);
        for (auto i : l[src])
        {
            if (!visited[i])
            {
                allPathHelper(i,dest,path,visited);
            }
        }
        path.pop_back();
        visited[src] = false;
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
    g.allPath(0,6);
    return 0;



}