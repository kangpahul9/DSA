#include<iostream>
using namespace std;
bool searchInSortedMatrix(int arr[][5], int n, int m,int target){
    int i=0;
    while (i<n && m >0)
    {
        int a = arr[i][m-1];
        if (a > target)
        {
        m--;
        }
        else if (a<target)
        {
        i++;
        }
        else{
            cout << "Found at "<<i<<" , "<<m<<endl;
            return true;
        }
    }
    return false;

}

int main(){
    int n = 5;
    int m = 5;
int arr[5][5] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};
int target=21;
    cout<<searchInSortedMatrix(arr, n, m,target);
    return 0;
}