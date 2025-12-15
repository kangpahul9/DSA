#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node * root){
    queue<pair<Node *,int>>q; //node,HD
    map<int,int> m; //HD,node->val
    q.push(make_pair(root,0));
    while (!(q.empty()))
    {
        pair<Node *,int> curr=q.front();
        q.pop();
        Node * currNode = curr.first;
        int currHD = curr.second; 
        if(!(m.count(currHD))){
            m[currHD]=currNode->val;
        }
        if (currNode->left!=NULL)
        {
            pair<Node*,int> leftChild = make_pair(currNode->left,currHD-1);
            q.push(leftChild);
        }
        if (currNode->right!=NULL)
        {
            pair<Node*,int> rightChild = make_pair(currNode->right,currHD+1);
            q.push(rightChild);
        }
    }
    for(auto it : m){
        cout<<it.second<<", ";
    }
    cout<<endl;
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    topView(root);
    return 0;
}