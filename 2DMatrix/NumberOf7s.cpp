#include<iostream>
using namespace std;
int numberOf7s(int arr[][5], int n, int m,int target){
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]==7)
            {
                count++;
            }
            
        }
        
    }
    
    return count;

}

int main(){
    int n = 5;
    int m = 5;
int arr[5][5] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 7, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};
int target=21;
    cout<<numberOf7s(arr, n, m,target);
    return 0;
}