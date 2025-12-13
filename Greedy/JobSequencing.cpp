#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
  return p1.second > p2.second;

}

int maxProfit(vector<pair<int,int>> jobs){
  sort(jobs.begin(),jobs.end(),compare);
    int ans = jobs[0].second;
    int safeDeadline=2;
    for (int i = 0; i < jobs.size(); i++)
    {
       if (jobs[i].first>=safeDeadline)
       {
         ans+=jobs[i].second;
         safeDeadline++;
       } 
    }
    return ans;
}
int main() {
    vector<pair<int,int>> jobs = {
        {1, 40},
        {1, 30},
        {1, 20},
        {4, 20}
    };

    cout << "Max Profit: "
         << maxProfit(jobs) << endl;

    return 0;
}
