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

vector<int> bellmanFord(vector<vector<Edge>> graph,int src){
    vector<int> dist(graph.size(),INT_MAX);
    dist[src]=0;
    for (int i = 0; i < graph.size()-1; i++)
    {
        for (int u = 0; u < graph.size(); u++)
        {
            for (Edge e : graph[u])
            {
                if (dist[u] != INT_MAX && dist[e.v] > dist[u]+e.wt)
                {
                    dist[e.v] = dist[u]+e.wt;
                }
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1));


    vector<int>dist=bellmanFord(graph,0);
    for (int i=0;i<dist.size();i++)
    {
        cout <<i<<" = "<<dist[i]<<endl;
    }
    
    return 0;
}
