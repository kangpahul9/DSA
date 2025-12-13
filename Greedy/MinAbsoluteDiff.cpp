#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int minAbsDiff(vector<int> start,vector<int> end){
    int ans=0; 
  vector<pair<int,int>> act;
  sort(start.begin(),start.end());
  sort(end.begin(),end.end());
  for (int i = 0; i < start.size(); i++)
  {
    act.push_back(make_pair(start[i],end[i]));
  } 
  for (int i = 0; i < act.size(); i++)
  {
    ans+=abs(act[i].second-act[i].first);
  }
  
    return ans;
}

int main() {
    vector<int> start = {5, 1, 3, 0, 5, 8};
    vector<int> end   = {7, 2, 4, 6, 9, 9};
    cout<<minAbsDiff(start,end);
    return 0;
}
