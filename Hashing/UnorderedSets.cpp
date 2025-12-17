#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    cout<<s.size()<<endl;
    s.erase(3);
    if (s.find(3) != s.end())
    {
        cout<<"3 exists"<<endl;
    }
    else{
        cout<<"3 doesn't exists"<<endl;
    }
    for (auto i : s)
    {
       cout<<i<<" ";
    }
    cout<<endl;
    

    
    return 0;
}