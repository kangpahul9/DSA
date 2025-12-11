#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int> arr)
{
    int n=arr.size();
    vector<int>res(arr.size());
    stack<int>s;
    for (int i = arr.size()-1; i >=0 ; i--)
    {
       while (!(s.empty()) && arr[s.top()]<=arr[i])
       {
        s.pop();
       }
       if (s.empty())
       {
        res[i]=(-1);
       }
       else{
        res[i]=arr[s.top()];
       }
       s.push(i);
    }
    return res;
}

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 85, 100};
    vector<int> res = nextGreater(arr);
    for (auto i : res)
    {
        {
            cout << i << ", ";
        }
    }

    return 0;
}