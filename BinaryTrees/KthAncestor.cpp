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



int kthAncestor(Node * root,int node, int K){ 
    if (root==NULL)
    {
        return -1;
    }
    
    if (root->val==node)
    {
        return 0;
    }
    int dist1=kthAncestor(root->left,node,K);
    int dist2=kthAncestor(root->right,node,K);
    if (dist1==-1 && dist2==-1){
        return -1;
    }
    int validVal = dist1==-1 ? dist2 : dist1;
    if (validVal+1==K)
    {
        cout<<"Kth Ancestor: "<<root->val;
    }
    return validVal+1;
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    int KthAncestor=kthAncestor(root,4,2);


    return 0;   
}