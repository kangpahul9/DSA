#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

bool isValid(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]!=')' && str[i]!='}' && str[i]!=']' )
        {
            s.push(str[i]);
        }
        else{
            if (s.empty()) return false;
            char top = s.top();
            if (!(
                (top == '(' && str[i] == ')') ||
                (top == '[' && str[i] == ']') ||
                (top == '{' && str[i] == '}')
            )){
                return false;
            }
            s.pop();
        }
    }
    return true;
}

int main(){
     string str1="()[]{}";
     string str2="([])";
     string str3="(}";
     string str4=")(";
     cout<< isValid(str1)<<endl;
     cout<< isValid(str2)<<endl;
     cout<< isValid(str3)<<endl;
     cout<< isValid(str4)<<endl;

    return 0;
}