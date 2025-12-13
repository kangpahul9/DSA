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

void preOrder(Node *root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->val<<", ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if (root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->val<<", ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if (root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<", ";
}

void levelOrder(Node * root){
    if (root==NULL)
    {
        return;
    }
    queue<Node * > q;
    q.push(root);
    q.push(NULL);

    while (!(q.empty()))
    {
        Node * currNode=q.front();
        q.pop();
        if (currNode==NULL)
        {
            cout<<endl; 
            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else{
        cout<<currNode->val<<", ";
        if (currNode->left!=NULL)
        {
            q.push(currNode->left);

        }
        if (currNode->right!=NULL)
        {
            q.push(currNode->right);
        }
        }
        
    }
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

int count(Node * root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = count(root->left);
    int rightHeight = count(root->right);
    int currHeight=leftHeight+rightHeight+1;
    return currHeight;
}

int sumOfNodes(Node * root){
    if(root==NULL){
        return 0; 
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    int sum=leftSum+rightSum+root->val;
    return sum;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<height(root)<<endl;
    cout<<count(root)<<endl;
    cout<<sumOfNodes(root)<<endl;

    return 0;
}