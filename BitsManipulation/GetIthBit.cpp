#include<iostream>
#include<string>
using namespace std;
int getIthBit(int n,int i){
    int bitmask = 1<<i;
    if (n & bitmask)
    {
        return 1;
    }
    
    return 0;
}

int main(){
    int n;
    cin >> n;
    int i;
    cin>>i;
    cout << getIthBit(n,i);
    return 0;
}