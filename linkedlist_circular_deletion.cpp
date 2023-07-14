#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};
void Traverse(Node *ptr);
Node *FirstDelete(Node *head);
Node *BetDelete(Node *head, int index);
Node *LastDelete(Node *head);
Node *NodeValueDelete(Node *head, int value);
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;
    head->data = 32;
    head->next = second;
    second->data = 34;
    second->next = third;
    third->data = 36;
    third->next = fourth;
    fourth->data = 38;
    fourth->next = fifth;
    fifth->data = 40;
    fifth->next = sixth;
    sixth->data = 42;
    sixth->next = head;
    Traverse(head);
    cout << endl;
    head = FirstDelete(head);
    Traverse(head);
    cout << endl;
    head = BetDelete(head, 2);
    Traverse(head);
    cout << endl;
    head = LastDelete(head);
    Traverse(head);
    cout << endl;
    head = NodeValueDelete(head, 3);
    Traverse(head);
    cout << endl;
    // cout<<head->next->data<<endl;
    return 0;
}
void Traverse(Node *ptr)
{
    Node *head = ptr;
    do
    {
        cout << head->data << endl;
        head = head->next;

    } while (head != ptr);
}
Node *FirstDelete(Node *head)
{
    Node *ptr = head;
    Node *p = head;
    do
    {

        ptr = ptr->next;

    } while (ptr->next != head);
    ptr->next = head->next;
    head = head->next;
    free(p);
    return head;
}
Node *BetDelete(Node *head, int index)
{
    Node *ptr = new Node;
    ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    Node *p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}
Node *LastDelete(Node *head)
{
    Node *ptr = head;
    Node *qtr = head->next;
    do
    {

        ptr = ptr->next;
        qtr = qtr->next;

    } while (qtr->next != head);
    ptr->next = head;
    free(qtr);
    return head;
}
Node *NodeValueDelete(Node *head, int value)
{
    Node *ptr = new Node;
    ptr = head;
    while (ptr->next->data != value && ptr->next->next != head)
    {
        ptr = ptr->next;
    }
    if (ptr->next->data == value)
    {
        Node *p = ptr->next;
        ptr->next = ptr->next->next;
        free(p);
        return head;
    }

    cout << "No. is not in list" << endl;
    return head;
}