#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int res=0;int a=0,b=1;
    for (int i = 1; i <= num; i++)
    {
        cout<< a <<", ";
        res = a + b;
        a = b;
        b = res;
    }
    return 0;
}