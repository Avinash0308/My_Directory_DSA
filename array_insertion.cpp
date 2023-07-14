#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void display(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insert(int index, int value, int *s, int n, int arr[])
{
    if (*s == n)
    {
        cout << "Can't insert the number as array is already full" << endl;
    }
    else
    {
        for (int i = *s - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        (*s)++;
        display(arr, *s);
    }
}
int main()
{
    int n, s, a;
    cout << "Please tell me the size you want to reserve for your array : ";
    cin >> n;
    cout << "Now please input the number of elements you want to fill : ";
    cin >> s;
    int arr[n];
    for (int i = 0; i < s; i++)
    {
        cout << "please enter the number " << (i + 1) << " : ";
        cin >> arr[i];
    }
    display(arr, s);
    int index, value;
    cout << "Now please tell me the index where you want to store the new number : ";
    cin >> index;
    cout << "And the number is : ";
    cin >> value;
    insert(index, value, &s, n, arr);
    display(arr, s);
    return 0;
}