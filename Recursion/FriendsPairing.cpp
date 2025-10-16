#include<iostream>
#include<string>
#include<vector>
using namespace std;
int friendsPairing(int n){
    if (n==1)
    {
        return 1;
    }
    if (n==2)
    {
        return 2;
    }
    return friendsPairing(n-1) + (n-1)*friendsPairing(n-2);
}

int main(){
    int n;
    cin >>n;
    cout << friendsPairing(n);
    return 0;
}