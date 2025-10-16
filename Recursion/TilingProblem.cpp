#include<iostream>
#include<string>
#include<vector>
using namespace std;
int noOfTiles(int n){
    if (n==0 || n==1)
    {
        return 1;
    }
    
    return noOfTiles(n-1) + noOfTiles(n-2);
}

int main(){
    int n;
    cin >>n;
    cout << noOfTiles(n);
    return 0;
}