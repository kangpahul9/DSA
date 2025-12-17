#include<iostream>
#include<unordered_set>
#include <vector>
using namespace std;

void unionAndIntersection(vector<int>arr1, vector<int>arr2){
    unordered_set<int> combo,rambo;

    for (auto i : arr1)
    {
       combo.insert(i);
    }
    for (auto i : arr2)
    {
        if (combo.count(i))
        {
            rambo.insert(i);
        }
    }
    for (auto i : arr2)
    {
        combo.insert(i);
    }
    cout<<" UNION : "<<endl;
    for (auto i : combo)
    {
        cout<<i<<" ";
    }
    cout<<endl<<"INTERSECTION : "<<endl;
    for (auto i : rambo)
    {
        cout<<i<<" ";
    }

}


int main(){
    
    vector<int> a = {7, 3, 9};
    vector<int> b = {6, 3, 9, 2, 9, 4};

    unionAndIntersection(a,b);
    return 0;
}