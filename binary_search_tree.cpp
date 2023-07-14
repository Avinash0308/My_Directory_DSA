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

int isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
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
    cout<<endl<<isBST(p);
    cout << endl;
    return 0;
}