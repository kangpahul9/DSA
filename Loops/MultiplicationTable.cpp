#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int res=0;
    for (int i = 1; i <= 10; i++)
    {
        res+=num;
        cout<<num<<" X "<<i<<" = "<<res<<endl;
    }
    return 0;
}