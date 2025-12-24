#include <iostream>
#include <vector>
#include<string>
#include <climits>
using namespace std;

class SegmentTree
{
private:
    vector<int>tree;
    int n;
public:
    SegmentTree(vector<int> &arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);

    }

    void buildTree(vector<int> arr,int st, int end, int node){
        if (st==end)
        {
            tree[node]=arr[st];
            return;
        }
        
        int mid = st + (end-st)/2;
        buildTree(arr,st,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);
        tree[node]=tree[node*2 + 1] + tree[node*2 + 2];
    }

    void printTree(){
        for (int i = 0; i < tree.size(); i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    SegmentTree ST(arr);
    ST.printTree();
    return 0;
}