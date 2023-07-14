#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int data;
    class Queue *next;
};
Queue *front = NULL;
Queue *rear = NULL;
int isFull(Queue *n)
{
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Traverse()
{

    while (front != NULL)
    {
        cout << front->data << " ";
        front = front->next;
    }
}
void enqueue(int val)
{
    Queue *n = new Queue;
    if (isFull(n))
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        Queue *ptr = front;
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    enqueue(23);
    enqueue(2);
    enqueue(3);
    cout << "Removed element is :: " << dequeue() << endl;
    ;
    cout << "Removed element is :: " << dequeue() << endl;
    cout << "Removed element is :: " << dequeue() << endl;
    cout << "Removed element is :: " << dequeue() << endl;
    Traverse();
    return 0;
}