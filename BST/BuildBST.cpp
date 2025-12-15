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

void inorder(Node * root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<", ";
    inorder(root->right);
}

bool search(Node * root,int target){
    if (root==NULL)
    {
        return false;
    }
    if (root->val>target)
    {
        return search(root->left,target);
    }
    if (root->val < target)
    {
        return search(root->right,target);
    }
    return true;
}

Node * inorderSuccessor(Node * root){
    if (root==NULL)
    {
        return NULL;
    }
    while (root->left!=NULL)
    {
        root= root->left;
    }
    return root;
}

Node * delNode(Node * root, int target){
    if (root==NULL)
    {
        return NULL;
    }
     if (root->val>target)
    {
        root->left= delNode(root->left,target);
    }
    else if (root->val < target)
    {
        root->right= delNode(root->right,target);
    } 
    else{
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left==NULL || root->right==NULL)
        {
            return root->left==NULL ? root->right : root->left;
        }
        else{
            Node * IS = inorderSuccessor(root->right);
            root->val = IS->val;
            root->right = delNode(root->right,IS->val);
            return root;
        } 
    }
    return root;
}

void printInRange(Node * root, int start, int end){
    if (root==NULL)
    {
        return;
    }
    if (root->val >=start && root->val <= end)
    {
        printInRange(root->left,start,end);
        cout<<root->val<<", ";
        printInRange(root->right,start,end);
    }
    else if (root->val < start)
    {
        printInRange(root->right,start,end);
    }
    else
    {
        printInRange(root->left,start,end);
    }
}


int main(){
    vector<int> nodes = {5,1,3,4,2,7};
    Node * root = buildBST(nodes);
    inorder(root);
    cout<<endl;
    cout<< search(root, 2);
    cout<< search(root, 6)<<endl;
    delNode(root,5);
    inorder(root);
    cout<<endl;

    printInRange(root,3,7);

    return 0;
}