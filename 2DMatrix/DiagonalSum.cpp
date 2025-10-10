#include<iostream>
using namespace std;
int diagonalSum(int arr[][5], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i][i];
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int arr[n][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
        cin >> arr[i][j];
        }
        
    }
    cout << diagonalSum(arr, n);
    return 0;
}