#include<iostream>
using namespace std;

void merge(int arr[],int st, int mid, int end){
    int i=st,j=mid+1;
    int temp[end - st + 1];
    int index=0;
    while (i<=mid && j<=end)
    {
        if (arr[i]<=arr[j])
        {
            temp[index]=arr[i];
            i++;
        }
        else{
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    while (i<=mid)
    {
        temp[index]=arr[i];
        i++;
        index++;
    }
    while (j<=end)
    {
        temp[index]=arr[j];
        j++;
        index++;
    }
    for (int k = 0; k < index; k++)
    {
        arr[st + k]=temp[k];
    }
}

void mergeSort(int arr[], int st, int end){
    if (st<end)
    {
        int mid = st + (end-st)/2;
        mergeSort(arr, st, mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}
int main(){
    int arr[5]={2,8,5,3,1};
    mergeSort(arr,0,4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
