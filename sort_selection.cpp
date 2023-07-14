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
void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        int x = i , z=0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                x = j;
                z++;
            }
        }
        if(!z){
            goto end;
        }
        int temp = arr[i];
        arr[i] = arr[x];
        arr[x] = temp;
    }
    end:
    return ;
}
int main()
{
    int arr[] = {23, 1, 4, 1, 52, 53, 2, 2, 4, 2, 5, 3, 53, 5, 3, 53, 5, 32, 5, 6, 5, 2, 674};
    cout << endl;
    cout << "UNSORTED :: ";
    traverse(arr, sizeof(arr) / sizeof(arr[0]));
    selectionsort(arr, sizeof(arr) / sizeof(arr[0]));
    cout << endl
         << "SORTED :: ";
    traverse(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}