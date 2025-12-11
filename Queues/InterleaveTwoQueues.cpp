#include <iostream>
#include<queue>
using namespace std;

queue<int> interleave(queue<int> &q){
    queue<int>q2;
    int n=q.size();
    while (q.size()>n/2)
    {
        q2.push(q.front());
        q.pop();
    }
    while (!(q2.empty()))
    {
        q.push(q2.front());
        q.push(q.front());
        q.pop();
        q2.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q = interleave(q);
    while(!(q.empty()))
        {
            cout << q.front() << " ";
            q.pop();
        }
    return 0;
}