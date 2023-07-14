#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int low, int high)
{

    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {

        while ((arr[i] <= pivot) && (i <= high))
        {
            i++;
        }
        while ((arr[j] > pivot) && (j >= low))
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionindex = partition(arr, low, high);
        quick_sort(arr, low, partitionindex - 1);
        quick_sort(arr, partitionindex + 1, high);
    }
}

int main()
{
    int arr[24];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout<<endl;
    traverse(arr, n);
    cout<<endl;
    quick_sort(arr, 0, n - 1);
    traverse(arr, n);
    cout<<endl;
    return 0;
}