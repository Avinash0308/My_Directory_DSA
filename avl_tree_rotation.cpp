#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int getHeight(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

Node *createNode(int key)
{
    Node *node = new Node;
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

int getBalFac(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return y;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balFac = getBalFac(node);

    // LeftLeft
    if (balFac > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // RightRight
    if (balFac < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // LeftRight
    if (balFac > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RightLeft
    if (balFac < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node *node)
{
    if (node != NULL)
    {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 34);
    root = insert(root, 54);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 14);
    root = insert(root, 74);
    root = insert(root, 94);
    preOrder(root);
    return 0;
}