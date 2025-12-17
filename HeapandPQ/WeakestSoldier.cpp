#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct comparePair{
    bool operator() (pair<int,int> &p1, pair<int,int> &p2){
        if (p1.first == p2.first)
        {
            return p1.second > p2.second;
        }
        
        return p1.first > p2.first;
    }
};

void weakestSoldier(const vector<vector<int>>&matrix, int K){
    vector<pair<int,int>> counts;
    for (int i = 0; i < matrix.size(); i++)
    {
        int c = 0;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j]==1)
            {
                c++;
            }
        }
        counts.push_back(make_pair(c,i));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,comparePair>pq(counts.begin(),counts.end());
    for (int i = 0; i < K; i++)
    {
        cout<<"weakest soldier in row : "<<pq.top().second<<endl;
        pq.pop();
    }
}

int main(){
    vector<vector<int>> matrix = {
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
};


    weakestSoldier(matrix,2);
    cout<<endl;
    return 0;
}