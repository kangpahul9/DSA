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

bool rootToNodePath(Node* root, int x, vector<int>& path) {
    if (root == NULL) 
    {
        return false;
    }

    path.push_back(root->val);

    if (root->val == x) return true;

    if (rootToNodePath(root->left, x, path) ||
        rootToNodePath(root->right, x, path)) {
        return true;
    }

    path.pop_back();   
    return false;
}

int lowestCommonAncestor(Node * root, int a, int b){
    vector<int>path1;
    vector<int>path2;
    rootToNodePath(root,a,path1);
    rootToNodePath(root,b,path2);
    int lca = -1;
    for (int i = 0; i < min(path1.size(),path2.size()); i++)
    {       
        if (path1[i]==path2[i])
        {
            lca=path1[i];
        }
        else{
            break;
        }
    }
    return lca;
}

Node * lca2(Node * root, int a, int b){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->val==a || root->val==b)
    {
        return root;
    }
    Node * leftLCA=lca2(root->left,a,b);
    Node * rightLCA=lca2(root->right,a,b);
    if (leftLCA!=NULL && rightLCA!=NULL)
    {
         return root;
    }
    return leftLCA == NULL ? rightLCA : NULL;    
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = buildTree(nodes);
    

    cout<<lowestCommonAncestor(root,3,6);
    Node * lca = lca2(root,3,6);
    cout << lca->val;

    return 0;   
}