#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


void majorityElement(vector<int>arr){
    unordered_map<int,int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!(m.count(arr[i])))
        {
            m[arr[i]]=1;
        }
        else{
            m[arr[i]]++;
        }
    }
    for (auto a : m)
    {
        if (a.second > arr.size()/3)
        {
            cout<< a.first<<" ";
        }
        
    }

}

int main(){
    vector<int> arr = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    majorityElement(arr);
    
    return 0;
}