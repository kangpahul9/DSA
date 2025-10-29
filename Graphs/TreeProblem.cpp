#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<queue>
using namespace std;

class TreeAndVertex
{
private:
    
public:
    int calcDegree(vector<vector<int>> &adj,int n){
        int maxDegree=INT_MIN;
        for (int i = 0; i <=n; i++)
        {
            int degree = adj[i].size();
            maxDegree = max(maxDegree, degree);
        }
        return maxDegree;      
    }
    int get(vector<int> &tree){
        int n=tree.size();
        vector<vector<int>> adj(n+1);
        for (int i = 0; i <n; i++)
        {
            adj[i+1].push_back(tree[i]);
            adj[tree[i]].push_back(i+1);
        }
    return calcDegree(adj,n);
    }
};

int main()
{
    TreeAndVertex obj;

    vector<vector<int>> tests = {
        {0, 0, 0},                                        // expected 3
        {0, 1, 2, 3},                                     // expected 2
        {0, 0, 2, 2},                                     // expected 3
        {0, 0, 0, 1, 1, 1},                               // expected 4
        {0, 1, 2, 0, 1, 5, 6, 1, 7, 4, 2, 5, 5, 8, 6, 2,
         14, 12, 18, 10, 0, 6, 18, 2, 20, 11, 0, 11, 7,
         12, 17, 3, 18, 31, 14, 34, 30, 11, 9}            // expected 5
    };

    for (int i = 0; i < tests.size(); i++)
    {
        cout << "Test " << i << ": " << obj.get(tests[i]) << endl;
    }

    return 0;
}