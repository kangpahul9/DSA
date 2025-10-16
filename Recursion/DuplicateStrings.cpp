#include<iostream>
#include<string>
#include<vector>
using namespace std;
string duplicateStrings(string s1, string &result, int index,vector<bool> &map){
    if (index>=s1.size())
    {   
        return result;
    }
    char c=s1[index];
    int i=c-'a';
    if (!(map[i]))
    {
        result+=c;
        map[i]=true;
    }
    return duplicateStrings(s1,result,index+1,map);
}

int main(){
    string str1;
    getline(cin,str1);
    string result = "";
    vector <bool>map(26, false);
    cout << duplicateStrings(str1,result,0,map);
    return 0;
}