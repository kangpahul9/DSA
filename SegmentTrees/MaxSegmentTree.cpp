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
    void buildTree(vector<int> arr,int st, int end, int node){
        if (st==end)
        {
            tree[node]=arr[st];
            return;
        }
        
        int mid = st + (end-st)/2;
        buildTree(arr,st,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);
        tree[node]=max(tree[node*2 + 1],tree[node*2 + 2]);
    }
    int rangeMax(int qi, int qj, int si, int sj, int node){
        if (qj < si || qi > sj)
        {
            return INT_MIN;
        }
        if (si >= qi && sj <= qj)
        {
            return tree[node];
        }
        int mid = si + (sj-si)/2;
        return max(rangeMax(qi,qj, si, mid, 2*node+1),rangeMax(qi,qj,mid+1,sj, 2*node+2));
    }
    void updateUtil(int idx, int val, int si, int sj, int node){
        if (si==sj)
        {
            tree[node]=val;
            return;
        }
        
        int mid = si + (sj-si)/2;
        if (idx >= si && idx <= mid)
        {
            updateUtil(idx,val,si,mid,2*node+1);
        }
        else{
            updateUtil(idx,val,mid+1,sj,2*node+2);
        }
        tree[node]=max(tree[node*2 + 1],tree[node*2 + 2]);
    }
public:
    SegmentTree(vector<int> &arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);

    }
    void printTree(){
        for (int i = 0; i < tree.size(); i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    int rangeQuery(int qi, int qj){
        return rangeMax(qi,qj,0,n-1,0);
    }
    void updateQuery(int idx, int val){
        updateUtil(idx,val,0,n-1,0);
    }

};

int main(){
    vector<int>arr={6,8,-1,2,17,1,3,2,4};
    SegmentTree ST(arr);
    ST.printTree();
    cout<<ST.rangeQuery(2,5)<<endl;
    ST.updateQuery(1,3);
    cout<<ST.rangeQuery(0,3)<<endl;
    return 0;
}