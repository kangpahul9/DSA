#include <iostream>
#include <vector>
#include<stack>
using namespace std;
template<class T>
class stackVec
{
private:
    vector<T> vec;

public:
    void push(T val) { vec.push_back(val); }
    void pop() { vec.pop_back(); }
    bool isEmpty()
    {
        if (vec.size() == 0)
        {
            return true;
        }
        return false;
    }
    T top() {if (isEmpty())
        {
            return -1;
        } return vec.back(); }
};
template<class T>
class Node{
    public:
    T data;
    Node * next;
    Node(T val){data=val;next=NULL;}
};

template<class T>
class Stack{
    Node<T> * head;
    public:
    Stack(){head=NULL;}
    void push(T val){
        Node<T> * newNode = new Node<T>(val);
        if (head==NULL)
        {
            head=newNode; 
            return;
        }
        newNode->next=head;
        head=newNode; 
    }
    void pop(){
        if (head==NULL)
        {
            return;
        }
        Node<T> * temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    T top(){
        if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return head->data;}
    bool isEmpty(){
        return head==NULL;
    }
};

template<class T>
void pushAtBottom(stack<T> &s, T val){
    if (s.empty())
    {
        s.push(val);
        return;
    }
    T toBe = s.top();
    s.pop(); 
    pushAtBottom(s,val);
    s.push(toBe);
}

template<class T>
void reverse(stack<T> &s){
    if (s.empty())
    {
        return;
    }
    T toBe = s.top();
    s.pop(); 
    reverse(s);
    pushAtBottom(s,toBe);
}

string reverseString(string str){
    stack<char> ch;
    for (int i = 0; i < str.size(); i++)
    {
        ch.push(str[i]);
    }
    string result;
    while (!(ch.empty()))
    {
        result=result+ch.top();
        ch.pop();
    }
    return result;
}

int main()
{
    stack<int> s;
    s.push(4);
    s.push(6);
    s.push(1);
    pushAtBottom(s,7);
    reverse(s);
    while(!(s.empty()))
        {
            cout << s.top() << " ";
            s.pop();
        }
        string str = "hello";
    cout<<reverseString(str);
    return 0;
}