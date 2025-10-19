#include<iostream>
#include<string>
#include<vector>
using namespace std;
int binarySearch(vector<int>arr, int st, int end, int target){
    if (!(st<=end))
    {
        return -1;
    }
    
    int mid = st + (end-st)/2;
    if (arr[mid]>target)
    {
        return binarySearch(arr,st,mid-1,target);
    }
    if (arr[mid]<target)
    {
        return binarySearch(arr,mid+1,end,target);
    }
    return mid;
}

int main(){
    int n;
    cin >>n;
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7};
    int end = arr.size()-1;
    cout << binarySearch(arr,0,end,n);
    return 0;
}