#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x = 0;
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
    int j = x;
    for (int i = (q->f + 1) % q->size; i != q->f && j != 0; i = (i + 1) % q->size, j--)
    {

        cout << q->arr[i] << " ";
    }
    cout << endl;
}
int isFull(Queue *q)
{
    if ((q->r + 1) % q->size == q->f)
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
        q->f = q->r = 0;
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
        cout << "Queue Overflow , can't add :: " << val << endl;
    }
    else
    {

        q->r = (q->r + 1) % q->size;
        if (q->r == q->f)
        {
            q->r++;
        }
        x++;
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
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        x--;
    }
    return a;
}
int main()
{
    Queue *q = new Queue;
    q->size = 10;
    q->f = q->r = 0;
    q->arr = new int(q->size);
    enqueue(q, 213);
    enqueue(q, 21);
    enqueue(q, 211);
    enqueue(q, 231);
    enqueue(q, 241);
    enqueue(q, 11);
    enqueue(q, 621);
    enqueue(q, 0);
    enqueue(q, 31);
    cout << "Element removed is :: " << dequeue(q) << endl;
    Traverse(q);
    enqueue(q, 333);
    enqueue(q, 3);
    cout << "Element removed is :: " << dequeue(q) << endl;
    Traverse(q);
    enqueue(q, 346);
    Traverse(q);
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    cout << "Element removed is :: " << dequeue(q) << endl;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    Traverse(q);
    return 0;
}