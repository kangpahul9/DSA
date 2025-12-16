#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int val;
    Node * left;
    Node * right;
    Node(int val){this->val=val;left=NULL;right=NULL;}
};

Node * buildBSTfromSorted(int arr[], int st, int end){
    if (st>end)
    {
        return NULL;
    }
    
    int mid = st + (end-st)/2;
    Node * curr = new Node(arr[mid]);
    curr->left=buildBSTfromSorted(arr,st,mid-1);
    curr->right=buildBSTfromSorted(arr,mid+1,end);
    return curr;
}

void inorder(Node * root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<", ";
    inorder(root->right);
}


int main(){
    int nodes[] = {3,4,5,6,7,8,9};
    Node * root = buildBSTfromSorted(nodes,0, 6);
    
    
    inorder(root);
    return 0;
}