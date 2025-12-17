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
        return true;
    }
};

bool startsWith(vector<string>dict,string key){
        Trie t;
        for (int i = 0; i < dict.size(); i++)
        {
            t.insert(dict[i]);
        }
        return t.search(key);
    }

int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    
    cout<<startsWith(words,"th");
    return 0;
}