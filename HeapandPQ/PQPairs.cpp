#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct comparePair{
    bool operator () (pair<string,int> &p1,pair<string,int> &p2){
        return p2.second > p1.second;
    }
};

int main(){
    // priority_queue<string, vector<string>, greater<string>>pq;
    priority_queue <pair<string,int>,vector<pair<string,int>>,comparePair> pq;
    pq.push(make_pair("Pahul",94 ));
    pq.push(make_pair("Pavi",95));
    pq.push(make_pair("Sukhjit",99));
    pq.push(make_pair("Gurnoor",94));
    while (!(pq.empty()))
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    
    return 0;
}