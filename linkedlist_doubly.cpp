

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
        ;
    }
}

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

    return 0;
}