#include<iostream>
using namespace std;

int sumOfDigits(int n){
    int temp = n;int digit,sum=0;
    while (temp > 0)
    {
        digit=temp%10;
        sum+=digit;
        temp=temp/10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout << sumOfDigits(n);
    
    return 0;
}