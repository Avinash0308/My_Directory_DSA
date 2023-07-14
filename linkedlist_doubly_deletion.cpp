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
Node *DelFirst(Node *head);
Node *DelIndex(Node *head, int index);
Node *DelData(Node *head, int data);
Node *DelLast(Node *head);

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

    head = DelFirst(head);
    Traverse(head);
    cout << endl;

    head = DelIndex(head, 2);
    Traverse(head);
    cout << endl;

    head = DelData(head, 33333);
    Traverse(head);
    cout << endl;

    head = DelLast(head);
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

Node *DelFirst(Node *head)
{
    Node *ptr = head;
    head->next->prev = NULL;
    head = head->next;
    free(ptr);
    return head;
}

Node *DelIndex(Node *head, int index)
{
    Node *ptr = head;
    int i = 1;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    Node *p = ptr->next;
    ptr->next = ptr->next->next;
    ptr->next->prev = ptr;
    free(p);
    return head;
}

Node *DelData(Node *head, int data)
{
    Node *ptr = head;
    while (ptr->data != data && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->data == data && ptr->prev == NULL)
    {
        return DelFirst(ptr);
    }
    if (ptr->data == data && ptr->next == NULL)
    {
        return DelLast(head);
    }
    if (ptr->data == data)
    {
        Node *p = ptr;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(p);
        return head;
    }
    cout << "Given data is not present in the list , that's why showing you the current list" << endl;
    return head;
}

Node *DelLast(Node *head)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Node *p = ptr;
    ptr->prev->next = NULL;
    free(p);
    return head;
}
