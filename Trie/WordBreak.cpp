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
        return temp->endOfWord;
    }
    
};

bool helper(Trie &t, string key){
    if (key.size() == 0) return true;
    for (int i = 0; i < key.size(); i++)
    {
        string first = key.substr(0,i+1);
        string second = key.substr(i+1); 
        if (t.search(first) && helper(t,second))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(vector<string> &dictionary,string key){
        Trie t;
        for (string str : dictionary)
        {
            t.insert(str);
        }
        return helper(t, key);
    }

int main(){
    vector<string> words = {"i", "like", "sam", "samsung", "mobile", "phone"};
    
    
    cout<<wordBreak(words,"ilikesamsung");
    
    return 0;
}