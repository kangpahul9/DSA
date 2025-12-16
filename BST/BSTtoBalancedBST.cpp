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

Node * insert(Node * root, int i){
    if (root==NULL)
    {
        root = new Node(i);
        return root;
    }
    if(i < root->val){
        root->left= insert(root->left,i);
    }
    else{
        root->right= insert(root->right, i);
    }
    return root;
}

Node * buildBST(vector<int>nodes){
    Node* root = NULL;
    for (int i = 0; i < nodes.size(); i++)
    {
        root = insert(root,nodes[i]);
    }
    return root;
}

Node * buildBSTfromSorted(vector<int> &path, int st, int end){
    if (st>end)
    {
        return NULL;
    }
    
    int mid = st + (end-st)/2;
    Node * curr = new Node(path[mid]);
    curr->left=buildBSTfromSorted(path,st,mid-1);
    curr->right=buildBSTfromSorted(path,mid+1,end);
    return curr;
}

void inorder(Node * root,vector<int> &path){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left,path);
    path.push_back(root->val);
    inorder(root->right,path);
}

Node * balancedBST(Node * root){
    vector<int>path;
    inorder(root,path);
    return buildBSTfromSorted(path,0,path.size()-1);
}

void preOrder(Node * root){
    if (root==nullptr)
    {
        return;
    }
    cout<<root->val<<", ";
    preOrder(root->left);
    preOrder(root->right); 
}

int main(){
    vector<int> nodes = {3,4,5,6,7,8,9};
    Node * root = buildBST(nodes);
    preOrder(root);
    cout<<endl;
    root = balancedBST(root);
    preOrder(root);
    
    return 0;
}