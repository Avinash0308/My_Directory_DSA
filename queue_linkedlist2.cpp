#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int data;
    class Queue *next;
};
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
int isEmpty(Queue *front)
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
void Traverse(Queue *front)
{
    while (front != NULL)
    {
        cout << front->data << " ";
        front = front->next;
    }
    cout<<endl;
}
vector<Queue *> enqueue(Queue *front, Queue *rear, int val)
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
    vector<Queue *> vec;
    vec.push_back(front);
    vec.push_back(rear);
    return vec;
}
Queue *dequeue(Queue *front)
{

    if (isEmpty(front))
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        Queue *ptr = front;
        front = front->next;
        free(ptr);
    }
    return front;
}
int main()
{
    Queue *front = new Queue;
    front = NULL;
    Queue *rear = new Queue;
    rear = NULL;
    vector<Queue *> vec;
    vec = enqueue(front, rear, 2);
    front = vec[0];
    rear = vec[1];
    vec = enqueue(front, rear, 23);
    front = vec[0];
    rear = vec[1];
    vec = enqueue(front, rear, 3);
    front = vec[0];
    rear = vec[1];
    Traverse(front);
    front = dequeue(front);
    front = dequeue(front);
    Traverse(front);
    return 0;
}