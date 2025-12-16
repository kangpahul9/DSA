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


void pathHelper(Node * root, vector<int> &path){
    if (root==NULL)
    {
        return;
    }
    
    path.push_back(root->val);
    if (root->left==NULL && root->right==NULL)
    {
        cout<<"path :";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i]<<", ";
        }
        cout<<endl;
        path.pop_back();
        return;
    }
    else{
    pathHelper(root->left,path);
    pathHelper(root->right,path);}
    path.pop_back();
}
void rootToLeafPath(Node * root){
    vector<int> path;
    pathHelper(root,path);
}

int main(){
    vector<int> nodes = {5,1,3,4,2,7};
    Node * root = buildBST(nodes);
    rootToLeafPath(root);

    return 0;
}