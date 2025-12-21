#include <iostream>
#include <vector>
using namespace std;

int ways(int n,vector<int> &f) {   
    if (f[n]!=-1)
    {
        return f[n];
    }
    
    if (n == 0 || n == 1) {
        return 1;
    }
    return f[n]=ways(n - 1,f) + ways(n - 2,f);
}

int ways2(int n) {   
    vector<int>f(n+1,0);
    f[0]=1;
    f[1]=1;
    for (int i = 2; i <=n; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int waysfor3(int n,vector<int> &f) {  
    if (n < 0) return 0; 
    if (f[n]!=-1)
    {
        return f[n];
    }
    
    if (n == 0 || n == 1) {
        return 1;
    }
    if (n==2)
    {
        return 2;
    }
    
    return f[n]=waysfor3(n - 1,f) + waysfor3(n - 2,f) + waysfor3(n-3,f);
}

int ways2ForThree(int n) {   
    vector<int>f(n+1,0);
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for (int i = 3; i <=n; i++)
    {
        f[i]=f[i-1]+f[i-2]+f[i-3];
    }
    return f[n];
}

int main() {
    int n = 4;
    vector<int>f(n+1,-1);
    cout << ways(n,f) << endl;
    cout << ways2(n) << endl;
    vector<int>f1(n+1,-1);
    cout << waysfor3(n,f1) << endl;
    cout << ways2ForThree(n) << endl;

    return 0;
}
