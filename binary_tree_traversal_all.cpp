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

void PostOrderTraverse(Node *root)
{
    Node *travel = root;
    if (travel != NULL)
    {
        PostOrderTraverse(travel->left);
        PostOrderTraverse(travel->right);
        cout << travel->data << " ";
    }
}

void PreOrderTraverse(Node *root)
{
    Node *travel = root;
    if (travel != NULL)
    {
        cout << travel->data << " ";
        PreOrderTraverse(travel->left);
        PreOrderTraverse(travel->right);
    }
}

void InOrderTraverse(Node *root)
{
    Node *travel = root;
    if (travel != NULL)
    {
        InOrderTraverse(travel->left);
        cout << travel->data << " ";
        InOrderTraverse(travel->right);
    }
}

int main()
{
    Node *p = createNode(7);
    Node *p1 = createNode(0);
    Node *p2 = createNode(4);
    Node *p3 = createNode(1);
    Node *p4 = createNode(2);
    p->left = p4;
    p->right = p3;
    p4->left = p1;
    p4->right = p2;
    PreOrderTraverse(p);
    cout << endl;
    PostOrderTraverse(p);
    cout << endl;
    InOrderTraverse(p);
    cout << endl;
    return 0;
}