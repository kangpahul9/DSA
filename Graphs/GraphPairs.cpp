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
    list<pair<int,int> > * l;
public:
    Graph(int V){
        this->V=V;
        l = new list<pair<int,int> > [V];
    }
    void addEdge(int u, int v,int wt){
        l[u].push_back({v,wt});
        l[v].push_back({u,wt});
    }    
    void printList(){
        for (int u = 0; u < V; u++)
        {
        list<pair<int,int> > neighbours = l[u];
        cout << u << ": ";
        for (pair<int,int> v : neighbours)
        {
            cout << "("<<v.first << ", "<<v.second<<")";
        }
        cout<<endl;
        }
    }
    void bfs(){
        queue<pair<int,int> > q;
        vector<bool>visited(V,false);
       q.push({0,0});
        visited[0]=true;
        while (!q.empty())
        {
            pair<int, int> currPair=q.front();
            int u = currPair.first;
            q.pop();
        cout << "visiting index " << u<<endl;
            for (auto neighbor : l[u])
            {
                if (!(visited[neighbor.first]))
                {
                    visited[neighbor.first]=true;
                    q.push(neighbor);
                }
            }
        }
    }
    void dfs(pair<int,int> u, vector<bool> &visited){
        if (visited[u.first])
        {
            return;
        }
        visited[u.first]=true;
        cout << "visiting : " << u.first<<endl;
        list<pair<int,int> > neighbors = l[u.first];
        for (auto neighbor : neighbors){
            if (!(visited[neighbor.first]))
                {
                    dfs(neighbor,visited);
                }
        }
    }
    void PrimsAlgo(int src){
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater <pair<int, int>> > pq;
        //wt,u -> Min heap
        vector<bool> mst(V,false);
        pq.push(make_pair(0,src));
        int ans = 0;
        while (pq.size() > 0)
        {
             int u = pq.top().second;
             int wt = pq.top().first;
            pq.pop();
            if (!mst[u])
            {
                mst[u]=true;
                ans+=wt;
                list<pair<int,int> > neighbours = l[u];
                for (auto n : neighbours)
                {
                    int v = n.first; 
                    int currWt = n.second; 
                    pq.push(make_pair(currWt,v));
                }
            }
        }
        cout<<"Final cost of MST : " << ans;         
    }
};


int main(){
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    cout << "DFS Traversal:\n";
    vector<bool> visited(5, false);
    g.dfs({0,0}, visited);

    cout << "\nBFS Traversal:\n";
    g.bfs();
    g.PrimsAlgo(0);
    return 0;
}