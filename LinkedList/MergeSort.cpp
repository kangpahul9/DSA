#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

class LinkedList{
    public:
    Node * head;
    LinkedList() {head=NULL;}
    void push_front(int data){
        Node * newNode = new Node;
        newNode->data=data;
        newNode->next = head;
        head=newNode;
    }
    void push_back(int data){
        Node * newNode = new Node;
        newNode->data=data;
        newNode->next=NULL;
        if (head==NULL)
        {
            head=newNode;
            return;
        }
        Node * temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void pop_back(){
        if (head==NULL)
        {
            return;
        }
        if (head->next==NULL)
        {
            Node * temp=head;
            head=NULL;
            delete temp;
            return;
        }
        Node * temp=head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Node * toDelete = temp->next;
        delete toDelete;
        temp->next=NULL;
    }
    void pop_front(){
        if (head==NULL)
        {
            return;
        }
        if (head->next==NULL)
        {
            Node * temp=head;
            head=NULL;
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
        return;
    }
        Node * temp = head;
        
        for (int i = 1; i < number-1; i++)
        {
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        
    }
    Node * findMid(Node * st){
        Node * prev= NULL;
        Node * fast=st;
        Node * slow = st;
        while (fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (prev!=NULL)
        {
            prev->next=NULL;
        }
         return slow;
    }
    Node * mergeSort(){
        return mergeSortHelper(head);
    }
    Node * merge(Node * left, Node * right){
        LinkedList  ans;
        Node * i=left;
        Node * j = right;
        while (i!=NULL && j!=NULL)
        {
            if (i->data < j->data)
            {
                ans.push_back(i->data);
                i=i->next;
            }
            else{
                ans.push_back(j->data);
                j=j->next; 
            }
        }
        while (i!=NULL)
        {
            ans.push_back(i->data);
            i=i->next;
        }
        while (j!=NULL)
        {
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;
    }
    Node * mergeSortHelper(Node * st){
        if (st==NULL || st->next==NULL)
        {
            return st;
        }
        Node * rightHead= findMid(st);
        Node * left = mergeSortHelper(st);
        Node * right =mergeSortHelper(rightHead);
        return merge(left,right);
    }
};

int main(){
    LinkedList ll;
    ll.push_front(12);
    ll.push_back(32);
    ll.push_front(21);
    ll.push_back(4);
    ll.printList();
    ll.head=ll.mergeSort();
    ll.printList();
}