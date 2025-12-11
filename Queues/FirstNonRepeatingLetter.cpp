#include <iostream>
#include<queue>
#include<stack>
using namespace std;

char firstNonRepeat(string str){
    int freq[26]={0};
    queue<char> q;
    for (char ch : str)
    {
            freq[ch - 'a']++;
            q.push(ch);

            while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
    }
    
    
    return q.empty() ? '#' : q.front();
}

int main()
{
    string str = "aabccbbxcad";
    
    cout << firstNonRepeat(str);
    return 0;
}