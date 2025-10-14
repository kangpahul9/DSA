#include<iostream>
#include<string>
using namespace std;
int updateIthBit(int n,int i,int val){
    n = n & ~(1<<i);
    n=n|(val<<i);
    return n;
}

int main(){
    int n;
    cin >> n;
    int i;
    cin>>i;
    int val;
    cin>>val;
    cout << updateIthBit(n,i,val);
    return 0;
}