#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    // priority_queue<string, vector<string>, greater<string>>pq;
    priority_queue <string> pq;
    pq.push("helloworld");
    pq.push("apnacollege");
    pq.push("c++");
    pq.push("alpha");
    while (!(pq.empty()))
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    
    return 0;
}