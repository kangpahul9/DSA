#include <iostream>
#include <vector>
#include<string>
using namespace std;

int catRec(int n,vector<int> &dp){
    if (n==0 || n==1)
    {
        return 1;
    }
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans+= catRec(i,dp)*catRec(n-i-1,dp);
    }
    return dp[n]=ans;
}

int catTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for (int i = 2; i < n+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 5;
    vector<int> dp(n+1,-1);
    cout << catRec(n,dp)<<endl;
    cout << catTab(n)<<endl;

    return 0;
}