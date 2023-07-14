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
void insert(int index, int *s, int n, int arr[])
{

    for (int i = index; i < (*s - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[*s - 1] = 0;

    (*s)--;
    display(arr, *s);
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
    int index;
    cout << "Now please tell me the index the value of which you want to delete : ";
    cin >> index;

    insert(index, &s, n, arr);

    return 0;
}