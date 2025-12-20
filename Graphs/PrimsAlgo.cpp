#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Edge
{
public:
    int v;
    int wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

int primsAlgo(vector<vector<Edge>> graph, int src)
{
    int V = graph.size();
    vector<bool> mstSet(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int ans = 0;
    q.push(make_pair(0, src));
    while (!q.empty())
    {
        int u = q.top().second;
        int wt = q.top().first;
        q.pop();
        if (mstSet[u])
            continue;
        mstSet[u] = true;
        ans += wt;
        for (auto a : graph[u])
        {
            if (!mstSet[a.v])
            {
                q.push(make_pair(a.wt, a.v));
            }
        }
    }
    return ans;
}
int main()
{
    int V = 6;
    vector<vector<Edge>> graph(V);

    // 0 - 1 (2)
    graph[0].push_back(Edge(1, 2));
    graph[1].push_back(Edge(0, 2));

    // 0 - 2 (4)
    graph[0].push_back(Edge(2, 4));
    graph[2].push_back(Edge(0, 4));

    // 1 - 3 (7)
    graph[1].push_back(Edge(3, 7));
    graph[3].push_back(Edge(1, 7));

    // 1 - 2 (1)
    graph[1].push_back(Edge(2, 1));
    graph[2].push_back(Edge(1, 1));

    // 2 - 4 (3)
    graph[2].push_back(Edge(4, 3));
    graph[4].push_back(Edge(2, 3));

    // 4 - 3 (2)
    graph[4].push_back(Edge(3, 2));
    graph[3].push_back(Edge(4, 2));

    // 4 - 5 (5)
    graph[4].push_back(Edge(5, 5));
    graph[5].push_back(Edge(4, 5));

    // 3 - 5 (1)
    graph[3].push_back(Edge(5, 1));
    graph[5].push_back(Edge(3, 1));

    cout << primsAlgo(graph, 0) << endl;


    vector<vector<Edge>> graph2(V);

// 0 - 1 (10)
graph2[0].push_back(Edge(1, 10));
graph2[1].push_back(Edge(0, 10));

// 0 - 2 (15)
graph2[0].push_back(Edge(2, 15));
graph2[2].push_back(Edge(0, 15));

// 0 - 3 (30)
graph2[0].push_back(Edge(3, 30));
graph2[3].push_back(Edge(0, 30));

// 1 - 3 (40)
graph2[1].push_back(Edge(3, 40));
graph2[3].push_back(Edge(1, 40));

// 2 - 3 (50)
graph2[2].push_back(Edge(3, 50));
graph2[3].push_back(Edge(2, 50));

cout << primsAlgo(graph2, 0) << endl;
}
