#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    ~Node(){
    }
};

class LinkedList{
    Node * head;
    Node * tail;
    public:
    LinkedList() {head=NULL;tail=NULL;}
    void push_front(int data){
        Node * newNode = new Node;
        newNode->data=data;
        newNode->next = head;
        head=newNode;
        if (tail==NULL)
        {
            tail=newNode;
        }
    }
    void push_back(int data){
        Node * newNode = new Node;
        newNode->data=data;
        newNode->next=NULL;
        if (head==NULL)
        {
            head=newNode;
            tail=newNode;
            return;
        }
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
        Node * temp=head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;
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
        Node * temp=head->next;
        delete head;
        head=temp;
    }
    void printList(){
        Node * temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" -> ";
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
    bool iterative_search(int target){
        Node * temp = head;
        while (temp!=NULL)
        {
            if(temp->data==target){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    bool recursiveSearch(int target){
        Node * temp = head;
        return recursiveSearchHelper(temp,target);
    }
    bool recursiveSearchHelper(Node*temp,int target){
        if (temp==NULL)
        {
            return false;
        }
        if (temp->data==target)
        {
            return true;
        }
        return recursiveSearchHelper(temp->next,target);
    }
    void reverse(){
        Node * curr=head;
        tail=head;
        Node * next=NULL;
        Node * prev = NULL;
        while (curr!=NULL)
        {
            next = curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void findRemoveNFromEnd(int number){
        int size = getSize();
        if (number > size || number <= 0)
        return; 
        Node * temp = head;
        
        for (int i = 1; i < (size-number); i++)
        {
            temp=temp->next;
        }
        Node * toDelete=temp->next;
        temp->next=temp->next->next;
        delete toDelete;
        
    }
    void insertAtN(int data,int number){
        int size = getSize();
        if (number <= 0 || number > size + 1)
        return;
        Node * newNode = new Node();
        newNode->data=data;
        newNode->next = NULL;
        if (number == 1) {
        newNode->next = head;
        head = newNode;

        if (tail == NULL) {   
            tail = newNode;
        }
        return;
    }
        Node * temp = head;
        
        for (int i = 1; i < number-1; i++)
        {
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
         if (newNode->next == NULL) {
        tail = newNode;
    }
    }

    ~LinkedList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
    tail = NULL;
}
};

int main(){
    LinkedList ll;
    ll.push_front(2);
    ll.push_back(3);
    ll.push_front(1);
    ll.push_back(4);
    ll.printList();
    // ll.pop_back();
    // ll.printList();
    // ll.pop_front();
    // ll.printList();
    // cout << ll.iterative_search(4);
    // cout << ll.recursiveSearch(2);

    // ll.reverse();
    ll.findRemoveNFromEnd(3);
    ll.printList();

}