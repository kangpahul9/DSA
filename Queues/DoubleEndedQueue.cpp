#include <iostream>
#include<deque>
using namespace std;



int main()
{
    deque<int> d;
    d.push_back(4);
    d.push_front(6);
    d.push_back(1);
    d.pop_front();
    d.pop_front();
    cout << d.front() << " ";
    return 0;
}