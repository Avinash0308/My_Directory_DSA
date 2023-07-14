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

void insert(Node *root, int key)
{
    static Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "Given key is already present in the tree ::: Unable to Insert" << endl;
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (prev->data < key)
    {
        prev->right = createNode(key);
    }
    else
    {
        prev->left = createNode(key);
    }
}

int main()
{
    // Node *p = createNode(7);
    // Node *p1 = createNode(3);
    // Node *p2 = createNode(6);
    // Node *p3 = createNode(9);
    // Node *p4 = createNode(5);
    // p->left = p4;
    // p->right = p3;
    // p4->left = p1;
    // p4->right = p2;
    // InOrderTraverse(p);
    // cout << endl;
    Node * p = NULL;
    insert(p, 34);
    InOrderTraverse(p);
    return 0;
}