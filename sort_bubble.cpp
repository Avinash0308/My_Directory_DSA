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
void bubblesort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int z = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                z++;
            }
        }
        if (z == 0)
        {
            break;
        }
    }
    return;
}
int main()
{
    int arr[] = {23, 1, 4, 2, 4, 5, 6, 6, 7, 3, 3, 5, 3, 4232, 63, 33};
    int x = sizeof(arr) / sizeof(arr[0]);
    cout << endl
         << "UNSORTED :: ";
    traverse(arr, x);
    bubblesort(arr, x);
    cout << endl
         << "SORTED :: ";
    traverse(arr, x);
    cout << endl;
    return 0;
}