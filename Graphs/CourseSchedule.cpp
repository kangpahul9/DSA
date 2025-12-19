#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> visited(V,false);
        vector<bool> recPath(V,false);
        vector<vector<int>> adj(numCourses);

for (auto &p : prerequisites) {
    adj[p[1]].push_back(p[0]); 
}
        for (int i = 0; i < V; i++)
        {
            if (!visited[i]){
            if (isCycleDirHelper(i,visited,recPath,adj))
            {
                return false;
            }
        }
        }
        return true;
    }
    bool isCycleDirHelper(int src, vector<bool> &visited, vector<bool>&recPath,vector<vector<int>> &adj){
        visited[src] = true;
        recPath[src] = true;

        for (int i=0;i<adj[src].size();i++)
        {
            int child = adj[src][i];
            if (!visited[child])
            {
                if (isCycleDirHelper(child, visited,recPath,adj))
                {
                    return true;
                }
            }
            else
            {
                if (recPath[child])
                {
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
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

    cout << s.canFinish(numCourses, prerequisites) << endl;

    prerequisites.push_back({1, 3});

    cout << s.canFinish(numCourses, prerequisites) << endl;

    return 0;
}
