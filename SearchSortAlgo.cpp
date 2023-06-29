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

// search in matrices
vector<int> searchMetrics(vector<vector<int>> &arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();

    int r = 0, c = n - 1;

    while (r < m && c >= 0)
    {
        if (arr[r][c] == target)
        {
            return {r, c};
        }
        if (arr[r][c] < target)
        {
            r++;
        }
        else
        {
            c--;
        }
    }
    return {-1, -1};
}

// binary search in strictly sorted materices

// searches in the row provided between provided colums
vector<int> binarySearchInRow(vector<vector<int>> arr, int row, int s, int e, int target)
{

    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[row][mid] == target)
            return {row, mid};
        if (arr[row][mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return {-1, -1};
}
vector<int> searchmatrices(vector<vector<int>> arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();

    if (n == 1)
    {
        return binarySearchInRow(arr, 0, 0, m - 1, target);
    }

    int rStart = 0;
    int rend = n - 1;
    int rMid;
    int cMid = (m - 1) / 2;
    while (rStart < (rend - 1))
    {
        rMid = rStart + (rend - rStart) / 2;

        if (arr[rMid][cMid] == target)
            return {rMid, cMid};

        if (arr[rMid][cMid] < target)
        {
            rStart = rMid;
        }
        else
        {
            rend = rMid;
        }
    }

    // now you have two row you have to check in them;
    if (arr[rStart][cMid] == target)
        return {rStart, cMid};
    if (arr[rend][cMid] == target)
        return {rend, cMid};

    if (arr[rStart][cMid] > target)
        return binarySearchInRow(arr, rStart, 0, cMid, target);
    if (arr[rend][cMid] < target)
        return binarySearchInRow(arr, rend, cMid, m - 1, target);
    if (arr[rend][0] > target)
        return binarySearchInRow(arr, rStart, cMid, m - 1, target);
    return binarySearchInRow(arr, rend, 0, cMid, target);
}

// MERGE SORT
void Merge(vector<int> &arr, int const s, int const m, int const e)
{
    int const l1 = (m - s) + 1; //*
    int const l2 = e - m;
    int x1[l1];
    int x2[l2];
    for (int i = 0; i < l1; i++) //*
    {
        x1[i] = arr[s + i];
    }
    for (int i = 0; i < l2; i++)
    {
        x2[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = s;

    while (i < l1 && j < l2) //*
    {
        if (x1[i] < x2[j])
        {
            arr[k] = x1[i];
            i++;
        }
        else
        {
            arr[k] = x2[j];
            j++;
        }
        k++;
    }
    while (i < l1)
    {
        arr[k] = x1[i];
        i++;
        k++;
    }
    while (j < l2)
    {
        arr[k] = x2[j];
        j++;
        k++;
    }
}

// INPALCE MERGE FUNCTION
void Merge2(vector<int> &arr, int s, int m, int e)
{

    int val;
    int index;
    int i = s, j = m + 1;
    while (i <= m && j <= e) //*
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            val = arr[j];
            index = j;
            while (index > i)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = val;
            i++;
            m++; //*
            j++;
        }
    }
}

void MergeSort(vector<int> &arr, int const s, int const e)
{
    if (s >= e)
        return;
    int m = s + (e - s) / 2;
    MergeSort(arr, s, m);
    MergeSort(arr, m + 1, e);
    Merge2(arr, s, m, e);
}

// ?? quick Sort algo
void QuickSort2(int arr[], int s, int e)
{

    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    int pivit = arr[mid];
    int i = s, j = e;
    int temp;
    while (i <= j)
    {
        while (arr[i] < pivit)
        {
            i++;
        }
        while (arr[j] > pivit)
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    QuickSort2(arr, s, j);
    QuickSort2(arr, i, e);
}
int Partition(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    int pivit = arr[mid];
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] <= pivit)
            count++;
    }
    int pivitIndex = s + count - 1;
    int temp;

    // swap pivit at right index
    temp = pivit;
    arr[mid] = arr[pivitIndex];
    arr[pivitIndex] = temp;

    int i = s, j = e;
    while (i < pivitIndex && j > pivitIndex)
    {
        while (arr[i] <= pivit)
        {
            i++;
        }
        while (arr[j] > pivit)
        {
            j--;
        }
        if (i < pivitIndex && j > pivitIndex)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivitIndex;
}
void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    // select pivit and make partition of original array
    int p = Partition(arr, s, e);

    // make recursion call on both left and right array
    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}

// Bubble Sort
void BubbleSort(int arr[], int size)
{
    int n = size;
    int temp;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if (flag == false)
            break;
        flag = false;
    }
}
// Selection Sort
void SelectionSort(int *arr, int n)
{

    int max, temp;
    for (int i = 0; i < n; i++)
    {
        int last = (n - 1) - i;
        max = 0;
        for (int j = 0; j <= last; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        temp = arr[last];
        arr[last] = arr[max];
        arr[max] = temp;
    }
}
int main()
{

    int arr[] = {1, 4, 6, 8, 9, 12, 14, 33};
    int arr2[] = {15, 14, 13, 9, 7, 5, 4, 2};
    // vector<int> x = {4, 2, 5, 9, 1, 6, 7, 3, 2, 12, 54};
    int x[] = {4, 2, -5, 9, 1, 6, 7, 3, 2, 12, 54};
    int y[] = {5, 7, 4, 6, 2, 1, 2};
    // MergeSort(x, 0, x.size() - 1);
    // QuickSort2(x, 0, 10);
    // QuickSort2(y, 0, 6);
    // BubbleSort(x, 10);
    SelectionSort(x,10);
    for (auto z : x)
        cout << z << "  ";

    cout << binarySearch(14, arr2, 8) << endl;
    cout << OrderAgnosticBS(arr, 14, 8);
}