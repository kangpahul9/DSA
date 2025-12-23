#include <iostream>
#include <vector>
#include<string>
#include <climits>

using namespace std;

int mcm(vector<int> arr,int i,int j,vector<vector<int>> &dp){
    if (i==j)
    {
        return 0;
    }
    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int ans=INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost1=mcm(arr,i,k,dp);
        int cost2=mcm(arr,k+1,j,dp);
        int currCost = cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,currCost);
    }
    return dp[i][j]=ans;
}


int mcm2(vector<int> arr,int i,int j){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));

    for (int i = 0; i < n; i++)
    {
        dp[i][i]=0;
    }
    
    for (int len = 2; len <n; len++)
    {
        for (int i = 1; i <=n-len; i++)
        {
            int j = i+ len - 1;
            for (int k = i; k < j; k++)
            {
                int cost1=dp[i][k];
                int cost2=dp[k+1][j];
                int currCost = cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
                dp[i][j]=min(dp[i][j],currCost);
            }
        }
        
    }
    return dp[1][n-1];
}
int main(){
    vector<int> arr = {1,2,3,4,3};
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    dp[0][0]=0;
    cout << mcm(arr,1,n-1,dp)<<endl;
    cout << mcm2(arr,1,n-1)<<endl;

    return 0;
}