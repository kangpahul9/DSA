#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int largestSubarray(vector<int> arr){
    unordered_map<int,int>m;
    int ans=0;int sum=0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
        if (m.count(sum))
        {
            int currLength=i-m[sum];
            ans=max(ans,currLength);
        }
        else{
        m[sum]=i;
        }
        
    }
    return ans;
}


int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
    cout<<largestSubarray(arr);
    return 0;
}