#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxArea(vector<int> arr)
{
    int n=arr.size();
    int ans = 0;
    vector<int>rs(arr.size());
    stack<int>nextSmaller;
    for (int i = arr.size()-1; i >=0 ; i--)
    {
       while (!(nextSmaller.empty()) && arr[nextSmaller.top()]>=arr[i])
       {
        nextSmaller.pop();
       }
       if (nextSmaller.empty())
       {
        rs[i]=(n);
       }
       else{
        rs[i]=nextSmaller.top();
       }
       nextSmaller.push(i);
    }

    vector<int>ls;
    stack<int> leftSmaller;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!(leftSmaller.empty()) && arr[i] <= arr[leftSmaller.top()])
        {
            leftSmaller.pop();
        }
            if (leftSmaller.empty())
            {
                ls.push_back(-1);
            }
            else
            {
                ls.push_back(leftSmaller.top());
            }
            leftSmaller.push(i);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        ans=max(ans,arr[i]*(rs[i]-ls[i]-1));
    }
    

    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout<< maxArea(arr);
    return 0;
}