#include<iostream>
#include<string>
using namespace std;
bool areAlmostEqual(string s1, string s2){
    if (s1.size() != s2.size()) return false;
    int diff[2];
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (count >= 2) return false;
            diff[count++] = i;
        }
    }
    if (count == 0) return true;
    if (count == 2) {
        int i = diff[0], j = diff[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
    return false;
}

int main(){
    string str1;
    getline(cin,str1);
    string str2;
    getline(cin,str2);
    cout << areAlmostEqual(str1,str2);
    return 0;
}