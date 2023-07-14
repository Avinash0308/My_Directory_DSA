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

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k;
    vector<int> a(100);
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        a[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        a[k] = arr[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        arr[x] = a[x];
    }
}
void merge_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}
int main()
{
    int a[] = {1, 22, 3, 2, 4, 2, 42, 52, 5, 253, 244};
    int n = sizeof(a) / sizeof(a[0]);
    traverse(a, n);
    merge_sort(a, 0, n - 1);
    traverse(a, n);
    return 0;
}