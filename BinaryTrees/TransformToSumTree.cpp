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


int transform(Node * root){
    if (root==NULL)
    {
        return 0;
    }
    
    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->val;
    root->val=leftOld+rightOld;
    if (root->left!=NULL)
    {
        root->val+=root->left->val;
    }
    if (root->right!=NULL)
    {
        root->val+=root->right->val;
    }
    return currOld;
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
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    transform(root);
    levelOrder(root);

    return 0;
}