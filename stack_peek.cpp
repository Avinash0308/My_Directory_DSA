#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int top;
    int size;
    int *arr;
};
int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(Stack *ptr)
{
    if (ptr->top + 1 == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void show(Stack *ptr)
{
    cout << "The array is :-" << endl;
    for (int i = 0; i <= ptr->top; i++)
    {
        cout << ptr->arr[i] << " ";
    }
    cout << endl;
}
void push(Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "!!!!Stack Overflow!!!! The stack is full , you can't add any element in it." << endl;
    }
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        show(ptr);
    }
}
void pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "!!!!Stack Underflow!!!! , can't pop" << endl
             << endl;
    }
    else
    {
        cout << "The element " << ptr->arr[ptr->top] << " is popped out" << endl;
        ptr->top--;
        show(ptr);
    }
}
int peek(Stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        cout << "Given index is not present in the array" << endl;
        return -1;
    }
    return ptr->arr[ptr->top - i + 1];
}
int main()
{
    Stack *s = new Stack;
    s->top = -1;
    s->size = 4;
    s->arr = new int(s->size);
    push(s, 34);
    push(s, 32);
    push(s, 31);
    push(s, 3);
    push(s, 4);

    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    for (int i = 0; i < s->top + 1; i++)
    {
        cout << "The value at position " << i + 1 << " is :- " << peek(s, i + 1) << endl;
    }
    return 0;
}