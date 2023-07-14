#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    class Node *left;
    class Node *right;
};

Node *createNode(int data)
{
    Node *p1;
    p1 = new Node;
    p1->data = data;
    p1->left = NULL;
    p1->right = NULL;
    return p1;
}

void PreOrderTraverse(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}

int main()
{
    Node *p = createNode(23);
    Node *p1 = createNode(55);
    Node *p2 = createNode(26);
    p->left = p1;
    p->right = p2;
    Node *p3 = createNode(5);
    Node *p4 = createNode(6);
    p1->left = p3;
    p1->right = p4;
    PreOrderTraverse(p);
    return 0;
}