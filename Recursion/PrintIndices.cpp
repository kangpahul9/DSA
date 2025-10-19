#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printIndices(vector<int>arr,int target,int i){
    if (i>=arr.size())
    {
        return;
    }
    if (arr[i]==target)
    {
        cout<<i<<" ";
    }
    printIndices(arr,target,i+1);
    
}

int main(){
    int n;
    cin >>n;
    vector<int>arr = {1, 2, 3, 2, 5, 6, 2};
    printIndices(arr,n,0);
    return 0;
}