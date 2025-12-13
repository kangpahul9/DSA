#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
  return p1.second < p2.second;

}
int maxActivities(vector<int> start,vector<int> end){
  vector<pair<int,int>> act(start.size(),make_pair(0,0));
  for (int i = 0; i < start.size(); i++)
  {
    act[i]=make_pair(start[i],end[i]);
  } 
    sort(act.begin(),act.end(),compare);

    int ans = 1;
    int currEnd = act[0].second;
    for (int i = 1; i < start.size(); i++)
    {
       if (act[i].first>=currEnd)
       {
         ans++;
         currEnd=act[i].second;
       }
       
    }
    return ans;
}

int main() {
    vector<int> start = {5, 1, 3, 0, 5, 8};
    vector<int> end   = {7, 2, 4, 6, 9, 9};

    cout << "Maximum number of activities: "
         << maxActivities(start, end) << endl;

    return 0;
}
