#include <iostream>
#include <vector>
using namespace std;

int fib(int n,vector<int> &f) {   
    if (f[n]!=-1)
    {
        return f[n];
    }
    
    if (n == 0 || n == 1) {
        return n;
    }
    return f[n]=fib(n - 1,f) + fib(n - 2,f);
}

int main() {
    int n = 6;
    vector<int>f(n+1,-1);
    cout << fib(n,f) << endl;
    return 0;
}
