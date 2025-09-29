#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int res=1;
    for (int i = 1; i <= num; i++)
    {
        res*=i;
    }
    cout<<"Factorial of "<<num<<" is "<<res;
    return 0;
}