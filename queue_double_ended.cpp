#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
};
void Traverse(Queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}
int BackisFull(Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int FrontisFull(Queue *q)
{
    if (q->f == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(Queue *q)
{
    if (q->f == q->r)
    {
        q->f = q->r = -1;
        return 1;
    }
    else
    {
        return 0;
    }
}
void BackEnqueue(Queue *q, int val)
{
    if (BackisFull(q))
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
void FrontEnqueue(Queue *q, int val)
{
    if (FrontisFull(q))
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        q->arr[q->f] = val;
        q->f--;
    }
}
int BackDequeue(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "Queue Underflow :: ";
    }
    else
    {
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}
int FrontDequeue(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "Queue Underflow :: ";
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    Queue * que = new Queue;
    que->size = 10;
    que->f = -1;
    que->r = -1;
    que->arr = new int(que->size);
    FrontEnqueue(que,34);
    BackEnqueue(que,43);
    BackEnqueue(que,4);
    BackEnqueue(que,3);
    BackDequeue(que);
    FrontDequeue(que);
    FrontEnqueue(que,64);
    Traverse(que);
    return 0;
}