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

bool helper(Node * root, Node * min, Node * max ){
    if (root==NULL)
    {
        return true;
    }
    
    if (min!=NULL && root->val <= min->val )
    {
        return false;
    }
    if (max!=NULL && root->val >= max->val )
    {
        return false;
    }
    return helper(root->left,min,root) && helper(root->right,root,max);
}


bool validate(Node * root  ){
    return helper(root,NULL,NULL);


}
int main(){
    vector<int> nodes = {5,1,3,4,2,7};
    Node * root = buildBST(nodes);
    cout<< validate(root);
    return 0;
}