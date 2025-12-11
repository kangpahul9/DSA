#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){
    stack<int>s;
    while (!(q.empty()))
    {
        s.push(q.front());
        q.pop();
    }
    while (!(s.empty()))
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(6);
    q.push(1);
    reverse(q);
    while(!(q.empty()))
        {
            cout << q.front() << " ";
            q.pop();
        }
    return 0;
}