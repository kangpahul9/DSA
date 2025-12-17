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
    int freq;
    Node(){endOfWord=false;freq=1;}
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
            temp->children[ch]->freq++;
            temp=temp->children[ch];
        }
        if (i==key.size()-1)
        {
            temp->endOfWord=true;
        }
        } 
    }
    string getPrefix(string str){
        Node * temp=root;
        string prefix="";
        for (int i = 0; i < str.size(); i++)
        {
            prefix+=str[i];
            if (temp->children[str[i]]->freq==1)
            {
                return prefix;
            }
            else{
                temp=temp->children[str[i]];
            }
        }
        return prefix;
    }
};

void prefixProblem(vector<string>dict){
        Trie t;
        for (int i = 0; i < dict.size(); i++)
        {
            t.insert(dict[i]);
        }
        for (int i = 0; i < dict.size(); i++)
        {
            cout<<t.getPrefix(dict[i])<<endl;
        }
    }

int main(){
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    prefixProblem(words);
    
    return 0;
}