#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

void Traverse(Node *head);
Node *InFirst(Node *head, int data);
Node *InIndex(Node *head, int data, int index);
Node *InLast(Node *head, int data);
Node *InAfterNode(Node *head, Node *prevnode, int data);

int main()
{
    Node *head = new Node;

    Node *second = new Node;

    Node *third = new Node;

    Node *fourth = new Node;

    Node *fifth = new Node;

    head->data = 3;
    head->prev = NULL;
    head->next = second;

    second->data = 33;
    second->prev = head;
    second->next = third;

    third->data = 333;
    third->prev = second;
    third->next = fourth;

    fourth->data = 3333;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 33333;
    fifth->prev = fourth;
    fifth->next = NULL;

    Traverse(head);
    cout << endl;

    head = InFirst(head, 1);
    Traverse(head);
    cout << endl;

    head = InIndex(head, 11, 2);
    Traverse(head);
    cout << endl;

    head = InLast(head, 111);
    Traverse(head);
    cout << endl;

    head = InAfterNode(head, third, 1111);
    Traverse(head);
    cout << endl;

    return 0;
}

void Traverse(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->prev;
    }
}

Node *InFirst(Node *head, int data)
{
    Node *ptr = new Node;

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

Node *InIndex(Node *head, int data, int index)
{
    Node *ptr = new Node;
    Node *p = new Node;
    ptr = head;
    int i = 1;
    while (i != index)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->next->prev = p;
    p->next = ptr->next;
    ptr->next = p;
    p->prev = ptr;
    p->data = data;
    return head;
}

Node *InLast(Node *head, int data)
{
    Node *ptr = head;
    Node *p = new Node;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    ptr->next = p;
    p->prev = ptr;
    p->data = data;
    p->next = NULL;
    return head;
}

Node *InAfterNode(Node *head, Node *prevnode, int data)
{
    Node *ptr = head;
    Node *p = new Node;
    while (ptr != prevnode)
    {
        ptr = ptr->next;
    }
    prevnode->next->prev = p;
    p->next = prevnode->next;
    prevnode->next = p;
    p->prev = prevnode;
    p->data = data;
    return head;
}