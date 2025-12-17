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
    string longestEOW(){
        string ans="";
        longestHelper(root,ans,"");
        return ans;
    }
    void longestHelper(Node * root, string &ans, string temp){
        for(pair<char,Node *> child : root->children){
            if (child.second->endOfWord)
            {
                temp+=child.first;
            if ((temp.size()==ans.size() && temp < ans)||(temp.size() > ans.size()))
            {
                ans=temp;
            }
            longestHelper(child.second,ans,temp);
            temp=temp.substr(0,temp.size() -1);
            }
            
            
        }
    }
};

string longestSubstring(vector<string> dict)
{
    Trie t;
    for (int i = 0; i < dict.size(); i++)
        {
            t.insert(dict[i]);
        } 
    return t.longestEOW();
}

int main(){
    vector<string> dict = {"a","banana","app","appl","apple","ap","apply"};
    cout<<longestSubstring(dict);
    
    return 0;
}