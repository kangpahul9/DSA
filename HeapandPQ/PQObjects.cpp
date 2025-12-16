#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Student{
    public:
    string name;
    int marks;
    Student(string name, int marks){
        this->name=name;
        this->marks=marks;
    }
    bool operator <(const Student &obj) const{
        return this->marks < obj.marks;
    }
};

int main(){
    // priority_queue<string, vector<string>, greater<string>>pq;
    priority_queue <Student> pq;
    pq.push(Student("Pahul",94));
    pq.push(Student("Pavi",95));
    pq.push(Student("Sukhjit",99));
    pq.push(Student("Gurnoor",94));
    while (!(pq.empty()))
    {
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
    
    return 0;
}