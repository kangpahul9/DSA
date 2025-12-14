#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

bool isIdentical(Node *root, Node *subRoot)
{
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    if (root == NULL || subRoot == NULL)
    {
        return false;
    }
    if (root->val != subRoot->val)
        return false;

    return isIdentical(root->left, subRoot->left) &&
           isIdentical(root->right, subRoot->right);
}

bool isSubtree(Node *root, Node *subRoot)
{
    if (subRoot == NULL)
        return true;
    if (root == NULL)
        return false;
    if (root->val == subRoot->val)
    {
        return isIdentical(root, subRoot);
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    vector<int> rootNodes = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    Node *root = buildTree(rootNodes);
    vector<int> subRootNodes = {
        3, 4, -1, -1, 5, -1, -1
    };

    idx = -1;                  // reset index again
    Node* subRoot = buildTree(subRootNodes);

    if (isSubtree(root, subRoot))
        cout << "subRoot is a subtree of root" << endl;
    else
        cout << "subRoot is NOT a subtree of root" << endl;

    return 0;
}