#include <iostream>
#include <vector>
#include<string>
#include <climits>

using namespace std;

int minSum(vector<int>arr){
    int totalSum=0;
    for (int i : arr)
    {
        totalSum+=i;
    }
    int W = totalSum/2;
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            if (arr[i-1]<=j)
            {
                dp[i][j]=max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }
    int grpSum1 = dp[n][W];
    int grpSum2 = totalSum - grpSum1;

    return abs(grpSum1-grpSum2);
}

int main(){
    vector<int> arr = {1,5,11,4};
     cout<< minSum(arr);
    return 0;
}