#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int data;
    class Stack *next;
};

int isEmpty(Stack *s);
int isFull(Stack *s);
Stack *push(Stack *s, int data);
Stack *pop(Stack *s);
int StackTop(Stack *s);
int StackBottom(Stack *s);
int peek(Stack *s, int i);
void Traverse(Stack *ptr);

int main()
{
    Stack *top = NULL;

    top = push(top, 34);
    top = push(top, 4);
    top = push(top, 3);
    top = push(top, 334);
    top = push(top, 323);
    top = push(top, 31);

    Traverse(top);
    cout << endl;

    top = pop(top);

    Traverse(top);
    cout << endl;

    cout << "The value at position 5 is :- ";
    cout << peek(top, 6) << endl;
    return 0;
}

int isEmpty(Stack *s)
{
    if (s == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *s)
{
    Stack *ptr = new Stack;
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

Stack *push(Stack *s, int data)
{
    if (isFull(s))
    {
        cout << "Stack Overflow" << endl;
        return s;
    }
    else
    {
        Stack *ptr = new Stack;
        ptr->data = data;
        ptr->next = s;
        return ptr;
    }
}

Stack *pop(Stack *s)
{
    if (!isEmpty(s))
    {
        Stack *ptr = new Stack;
        ptr = s->next;
        free(s);
        return ptr;
    }
    cout << "Stack UnderFlow" << endl;
    return s;
}

int StackTop(Stack *s)
{
    return s->data;
}

int StackBottom(Stack *s)
{
    Stack *ptr = s;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int peek(Stack *s, int i)
{
    Stack *ptr = new Stack;
    ptr = s;
    int x = 0;
    while (x < i - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        x++;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    return -1111;
}

void Traverse(Stack *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}