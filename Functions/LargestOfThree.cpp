#include<iostream>
using namespace std;

int LargestOfThree(int a, int b, int c){
    if (a>=b && a >=c)
    {
        return a;
    }
    if (b>=a && b >=c)
    {
        return b;
    }
    return c;
}

int main(){
    int a,b,c;
    cin >> a;
    cout << endl; 
    cin >> b;
     cout << endl; 
    cin >> c;
    cout << LargestOfThree(a,b,c);
    
    return 0;
}