#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;
    public : 
    void push(int val){
        vec.push_back(val);
        int x = vec.size()-1;
        int parX = (x-1)/2;
        while (parX >=0 && vec[x] > vec[parX])
        {
            swap(vec[x],vec[parX]);
            x=parX;
            parX=(x-1)/2;
        }
        
    }
    void heapify(int idx){
        int largest = idx;
        int left=2*idx+1;
        int right=2*idx+2;
        if (left < vec.size() && vec[left] > vec[largest]) {
        largest = left;
    }
        if (right < vec.size() && vec[right] > vec[largest]) {
        largest = right;
    }
        if (largest == idx) {
        return;
    }
         swap(vec[idx], vec[largest]);
        heapify(largest);
    }
    void pop(){
        if (vec.empty()) return;
        int x = vec.size()-1;
        swap(vec[x],vec[0]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        if (vec.empty()) return -1;
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};

int main(){
    Heap h;
    h.push(50);
    h.push(10);
    h.push(100);
    while (!h.empty())
    {
        cout<<"Top : "<<h.top()<<endl;
        h.pop();

    }
    return 0;
}