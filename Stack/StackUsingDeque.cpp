#include <iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> d;
    public:
    void push(int val){
        d.push_back(val);
    }
    void pop(){
        d.pop_back();
    }
    int top(){
        return d.back();
    }
    bool empty(){
        return d.empty();
    }
};


int main()
{
    Stack s;
    s.push(4);
    s.push(6);
    s.push(1);
    while(!(s.empty()))
        {
            cout << s.top() << " ";
            s.pop();
        }
    return 0;
}