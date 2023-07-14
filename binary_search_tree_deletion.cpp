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

Node *inOrderPredecessor(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    Node *iPre = new Node;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    Node *p = createNode(7);
    Node *p1 = createNode(3);
    Node *p2 = createNode(6);
    Node *p3 = createNode(9);
    Node *p4 = createNode(5);
    p->left = p4;
    p->right = p3;
    p4->left = p1;
    p4->right = p2;
    InOrderTraverse(p);
    cout << endl;
    deleteNode(p, 7);
    InOrderTraverse(p);
    cout << endl;
    return 0;
}