#include<iostream>
#include<string>
using namespace std;
int countSetBits(int n){
    int sum=0;
    while (n>0)
    {
        int lastDig=n&1;
        sum+=lastDig;
        n=n>>1;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout << countSetBits(n);
    return 0;
}