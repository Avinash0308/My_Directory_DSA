#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void traverse(int *v, int n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;
}
void merge(int *arr1, int *arr2, int *v, int n, int m)
{

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            v[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            v[k] = arr1[i];
            i++;
            k++;
        }
    }
    while (i < n)
    {
        v[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        v[k] = arr2[j];
        k++;
        j++;
    }
}
int main()
{
    int arr1[] = {2, 3, 4, 5, 67, 76, 87, 98, 99, 100};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    traverse(arr1, n);
    int arr2[] = {1, 3, 5, 6, 76, 87, 90};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    traverse(arr2, m);
    int v[n+m];
    merge(arr1, arr2, v, n, m);
    traverse(v, n+m);
    return 0;
}