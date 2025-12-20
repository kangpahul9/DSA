#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include<stack>
using namespace std;

class Edge
{
public:
    int v;
    int wt;
    Edge(int v, int wt){
        this->v=v;
        this->wt=wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> graph, vector<int> &dist){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,src));
    dist[src]=0;
    while (!q.empty())
    {
        int u = q.top().second;
        int wt = q.top().first;
        q.pop();
        if (wt > dist[u]) continue;
        for (auto v : graph[u])
        {
            if (dist[v.v] >= dist[u]+v.wt)
            {
                dist[v.v]=dist[u]+v.wt;
                q.push(make_pair(dist[v.v],v.v));
            }
        }
    }
}

vector<int> shortestPath(vector<vector<Edge>> graph){
    vector<int>dist(graph.size(),INT_MAX);
        dijkstra(0,graph,dist);
    return dist;
}

int main() {
    int V = 6;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(3, 7));
    graph[1].push_back(Edge(2, 1));

    graph[2].push_back(Edge(4, 3));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    graph[3].push_back(Edge(5, 1));

    vector<int>dist=shortestPath(graph);
    for (int i=0;i<dist.size();i++)
    {
        cout <<i<<" = "<<dist[i]<<endl;
    }
    
    return 0;
}
