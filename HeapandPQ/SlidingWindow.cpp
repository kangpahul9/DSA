#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

void maxSubarrayPQ(vector<int>arr,int K){
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<K;i++){
        pq.push(make_pair(arr[i],i));
    }   
    cout<<"Max : "<<pq.top().first<<endl;
    for (int i = K; i < arr.size(); i++)
    {
        while (!pq.empty() && pq.top().second<=i-K)
        {
            pq.pop();
        }
        
        pq.push(make_pair(arr[i],i));
        cout<<"Max : "<<pq.top().first<<endl;
    }
    
}

void maxSubarrayDeque(vector<int> arr, int K){
    deque<int> dq;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!dq.empty() && dq.front()==i-K)
        {
            dq.pop_front();
        }
         while (!dq.empty() && arr[dq.back()]< arr[i]){
            dq.pop_back();
         }
    dq.push_back(i);
    if (i >= K - 1) {
            cout << "Max : " << arr[dq.front()] << endl;
    }
    }
}


int main(){
    vector <int>arr =  {1,3,-1,-3,5,3,6,7};
    maxSubarrayPQ(arr,3);
    cout<<endl;
    maxSubarrayDeque(arr,3);
    cout<<endl;
    return 0;
}