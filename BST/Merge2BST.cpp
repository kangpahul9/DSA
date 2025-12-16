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

vector<int> merge(vector<int>path1,vector<int>path2){
    int i=0;
    int j=0;
    vector<int> final;
    while (i<path1.size() && j< path2.size())
    {
        if (path1[i]<=path2[j])
        {
            final.push_back(path1[i]);
            i++;
        }
        else{
            final.push_back(path2[j]);
            j++;
        }
    }
    while (i<path1.size())
    {
        final.push_back(path1[i]);
        i++;
    }
    while (j<path2.size())
    {
        final.push_back(path2[j]);
        j++;
    }
    return final;
}

Node * balancedBST(Node * root1, Node * root2 ){
    vector<int>path1;
    inorder(root1,path1);
    vector<int>path2;
    inorder(root2,path2);
    vector<int>path = merge(path1,path2);
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
    vector<int> nodes1 = {1,2,4};
    Node * root1 = buildBST(nodes1);
    vector<int> nodes2 = {9,3,12};
    Node * root2 = buildBST(nodes2);
    preOrder(root1);
    cout<<endl;
    preOrder(root2);
    cout<<endl;
    Node * root = balancedBST(root1,root2);
    preOrder(root);
    
    return 0;
}