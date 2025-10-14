#include<iostream>
#include<string>
using namespace std;
int PowerOfTwo(int n){
    int bitmask = n-1;
    if (n & bitmask)
    {
        return 0;
    }
    
    return 1;
}

int main(){
    int n;
    cin >> n;
    cout << PowerOfTwo(n);
    return 0;
}