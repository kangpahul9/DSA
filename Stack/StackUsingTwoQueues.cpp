#include <iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> s1;
    queue<int>s2;
    public:
    void push(int val){
        while (!(s1.empty()))
        {
            s2.push(s1.front());
            s1.pop();
        }
        s1.push(val);
        while (!(s2.empty()))
        {
            s1.push(s2.front());
            s2.pop();
        }
    }
    void pop(){
        s1.pop();
    }
    int top(){
        return s1.front();
    }
    bool empty(){
        return s1.empty();
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