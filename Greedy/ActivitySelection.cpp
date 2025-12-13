#include<iostream>
#include<vector>
using namespace std;

int maxActivities(vector<int> start,vector<int> end){
    int ans = 1;
    int currEnd = end[0];
    for (int i = 1; i < start.size(); i++)
    {
       if (start[i]>=currEnd)
       {
         ans++;
         currEnd=end[i];
       }
       
    }
    return ans;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9}; // already sorted by end time

    cout << "Maximum number of activities: "
         << maxActivities(start, end) << endl;

    return 0;
}
