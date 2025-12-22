#include <iostream>
#include <vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> unique(vector<int> arr)
{
    vector<int> arr2;
    unordered_set<int> s(arr.begin(),arr.end());
    vector<int> arr2(s.begin(),s.end());
    sort(arr2.begin(),arr2.end());    
    return arr2;
}
int lisTab(vector<int>arr){
    int n=arr.size();
    vector<int> arr2=unique(arr);
    int m =arr2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (arr[i-1]==arr2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }            
        }
        
    }
    return dp[n][m];
}

int main(){
    vector<int>arr={50,3,10,7,40,80};
    cout<<lisTab(arr);

    return 0;
}