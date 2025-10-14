#include<iostream>
#include<string>
using namespace std;
int clearIthBit(int n,int i){
    int bitmask = 1<<i;
    if (n & bitmask)
    {
       return n & ~(bitmask);
    }
    
    return 0;
}

int main(){
    int n;
    cin >> n;
    int i;
    cin>>i;
    cout << clearIthBit(n,i);
    return 0;
}