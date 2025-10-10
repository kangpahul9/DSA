#include<iostream>
using namespace std;
void spiralMatrix(int arr[][5], int n){
    int rowStart=0,colStart=0,colEnd=n-1,rowEnd=n-1;
    while (rowStart<=rowEnd && colStart <= colEnd)
    {
        for (int i = colStart; i <=colEnd; i++)
    {
        cout << arr[rowStart][i] << " ";
    }
    rowStart++;

    for (int i = rowStart; i <= rowEnd; i++)
    {
        cout << arr[i][colEnd]<< " ";
    }
    colEnd--;

    for (int i = colEnd; i >= colStart; i--)
    {
        cout << arr[rowEnd][i]<< " ";
    }
    rowEnd--;
    for (int i = rowEnd; i >= rowStart; i--)
    {
        cout << arr[i][colStart]<< " ";
    }
    cout<<endl;
    colStart++;
    }
}

int main(){
    // int n;
    // cin >> n;
    // int arr[n][4];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //     cin >> arr[i][j];
    //     }
        
    // }
    int n = 5;
int arr[5][5] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};
    spiralMatrix(arr, n);
    return 0;
}