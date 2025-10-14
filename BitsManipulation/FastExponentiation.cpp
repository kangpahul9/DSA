#include<iostream>
#include<string>
using namespace std;
int fastExponentiation(int n,int p){
    int x=n;
    int ans=1;
    while (p>0)
    {
        int lastDig=p&1;
        if (lastDig>0)
        {
            ans=ans*x;
        }
        x=x*x;
        p=p>>1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int p;
    cin>>p;
    cout << fastExponentiation(n,p);
    return 0;
}