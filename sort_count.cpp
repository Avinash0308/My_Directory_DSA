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
int max_ele(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void count_sort(int *arr, int n, int max)
{
    vector<int> v(max + 1);
    vector<int> v(max + 1);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (v[i])
        {
            arr[j] = i;
            j++;
            v[i]--;
        }
    }
}
int main()
{
    int arr[11];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    traverse(arr, n);
    int max = max_ele(arr, n);
    count_sort(arr, n, max);
    traverse(arr, n);
    return 0;
}