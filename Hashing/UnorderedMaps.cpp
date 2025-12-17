#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;
    m["China"]=150;
    m["India"]=150;
    m["US"]=50;
    m["Nepal"]=10;
    for (pair <string,int> p : m)
    {
        cout<< p.first <<": "<<p.second<<endl;
    }
    m.erase("Nepal");
    if (m.count("Nepal"))
    {
        cout<<"Nepal Exists"<<endl;
    }else{
        cout << "Nepal doesn't exist"<<endl;
    }
    m["India"]=200;
    cout<<m["India"]<<endl;
    
    return 0;
}