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
        cout << "!!!!Stack Underflow!!!! , can't pop" << endl;
    }
    else
    {
        cout << "The element " << ptr->arr[ptr->top] << " is popped out" << endl;
        ptr->top--;
        show(ptr);
    }
}
int StackTop(Stack *ptr){
    return ptr->arr[ptr->top];
}
int StackBottom(Stack *ptr){
    return ptr->arr[0];
}
int main()
{
    Stack *s = new Stack;
    s->top = -1;
    s->size = 5;
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
    cout<<endl<<endl<<"The top most element of the stack is :- "<<StackTop(s)<<endl;
    cout<<endl<<endl<<"The bottom most element of the stack is :- "<<StackBottom(s)<<endl;
    return 0;
}