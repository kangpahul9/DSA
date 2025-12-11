#include <iostream>
#include<deque>
using namespace std;

class Queue{
    deque<int> d;
    public:
    void push(int val){
        d.push_back(val);
    }
    void pop(){
        d.pop_front();
    }
    int front(){
        return d.front();
    }
    bool empty(){
        return d.empty();
    }
};


int main()
{
    Queue q;
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