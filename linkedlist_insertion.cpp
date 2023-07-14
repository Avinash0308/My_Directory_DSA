#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};
void Traverse(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
Node *insertatfirst(Node *head, int value)
{
    Node *ptr = new Node;
    ptr->next = head;
    ptr->data = value;
    return ptr;
}
Node *insertatindex(Node *head, int data, int index)
{
    Node *ptr = new Node;
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
Node *insertatlast(Node *head, int data)
{
    Node *ptr = head;
    Node *p = new Node;
    p->data = data;
    while (ptr->next != NULL)
    {

        ptr = ptr->next;
    }

    ptr->next = p;
    p->next = NULL;

    return head;
}
Node *insertafternode(Node *head, Node *prevnode, int data)
{
    Node *ptr = new Node;
    ptr->next = prevnode->next;
    ptr->data = data;
    prevnode->next = ptr;
    return head;
}
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    head->data = 32;
    head->next = second;
    second->data = 34;
    second->next = third;
    third->data = 36;
    third->next = NULL;
    Traverse(head);
    cout << endl
         << endl;
    head = insertatfirst(head, 34);
    Traverse(head);
    cout << endl
         << endl;
    head = insertatindex(head, 23, 2);
    Traverse(head);
    cout << endl
         << endl;
    head = insertatlast(head, 100);
    Traverse(head);
    cout << endl
         << endl;
    head = insertafternode(head, second, 10);
    Traverse(head);
    cout << endl
         << endl;
    // cout<<head->next->data<<endl;
    return 0;
}