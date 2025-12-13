#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
  return p1.second < p2.second;

}

int longestChain(vector<pair<int,int>> numbers){
  vector<pair<int,int>> act;
  sort(numbers.begin(),numbers.end(),compare);
  int ans = 1;
    int currEnd = numbers[0].second;
    for (int i = 1; i < numbers.size(); i++)
    {
       if (numbers[i].first>=currEnd)
       {
         ans++;
         currEnd=numbers[i].second;
       }
    }
    return ans;
}
int main() {
    vector<pair<int,int>> numbers = {
        {5, 24},
        {15, 25},
        {27, 40},
        {50, 60}
    };

    cout << "Longest chain length: "
         << longestChain(numbers) << endl;

    return 0;
}
