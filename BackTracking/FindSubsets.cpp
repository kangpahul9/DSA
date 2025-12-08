#include <iostream>
using namespace std;

void subsets(string str,string res,int i)
{
    if (i>=str.size())
    {
        cout<<res;
        cout<<endl;
        return;
    }
    subsets(str,res+str[i],i+1);

    subsets(str,res,i+1);
}

int main()
{
    string str = "abc";
    string res="";
    subsets(str,res,0);
    return 0;
}
