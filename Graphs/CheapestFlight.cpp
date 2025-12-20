#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst, int k) {
        priority_queue<pair<pair<int, int>, int>,
                       vector<pair<pair<int, int>, int>>,
                       greater<pair<pair<int, int>, int>>> pq;

        vector<vector<int>> dist(adj.size(), vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        int ans = INT_MAX;
        pq.push({{0, src}, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost  = curr.first.first;
            int node  = curr.first.second;
            int stops = curr.second;

            if (cost > dist[node][stops]) continue;

            if (node == dst) {
                ans = min(ans, cost);
                continue;
            }

            for (auto &child : adj[node]) {
                int wt = child.first;
                int next = child.second;

                if (stops <= k) {
                    if (dist[next][stops + 1] > cost + wt) {
                        dist[next][stops + 1] = cost + wt;
                        pq.push({{dist[next][stops + 1], next}, stops + 1});
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back(
                {flights[i][2], flights[i][1]});
        }
        return dijkstra(adj, src, dst, k);
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    // Expected output: 700

    return 0;
}
