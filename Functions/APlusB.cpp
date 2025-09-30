#include<iostream>
using namespace std;

int APlusB(int a, int b){
    
    return a*a + 2*a*b + b*b;
}

int main(){
    int a,b;
    cin >> a;
    cout << endl; 
    cin >> b;
    cout << APlusB(a,b);
    
    return 0;
}