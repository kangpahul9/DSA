#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int countSubarray(vector<int> arr,int K){
    unordered_map<int,int>m;
    m[0]=1;
    int ans=0;int sum=0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
        if (m.find(sum-K)!=m.end())
        {
            ans+=m[sum-K];
        }
        if (m.find(sum)==m.end())
        {
            m[sum]=1;
        }
        else{
            m[sum]++;
        }
        
    }
    return ans;
}


int main(){
    vector<int> arr = {10, -2, 2, -20, 10};
    cout<<countSubarray(arr,-10);
    return 0;
}