#include<iostream>
#include<unordered_set>
#include <vector>
using namespace std;

int countDistinct(vector<int>arr){
    unordered_set<int> s;

    for (auto i : arr)
    {
       s.insert(i);
    }
    return s.size();
}


int main(){
    
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout<<countDistinct(arr);
    return 0;
}