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
    // cout<<head->next->data<<endl;
    return 0;
}