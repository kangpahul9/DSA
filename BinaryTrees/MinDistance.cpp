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


Node * lca(Node * root, int a, int b){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->val==a || root->val==b)
    {
        return root;
    }
    Node * leftLCA=lca(root->left,a,b);
    Node * rightLCA=lca(root->right,a,b);
    if (leftLCA!=NULL && rightLCA!=NULL)
    {
         return root;
    }
    return leftLCA != NULL ? leftLCA : rightLCA ;    
}

int distance(Node * root,int n){ 
    if (root==NULL)
    {
        return -1;
    }
    
    if (root->val==n)
    {
        return 0;
    }
    int dist1=distance(root->left,n);
    int dist2=distance(root->right,n);
    if (dist1!=-1)
    {
        return dist1+1;
    }
    if(dist2!=-1){
        return dist2+1;
    }
    return -1;
    
}

int minDist(Node * root, int a, int b){
    Node * LCA = lca(root, a, b);
    if (LCA == NULL) return -1;
    int dist1=distance(LCA,a);
    int dist2=distance(LCA,b);
    return dist1+dist2;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    
    cout << minDist(root,4,6);
    return 0;   
}