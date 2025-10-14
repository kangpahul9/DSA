#include<iostream>
#include<string>
using namespace std;
int clearLastIBits(int n,int i){
    int bitmask = ~(0)<<i;
    return n & bitmask;
}

int main(){
    int n;
    cin >> n;
    int i;
    cin>>i;
    cout << clearLastIBits(n,i);
    return 0;
}