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

Node *searchIter(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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
    Node *ans = searchIter(p,5);
    if (ans == NULL)
    {
        cout << endl
             << "ERRRRRRRRRRR !!!!! NOT PRESENT" << endl;
    }
    else
    {
        cout << endl
             << ans->data << " is present in the tree" << endl;
    }
    return 0;
}