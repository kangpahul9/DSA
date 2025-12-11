#include <iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> * next;
    Node(T val){data=val;next=NULL;}
};

template<class T>
class Queue{
    Node<T> * head;
    Node<T> * tail;
    public:
    Queue(){head=NULL;tail=NULL;}
    void push(T val){
        Node<T> * newNode = new Node<T>(val);
        if (head==NULL)
        {
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }
    void pop(){
        Node<T> * temp = head;
        head=head->next;
        delete temp;
    }
    T front(){
        if (empty())
        {
            return -1;
        }
        return head->data;
        
    }
    bool empty(){
        return head==NULL;
    }
};


int main()
{
    Queue<int> q;
    q.push(4);
    q.push(6);
    q.push(1);
    while(!(q.empty()))
        {
            cout << q.front() << " ";
            q.pop();
        }
    return 0;
}