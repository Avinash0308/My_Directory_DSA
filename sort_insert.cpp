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
void InsertionSortMethod1(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
void InsertionSortMethod2(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                goto end;
            }
        }
    end:
        continue;
    }
}
int main()
{
    int arr[] = {23, 1, 4, 1, 52, 53, 2, 2, 4, 2, 5, 3, 53, 5, 3, 53, 5, 32, 5, 6, 5, 2, 674};
    cout << endl;

    cout << "UNSORTED :: ";
    traverse(arr, sizeof(arr) / sizeof(arr[0]));
    // InsertionSortMethod1(arr, sizeof(arr) / sizeof(arr[0]));
    InsertionSortMethod2(arr, sizeof(arr) / sizeof(arr[0]));
    cout << endl;

    cout << "SORTED :: ";
    traverse(arr, sizeof(arr) / sizeof(arr[0]));
    cout<<endl;
    return 0;
}