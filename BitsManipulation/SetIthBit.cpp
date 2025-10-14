#include<iostream>
#include<string>
using namespace std;
int setIthBit(int n,int i){
    int bitmask = 1<<i;
    if (!(n & bitmask))
    {
       return n | bitmask;
    }
    
    return 1;
}

int main(){
    int n;
    cin >> n;
    int i;
    cin>>i;
    cout << setIthBit(n,i);
    return 0;
}