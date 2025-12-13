#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2){
  return p1.first > p2.first;

}
double fractionalKnapsack(vector<int> val,vector<int> wt, int W){
    double ans=0; 
  vector<pair<double,int>> things;
  for (int i = 0; i < val.size(); i++)
  {
    double ratio=(double)val[i]/wt[i];
    things.push_back(make_pair(ratio,i));
  } 
  sort(things.begin(),things.end(),compare);

  for (int i = 0; i < things.size(); i++)
  {

    int idx=things[i].second;
    if (W>=wt[idx])
    {
        ans+=val[idx];
        W-=wt[idx];
    }
    else{
        ans+=W*things[i].first;
        break;
    }
  }
    return ans;
}

int main() {
    vector<int> val = {60,100,120};
    vector<int> wt   = {10,20,30};
    int W=50;
    cout<<fractionalKnapsack(val,wt,W)<<endl;
    val = {60, 100};
    wt  = {10, 30};
    W = 20;
    cout<<fractionalKnapsack(val,wt,W)<<endl;
    return 0;
}
