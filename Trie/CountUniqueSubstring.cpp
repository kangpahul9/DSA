#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char,Node *> children;
    bool endOfWord;
    Node(){endOfWord=false;}
};

class Trie{
    public: 
    Node * root;
    Trie(){root=new Node();}
    void insert(string key){
        Node * temp=root;
        for (int i = 0;i<key.size();i++)
        {
            char ch = key[i];
            if (temp->children.find(ch)==temp->children.end())
        {
            Node * newNode = new Node();
            temp->children[ch]=newNode;
            temp=temp->children[ch];
        }
        else{
            temp=temp->children[ch];
        }
        if (i==key.size()-1)
        {
            temp->endOfWord=true;
        }
        } 
    }
    int helper(Node * root){
        int ans=0;
        for (pair<char,Node *> child : root->children)
        {
            ans+=helper(child.second);
        }
        return ans+1;
        
    }
    int countNodes(){
        return helper(root);
    }
    bool search(string key){
         Node * temp=root;
        for (int i = 0;i<key.size();i++)
        {
            char ch = key[i];
            if (temp->children.find(ch)==temp->children.end())
        {
            return false;
        }
        else{
            temp=temp->children[ch];
        }
        }
        return temp->endOfWord;
    }
};

int countSubstring(string str)
{
    Trie t;
    for (int i = 0; i < str.size(); i++)
        {
            string suffix = str.substr(i);
            t.insert(suffix);
        } 
        return t.countNodes();
}

int main(){
    string str = "ababa";
    cout<<countSubstring(str);
    
    return 0;
}