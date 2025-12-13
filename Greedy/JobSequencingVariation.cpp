#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Job{
    public:
    int idx;
    int deadline;
    int profit;
    Job(int idx,int deadline, int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
    }
};

void maxProfit(vector<pair<int,int>> pairs){
  vector<Job> jobs;
  for (int i = 0; i < pairs.size(); i++)
  {
    jobs.emplace_back(i,pairs[i].first,pairs[i].second);
  }
  sort(jobs.begin(),jobs.end(),[](Job &a, Job &b){
    return a.profit > b.profit;
  });
  cout<< "Selecting Job "<<jobs[0].idx<<endl;
  int profit = jobs[0].profit;
  int safeDeadline = jobs[0].deadline+1;
  for (int i = 0; i < jobs.size(); i++)
  {
    if (jobs[i].deadline >= safeDeadline)
    {
          cout<< "Selecting Job "<<jobs[i].idx<<endl;
          profit+= jobs[i].profit;
           safeDeadline++;
    }
  }
    cout << "Max Profit: "<<profit;
}
int main() {
    vector<pair<int,int>> jobs = {
        {1, 40},
        {1, 30},
        {1, 20},
        {4, 20}
    };

    
    maxProfit(jobs);
    return 0;
}
