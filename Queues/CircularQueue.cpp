#include <iostream>
using namespace std;

class Queue{
    int arr[100];
    int fr;
    int rear;
    public:
    Queue(){fr=0;rear=0;}
    
    void push(int val){
        if ((rear + 1) % 100 == fr){
            cout << "Queue overflow!" << endl;
            return;
        }
        arr[rear]=val;
        rear=(rear+1)%100;
    }
    void pop(){
        if (empty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
            fr=(fr+1)%100;
    }
    int front(){
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[fr];
    }
    bool empty(){
        return fr==rear ? 1 : 0;
        
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