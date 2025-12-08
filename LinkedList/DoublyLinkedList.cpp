#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * prev;
    Node * next;
    ~Node(){
    }
};

class DoublyLinkedList{
    Node * head;
    Node * tail;
    public:
    DoublyLinkedList() {head=NULL;tail=NULL;}
    void push_front(int data){
        Node * newNode = new Node;
        newNode->data=data;
        newNode->prev=NULL;
        newNode->next = head;
        if (head!=NULL)
        {
            head->prev=newNode;
        }
        if (tail==NULL)
        {
            tail=newNode;
        }
        head=newNode;
    }
    void push_back(int data){
        Node * newNode = new Node;
        newNode->data=data;
        newNode->next=NULL;
        if (head==NULL)
        {
        newNode->prev=NULL;
            head=newNode;
            tail=newNode;
            return;
        }
        
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
    void pop_back(){
        if (head==NULL)
        {
            return;
        }
        if (head==tail)
        {
            Node * temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }
        Node * temp=tail;
        tail=temp->prev;
        tail->next=NULL;
        delete temp;
    }
    void pop_front(){
        if (head==NULL)
        {
            return;
        }
        if (head==tail)
        {
            Node * temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }
        Node * temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    void printList(){
        Node * temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" -> <- ";
            temp=temp->next;
        }
        cout << "NULL"<<endl;
    }
    int getSize(){
        int s = 0;Node * temp=head;
        while (temp!=NULL)
        {
            temp=temp->next;
            s++;
        }
        return s;
    }
    
};

int main(){
    DoublyLinkedList dll;
    dll.push_front(2);
    dll.push_back(3);
    dll.push_front(1);
    dll.push_back(4);
    dll.printList();
    dll.pop_back();
    dll.printList();
    dll.pop_front();
    dll.printList();
    
}