#include<iostream>
using namespace std;

int partition(int arr[], int st, int end){
    int i = st-1;
    int pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}


void quickSort(int arr[],int st, int end){
    if (st>=end)
    {
       return;
    }
    int pivot = partition(arr,st,end);
    quickSort(arr,st,pivot-1);
    quickSort(arr,pivot+1,end);
}



int main(){
    int arr[5]={2,8,5,3,1};
    quickSort(arr,0,4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
