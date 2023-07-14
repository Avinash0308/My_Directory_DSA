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

Node *search(Node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        if (root->data > key)
        {
            search(root->left, key);
        }
        else
        {
            search(root->right, key);
        }
    }
    else
    {
        return NULL;
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
    Node * ans = search(p,33);
    if(ans == NULL){
        cout<<endl<<"ERRRRRRRRRRR !!!!! NOT PRESENT"<<endl;
    }
    else{
        cout<<endl<<ans->data<<" is present in the tree"<<endl;
    }
    return 0;
}