#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
    string key;
    int val;
    Node * next;
    Node(string key, int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
    }
    ~Node(){
        if (next!=NULL)
        {
            delete next;
        }
        
    }
};

class HashTable{
    int totalSize;
    int currSize;
    Node **table;
    int hashFunction(string key){
        int idx=0;
        for (int i = 0; i < key.size(); i++)
        {
            idx+=(key[i]*key[i]) %  totalSize;
        }
        return idx%totalSize;
    }
    void rehash(){
        Node ** oldTable = table;
        int oldSize = totalSize;
        totalSize=2*totalSize;
        table = new Node *[totalSize];
        currSize=0;
        for(int i=0;i<totalSize;i++){
            table[i]=NULL;
        }
        for (int i = 0; i < oldSize; i++)
        {
            Node * temp= oldTable[i];
            while (temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if (oldTable!=NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }
    public: 
    HashTable(int totalSize){
        this->totalSize=totalSize;
        this->currSize=0;
        table = new Node * [totalSize];
        for(int i=0;i<totalSize;i++){
            table[i]=NULL;
        }
    }
    void insert(string key, int val){
        int idx = hashFunction(key); 
        Node * newNode = new Node(key,val);
        newNode->next=table[idx];
        table[idx]=newNode;
        currSize++;
        double lamda = (double)currSize/totalSize;
        if (lamda > 1)
        {
            rehash();
        }
        
    }
    bool exists(string key){
        int idx = hashFunction(key);
        Node * temp = table[idx];
        while (temp!=NULL)
        {
            if (temp->key==key)
            {
                return true;
            }
        }
        return false;
    }
    void remove(string key){
        int idx = hashFunction(key);
        Node * temp = table[idx];
        Node * prev=temp;
        while (temp!=NULL){
            if (temp->key==key)
            {
                if (prev==temp)
                {
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                
            }
            prev=temp;
            temp=temp->next;
        }
    }
    void print(){
        for(int i=0;i<totalSize;i++){
            cout << "idx "<<i<<"->";
            Node * temp = table[i];
            while (temp!=NULL)
            {
                cout<<"("<<temp->key<<", "<<temp->val<<") -> ";
                temp=temp->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int search(string key){
        int idx = hashFunction(key);
        Node * temp = table[idx];
        while (temp!=NULL)
        {
            if (temp->key==key)
            {
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
};

int main() {
    HashTable ht(5);

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    if (ht.exists("India"))
    {
        cout << "India population: "<<ht.search("India")<<endl;
    }
    ht.print();
    ht.remove("UK");
    ht.print();
    return 0;
}