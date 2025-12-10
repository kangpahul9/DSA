#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

bool isDuplicate(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]==')')
        {
            if (s.top()=='(')
            {
                return true;
            }
            while (s.top()!='(')
            {
                s.pop();
            }
            s.pop();
            }
        else{
            s.push(str[i]);
        }
    }
    return false;
}

int main(){
     string str1="((a+b))";
     string str2="((a+b)+(c+d))";
     cout<< isDuplicate(str1)<<endl;
     cout<< isDuplicate(str2)<<endl;
    return 0;
}