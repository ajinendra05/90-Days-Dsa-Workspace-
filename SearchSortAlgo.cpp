#include <bits/stdc++.h>

using namespace std;

int binarySearch(int target, int *arr, int n)
{

    int s = 0;
    int e = n - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int OrderAgnosticBS(int *arr, int target, int n)
{
    int s = 0;
    int e = n - 1;
    bool isAce = arr[s] < arr[e];
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;
        if (isAce)
        {
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        else
        {
            if (arr[mid] > target)
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {1, 4, 6, 8, 9, 12, 14, 33};
    int arr2[] = {15, 14, 13, 9, 7, 5, 4, 2};

    cout<<binarySearch(14,arr2,8)<<endl;
    cout<<OrderAgnosticBS(arr,14,8);
}