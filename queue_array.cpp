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
int isFull(Queue *q)
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
void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(Queue *q)
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
    Queue *q = new Queue;
    q->size = 2;
    q->f = q->r = -1;
    q->arr = new int(q->size);
    enqueue(q, 213);
    enqueue(q, 21);
    dequeue(q);
    dequeue(q);
    return 0;
}