#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<queue>
using namespace std;

class FriendlyRooks
{
private:
    
public:
   
    int getMinFriendlyColoring(vector<string> &board){
        int n = board.size();
        vector<pair<int,int>> graph;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j]=='R')
                {
                    graph.push_back(make_pair(i,j));
                }
            }
        }
        int numColors=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (graph[i].first == graph[j].first || graph[i].second == graph[j].second)
            {
                numColors++;
            }
            }
            
            
        }
    }
};

int main()
{
    

    return 0;
}