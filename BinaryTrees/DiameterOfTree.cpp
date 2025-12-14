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

int height(Node * root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currHeight=max(leftHeight,rightHeight)+1;
    return currHeight;
}

int diameter(Node * root){
    if(root==NULL){
        return 0;
    }
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int currDiameter=height(root->left)+height(root->right)+1;
    return max(currDiameter,max(leftDiameter,rightDiameter));
}

pair<int,int> diameter2(Node * root){
    if(root==NULL){
        return make_pair(0,0) ;
    }
    pair<int,int> leftDiameter = diameter2(root->left);
    pair<int,int> rightDiameter = diameter2(root->right);
    int currDiameter= leftDiameter.second + rightDiameter.second+1;
    int finalDiameter= max(currDiameter,max(leftDiameter.first,rightDiameter.first));
    int finalHt= max(leftDiameter.second,rightDiameter.second)+1;

    return make_pair(finalDiameter,finalHt); 
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    cout<<diameter(root)<<endl;
    pair<int,int> pp=diameter2(root);
    cout<<pp.first;

    return 0;
}