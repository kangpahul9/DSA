#include <iostream>
#include<vector>

using namespace std;

int gridWays(int n, int m, int currN, int currM)
{
    if (currN==n-1 && currM==m-1)
    {
        return 1;
    }
    if (currN>=n || currM>=m)
    {
        return 0;
    }
    
    
    int right=gridWays(n,m,currN,currM+1);
    int down=gridWays(n,m,currN+1,currM);
    return right + down;
}

int main()
{
    int n=3;
    int m=3;

    cout << gridWays(n,m,0,0);
    return 0;
}
