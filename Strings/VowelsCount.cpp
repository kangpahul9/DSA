#include<iostream>
#include<string>
using namespace std;
int vowelsCount(string str){
    int n=str.length();int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            count++;
        }
    }
    return count;
}

int main(){
    string str;
    getline(cin,str);
    cout << vowelsCount(str);
    return 0;
}