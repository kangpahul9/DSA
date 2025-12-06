#include <iostream>
using namespace std;

int rotatedSortedArray(int arr[], int st, int end, int target)
{
    int mid = st + (end - st) / 2;
    if (st>end)
    {
        return -1;
    }
    
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[st] <= arr[mid])
    {
        if (arr[st] <= target && arr[mid] >= target) // L1
        {

            return rotatedSortedArray(arr, st, mid - 1, target);
        }
        else
        {
            return rotatedSortedArray(arr, mid + 1, end, target);
        } 
    }
    else
    {
        if (arr[mid] <= target && arr[end] >= target) // L2
        {

            return rotatedSortedArray(arr, mid + 1, end, target);
        }
        else
        {
            return rotatedSortedArray(arr, st, mid - 1, target);
        }
    }
    return -1;
}

int main()
{
    int arr[6] = {2, 5, 6, 8, 1, 7};
    cout << rotatedSortedArray(arr, 0, 5, 7);
    return 0;
}
