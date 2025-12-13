#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int> coins,int val){
    int ans=0; 
    for (int i = coins.size()-1; i >=0; i--)
    {
        while (val >= coins[i]) {
            val -= coins[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int val = 57;
    cout<<minCoins(coins,val)<<endl;
    cout<<minCoins(coins,121)<<endl;
    cout<<minCoins(coins,590)<<endl;
    cout<<minCoins(coins,490)<<endl;
    cout<<minCoins(coins,1000)<<endl;

    return 0;
}
