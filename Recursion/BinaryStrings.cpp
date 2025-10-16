#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printBinaryStrings(int n, char lastDig,string ans){
    if (n==0)
    {
        cout<<ans<<endl;
        return;
    }
    
    if (lastDig!='1')
    {
        printBinaryStrings(n-1,'0',ans+'0');
        printBinaryStrings(n-1,'1',ans+'1');
    }
    else{
        printBinaryStrings(n-1,'0',ans+'0');
    }
    
    
}

int main(){
    int n;
    cin>>n;
    string ans="";
    printBinaryStrings(n, '0',ans);
    return 0;
}