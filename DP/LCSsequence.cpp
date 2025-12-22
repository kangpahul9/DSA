#include <iostream>
#include <vector>
#include<string>
using namespace std;

int lcsRec(string str1, string str2,int n, int m,vector<vector<int>> &dp){
    
    if (n==0 || m==0)
    {
        return 0;
    }
    if (dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if (str1[n-1]==str2[m-1])
    {
        dp[n][m]= lcsRec(str1,str2,n-1,m-1,dp)+1;
    }
    else{
       dp[n][m]= max(lcsRec(str1,str2,n,m-1,dp),lcsRec(str1,str2,n-1,m,dp));
    }
    return dp[n][m];
}

int lcsTab(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (str1[i-1]==str2[j-1])
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
    string str1="abcdge";
    string str2="abedg";
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<lcsRec(str1,str2,n,m,dp)<<endl;
    cout<<lcsTab(str1,str2);

    return 0;
}