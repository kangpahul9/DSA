#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int minCost(vector<int>arr){
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
    int ans = 0;
    for (int i = 0; i < arr.size()-1; i++)
    {
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        ans+=min1+min2;
        pq.push(min1+min2);
    }
    return ans;    
}

int main(){
    vector <int>arr = {4,3,2,6};
    cout<<minCost(arr);
    cout<<endl;
    return 0;
}