#include "BST.h"

#include <iostream>
using namespace std;

void BST::insert_Node(Node *&ptr, int x)
{
    // BCTR++;

    if (ptr == nullptr)
        ptr = new Node(x);
    else if (x <= ptr->data)
        insert_Node(ptr->left, x);
    else
        insert_Node(ptr->right, x);
}

int BST::Tree_Height(Node *&ptr)
{
    if (ptr)
    {
        int left = 1 + Tree_Height(ptr->left);
        int right = 1 + Tree_Height(ptr->right);
        if (left > right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else
    {
        return 0;
    }
}

void BST::Find(Node *&ptr, int x)
{

    if (ptr == NULL)
    {
        cout << "Not found" << endl;
    }
    else if (x == ptr->data)
    {
        cout << "found" << endl;
    }
    else if (x <= ptr->data)
    {
        // BFCT += 1;
        Find(ptr->left, x);
    }
    else
    {
        // BFCT += 1;
        Find(ptr->right, x);
    }
}

void BST::Print_inorder(Node *ptr)
{

    if (ptr)
    {
        Print_inorder(ptr->left);
        cout << ptr->data << " ";
        Print_inorder(ptr->right);
    }
}

void BST::Find(int x)
{
    Find(root, x);
}

void BST::inOrderPrint()
{
    Print_inorder(root);
    cout << endl;
}

void BST::insert(int x)
{
    insert_Node(root, x);
}

int BST::CalcH()
{

    int height = Tree_Height(root);
    return height;
}
