#include <iostream>
using namespace std;

void permutation(string str,string res)
{
    int n=str.size();
    if (n==0)
    {
        cout<<res<<" ";
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string str1=str.substr(0,i)+str.substr(i+1,n-i-1);
        permutation(str1,res+str[i]);
    }
}

int main()
{
    string str = "123";
    string res="";
    permutation(str,res);
    return 0;
}
