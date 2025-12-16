#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Info {
public:
    bool isBST;
    int min;
    int max;
    int size;
    Info(bool isBST,int min,int max,int size){
        this->isBST = isBST;
        this->max = max;
        this->min = min;
        this->size = size;
    }
};

static int maxSize;
Info * largestBST(Node * root){
    if (root==NULL)
    {
        return new Info(true,INT_MAX,INT_MIN, 0);
    }
    // if (root==NULL)
    // {
    //     return NULL;
    // }
    
    // if (root->left==NULL && root->right == NULL)
    // {
    //     return new Info(true, root->data,root->data,1);
    // }
    
    
    Info * left = largestBST(root->left);
    Info * right  = largestBST(root->right);
    bool currIsBST;
    int currMin = min(root->data, min(left->min,right->min));
    int currMax = max(root->data, max(left->max,right->max));
    int currSize = left->size + right->size + 1;
    if (left->isBST && right->isBST && root->data > left->max && root->data < right->min)
    {
        maxSize = max(maxSize,currSize);
        return new Info(true, currMin, currMax, currSize);
    }
        return new Info(false, currMin, currMax, currSize);
}

int main() {
    Node* root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

     largestBST(root);
    cout << "Max Size : "<<maxSize;
    return 0;
}
