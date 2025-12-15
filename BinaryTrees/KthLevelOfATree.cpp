#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
public:
    int val;
    Node * left;
    Node * right;
    Node(int val){this->val=val;left=NULL;right=NULL;}
};

static int idx=-1;

Node * buildTree(vector<int>nodes){
    idx++;
    if (nodes[idx]==-1)
    { 
        return NULL;
    }
    Node * currNode = new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}


void kNodePrint(Node * root, int K){
    if (root==NULL || K<0)
    {
        return;
    }
    if (K==1)
    {
        cout<<root->val<<", ";
        return;
    }
    kNodePrint(root->left,K-1);
    kNodePrint(root->right,K-1);
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    

    kNodePrint(root,3);
    return 0;   
}