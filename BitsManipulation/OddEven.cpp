#include<iostream>
#include<string>
using namespace std;
int oddEven(int n){
    int bitmask = 1;
    return n & bitmask;
}

int main(){
    int n;
    cin >> n;
    cout << oddEven(n);
    return 0;
}