#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void traverse(int *arr, int n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}
void merge(int *arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    int i = 0;
    int v[n];
    while (arr[i] < arr[i + 1])
    {
        i++;
        mid++;
    }
    i = 0;
    int j = mid + 1;
    while (low <= mid && j <= high)
    {
        if (arr[low] > arr[j])
        {
            v[i] = arr[j];
            j++;
            i++;
        }
        else
        {
            v[i] = arr[low];
            low++;
            i++;
        }
    }
    while (low <= mid)
    {
        v[i] = arr[low];
        low++;
        i++;
    }
    while (j <= high)
    {
        v[i] = arr[j];
        j++;
        i++;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = v[i];
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 23, 32, 5, 9, 22, 121};
    int n = sizeof(arr) / sizeof(arr[0]);
    traverse(arr, n);
    merge(arr,n);
    traverse(arr , n);
    return 0;
}