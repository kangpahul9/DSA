#include<iostream>
using namespace std;
void countingSort(int arr[], int n){
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int count[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }
    int index = 0;
    for (int i = maxVal; i >=minVal; i--)
    {
        while (count[i] > 0) {
    arr[index++] = i;
    count[i]--;
}
    }
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}