#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include<stack>
using namespace std;
class Solution {
public:
    bool isCycleDirHelper(int src, vector<bool>& visited, vector<bool>& recPath,
                          vector<vector<int>>& adj) {
        visited[src] = true;
        recPath[src] = true;

        for (int i = 0; i < adj[src].size(); i++) {
            int child = adj[src][i];
            if (!visited[child]) {
                if (isCycleDirHelper(child, visited, recPath, adj)) {
                    return true;
                }
            } else {
                if (recPath[child]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoSort(int src,vector<bool>&visited,stack<int>&s,vector<vector<int>>& adj){
        visited[src]=true;
        for(auto i : adj[src]){
            if(!visited[i]){
                topoSort(i,visited,s,adj);
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);
        vector<int> ans;
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleDirHelper(i, visited, recPath, adj)) {
                    return ans;
                }
            }
        }
        //toposort
        vector<bool>vis(V,false);
        stack<int>s;
        for (int i = 0; i < V; i++){
            if (!vis[i]) {
                topoSort(i,vis,s,adj);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


int main() {
    Solution s;

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    vector<int> ans = s.findOrder(numCourses, prerequisites);
    for (int i : ans)
    {
        cout << i << " ";
    }
    

    prerequisites.push_back({1, 3});

    vector<int> ans2 = s.findOrder(numCourses, prerequisites);
    for (int i : ans2)
    {
        cout << i << " ";
    }

    return 0;
}
