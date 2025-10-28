#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<queue>

using namespace std;
class Graph
{
private:
    int V;
    list<int> * l;
public:
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
    }    
    void printList(){
        for (int u = 0; u < V; u++)
        {
        list<int > neighbours = l[u];
        cout << u << ": ";
        for (int v : neighbours)
        {
            cout <<v << ", ";
        }
        cout<<endl;
        }
    }
    void bfs(){
        queue<int> q;
        vector<bool>visited(V,false);
       q.push(0);
        visited[0]=true;
        while (!q.empty())
        {
            int currPair=q.front();
            q.pop();
        cout << "visiting index " << currPair<<endl;
            for (auto neighbor : l[currPair])
            {
                if (!(visited[neighbor]))
                {
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
    }
    void dfs(int u, vector<bool> &visited){
        if (visited[u])
        {
            return;
        }
        visited[u]=true;
        cout << "visiting : " << u<<endl;
        list<int > neighbors = l[u];
        for (auto neighbor : neighbors){
            if (!(visited[neighbor]))
                {
                    dfs(neighbor,visited);
                }
        }
    }

    bool hasPathDFS(int src, int dest,vector<bool> &visited){
        if (src==dest)
        {
            return true;
        }
        
        if (visited[src])
        {
            return false;
        }
        visited[src]=true;
        list<int > neighbors = l[src];
        for (auto neighbor : neighbors){
            if (!(visited[neighbor]))
                {
                   if(hasPathDFS(neighbor,dest,visited)){
                    return true;
                   }
                }
        }
        return false;
    }

    bool hasPathBFS(int dest){
        queue<int> q;
        vector<bool>visited(V,false);
       q.push(0);
        visited[0]=true;
        while (!q.empty())
        {
            int currIndex=q.front();
            if (currIndex==dest)
            {
                return true;
            }
            
            q.pop();
            for (auto neighbor : l[currIndex])
            {
                if (!(visited[neighbor]))
                {
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
    void printAllPaths(int src, int dest){
        vector<bool> visited(5, false);
        string path="";
        pathHelper(src,dest,path,visited);
    }
    void pathHelper(int src, int dest, string path, vector<bool> &visited){
        if (src==dest)
        {
            cout<<path<<dest<<endl;
            return;
        }
            visited[src]=true;
            path += to_string(src);
        for (auto i : l[src])
        {
            if (!visited[i])
            {
                pathHelper(i,dest,path,visited);
            }
        }
        visited[src]=false;
    }

    void calcIndegree(vector<int> &indegree){
        for (int i = 0; i < V; i++)
        {
            for (int v : l[i])
            {
                indegree[v]++;
            }
        }
    }
    void topoSort(){
        vector<int>indegree(V,0);
        calcIndegree(indegree);
        queue <int> q;
        for (int  i = 0; i < V; i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int v : l[curr])
            {
                indegree[v]--;
                if (indegree[v]==0)
                {
                    q.push(v);
                }
                
            }
        }
        cout<<endl; 
        
    }
};


int main(){
    Graph g(6); 

g.addEdge(5, 0);
g.addEdge(5, 2);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);
g.addEdge(0, 3);


    // cout << "DFS Traversal:\n";
    vector<bool> visited(5, false);
    // g.dfs(0, visited);

    // cout << "\nBFS Traversal:\n";
    // g.bfs();
    g.topoSort();
    return 0;
}