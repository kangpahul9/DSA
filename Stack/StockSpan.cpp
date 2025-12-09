#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> arr)
{
    vector<int> res;
    stack<int> s;
    res.push_back(1);
    s.push(0);
    for (int i = 1; i < arr.size(); i++)
    {
        while (!(s.empty()) && arr[i] >= arr[s.top()])
        {
            s.pop();
        }
            if (s.empty())
            {
                res.push_back(i + 1);
            }
            else
            {
                res.push_back(i - s.top());
            }
            s.push(i);
        
    }

    return res;
}

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 85, 100};
    vector<int> res = stockSpan(arr);
    for (auto i : res)
    {
        {
            cout << i << ", ";
        }
    }

    return 0;
}