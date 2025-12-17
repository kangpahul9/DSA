#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Car{
    public:
    int idx;
    int distSq;
    Car(int idx,int distSq){
        this->idx=idx;
        this->distSq=distSq;
    }
    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq;
    }
};

void nearbyCars(vector<pair<int,int>> pos,int K){
    vector<Car>cars;
    for (int i = 0; i < pos.size(); i++)
    {
         int distSq=( pos[i].first*pos[i].first) + (pos[i].second*pos[i].second);
         cars.push_back(Car(i,distSq));
    }
    priority_queue<Car> pq(cars.begin(),cars.end());

    for (int i = 0; i < K; i++)
    {
        cout << "car: "<<pq.top().idx<<endl;
        pq.pop();
    }
}
int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    nearbyCars(pos,2);
    
    
    cout<<endl;
    return 0;
}