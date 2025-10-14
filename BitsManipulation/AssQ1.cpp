#include<iostream>
#include<string>
using namespace std;
int clearLastIBits(int n,int i,int j){
    int bitmask1 = ~(0)<<j;
    int bitmask2= ~(0)<<i;
    int bitmask=~(bitmask1^bitmask2);
    n = n & bitmask;
    return n;
}

int main(){
    int n;
    cin >> n;
    int i;
    cin>>i;
    int j;
    cin>>j;
    cout << clearLastIBits(n,i,j);
    return 0;
}