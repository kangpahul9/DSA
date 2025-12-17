#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


bool isAnalagram(string arr1, string arr2){
    if (arr1.size() != arr2.size())
    {
        return false;
    }
    
    unordered_map< char,int> m1;
    for (int i = 0; i < arr1.size(); i++)
    {
        if (!(m1.count(arr1[i])))
        {
            m1[arr1[i]]=1;
        }
        else{
            m1[arr1[i]]++;
        }
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        
        if (!(m1.count(arr2[i])))
        {
            return false;
        }else{
            m1[arr2[i]]--;
        }
    }
    for (auto &p : m1) {
    if (p.second != 0) {
        return false;
    }
}
return true;

}

int main(){
    string arr1="tulip";
    string arr2="lipid";

    cout << isAnalagram(arr1,arr2);
    
    return 0;
}