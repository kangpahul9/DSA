#include<iostream>
using namespace std;

bool palindrome(int n){
    int temp = n;int digit,sum=0;
    while (temp > 0)
    {
        digit=temp%10;
        sum=sum*10+digit;
        temp=temp/10;
    }
    if (sum==n)
    {
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    cout << palindrome(n);
    
    return 0;
}