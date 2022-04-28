#include "BST.h"

#include <iostream>
using namespace std;


int insertion_Steps = 0;
int searching_Steps = 0; 

void BST::insert_Node(Node *&ptr, int x)
{
    insertion_Steps++;

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
        cout << "Sorry couldn't find" << x << endl;
    }
    else if (x == ptr->data)
    {
        cout << "Found the Number: " << x << endl;
    }
    else if (x <= ptr->data)
    {
        searching_Steps ++;
        Find(ptr->left, x);
    }
    else
    {
        searching_Steps ++;
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

void BST:: Print_preorder(Node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        Print_preorder(ptr->left);
        Print_preorder(ptr->right);
    }
}

void BST::Print_postorder(Node *ptr)
{
    if (ptr)
    {
        Print_postorder(ptr->left);
        Print_postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

void BST::preorderPrint()
{
    cout << "Preorder:  ";
    Print_preorder(root);
    cout << endl;
}

void BST::inOrderPrint()
{
    cout << "Inorder:   ";
    Print_inorder(root);
    cout << endl;
}

void BST::postorderPrint()
{
    cout << "Postorder: ";
    Print_postorder(root);
    cout << endl;
}

void BST::Find(int x)
{
    Find(root, x);
}

void BST::insert(int x)
{
    insert_Node(root, x);
}

int BST::Cal_Height()
{

    int height = Tree_Height(root);
    return height;
}
