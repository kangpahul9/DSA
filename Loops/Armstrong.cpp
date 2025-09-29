#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int temp=num;
    int res=0;int digit;
    while(temp > 0){
        digit=temp%10;
        res+=digit*digit*digit;
        temp=temp/10;
    }
    if (num == res)
    {
        cout << num << " is an Armstrong Number";
    }
    else{
        cout << num << " is not an Armstrong Number";
    }
    
    return 0;
}