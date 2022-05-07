/******************************************************************************
 * 
 * C++ 11 Bst-Tree
 * copyright: https://replit.com/@tina_johnson/BST?v=1#BSTree.cpp
 * author: Tina Johnson
 * file: BST.hpp
 * Added few functions to make it compatible with our program specification.
 * 
******************************************************************************/


#pragma once
#include <iostream>
using namespace std;

// Global variables to calculate the number of steps for the    
// inserting and searching the tree.  
int insertion_Steps_BST = 0;
int searching_Steps_BST = 0; 


/******************************************************************************
 * This is the This is BT_Node structure for BST-Tree.
 * It contains the data, and left & right pointers.
 * A default Constructor is also provided.
 * 
 *  -    BT_Node(int x)
 * 
 * 
 ******************************************************************************/
struct BT_Node
{
    int data;
    BT_Node *left;
    BT_Node *right;

    BT_Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

/******************************************************************************
 * 
 * This is a Binary Search-Tree class.
 * It contains the root pointer.
 * 
 * It also contains the functions for different operations such as:
 * 
 *  - void insert_Node(BT_Node *&ptr, int x);
 *  - int Tree_Height(BT_Node *&ptr);
 *  - void Find(BT_Node *&ptr, int x);
 * 
 *  - BinarySearchTree(){root = nullptr;}
 *  - void Print_preorder(BT_Node *ptr);
 *  - void Print_inorder(BT_Node *ptr);
 *  - void Print_postorder(BT_Node *ptr);
 *  - void Find(int x);
 *  - void inOrderPrint();
 *  - void preorderPrint();
 *  - void postorderPrint();
 *  - void insert(int x);
 *  - int Cal_Height();
 *  - void printTree(BT_Node *root,string indent, bool last);
 * 
 * 
 ******************************************************************************/
class BinarySearchTree
{
    private:

        BT_Node *root;

        void insert_Node(BT_Node *&ptr, int x);
        int Tree_Height(BT_Node *&ptr);
        void Find(BT_Node *&ptr, int x);

    public:

        BinarySearchTree(){root = nullptr;}
        void Print_preorder(BT_Node *ptr);
        void Print_inorder(BT_Node *ptr);
        void Print_postorder(BT_Node *ptr);
        void Find(int x);
        void inOrderPrint();
        void preorderPrint();
        void postorderPrint();
        void insert(int x);
        int Cal_Height();
        void printTree(BT_Node *root,string indent, bool last);
};


/******************************************************************************
 * 
 * This is the function to insert a node in the tree.
 * It takes the root pointer and the data to be inserted.
 * 
 *  - void insert_Node(BT_Node *&ptr, int x)
 *  - We use the pointer to the root of the tree as a reference.
 *  - We also increment the number of steps for the inserting operation.
 * 
 * 
 ******************************************************************************/
void BinarySearchTree::insert_Node(BT_Node *&ptr, int x)
{
    insertion_Steps_BST++;

    if (ptr == nullptr)
        ptr = new BT_Node(x);

    else if (x <= ptr->data)
        insert_Node(ptr->left, x);

    else
        insert_Node(ptr->right, x);
}

/******************************************************************************
 * 
 * This is the function to find the height of the tree.
 * It takes the root pointer as a parameter.
 * 
 *  - int Tree_Height(BT_Node *&ptr)
 *  - We use the pointer to the root of the tree as a reference.
 * 
 * 
 ******************************************************************************/
int BinarySearchTree::Tree_Height(BT_Node *&ptr)
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


/******************************************************************************
 * 
 * This is the function to find the node in the tree.
 * It takes the root pointer and the data to be searched.
 * 
 *  - void Find(BT_Node *&ptr, int x)
 *  - We use the pointer to the root of the tree as a reference. 
 *  - We also increment the number of steps for the searching operation.
 * 
 ******************************************************************************/
void BinarySearchTree::Find(BT_Node *&ptr, int x)
{
    if (ptr == NULL)
    {
        cout << "Sorry couldn't find the number: '" << x << "' in the tree.\n";
    }
    else if (x == ptr->data)
    {
        cout << "Found the number: '" << x << "' in the tree.\n";
    }
    else if (x <= ptr->data)
    {
        searching_Steps_BST++;
        Find(ptr->left, x);
    }
    else
    {
        searching_Steps_BST++;
        Find(ptr->right, x);
    }
}


/******************************************************************************
 * 
 * This is the function to print the tree in preorder.
 * It takes the root pointer as a parameter.
 * 
 *  - void Print_preorder(BT_Node *ptr)
 *  - We use the pointer to the root of the tree as a reference.
 * 
 * 
 ******************************************************************************/
void BinarySearchTree::Print_inorder(BT_Node *ptr)
{
    if (ptr)
    {
        Print_inorder(ptr->left);
        cout << ptr->data << " ";
        Print_inorder(ptr->right);
    }
}


/******************************************************************************
 * 
 * This is the function to print the tree in preorder.
 * It takes the root pointer as a parameter.
 * 
 *  - void Print_preorder(BT_Node *ptr)
 *  - We use the pointer to the root of the tree as a reference.
 * 
 * 
 ******************************************************************************/
void BinarySearchTree:: Print_preorder(BT_Node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        Print_preorder(ptr->left);
        Print_preorder(ptr->right);
    }
}


/******************************************************************************
 * 
 * This Function is used to print the nodes in a in Postorder fashion.
 * 
 * - void Print_postorder();
 * 
 ******************************************************************************/
void BinarySearchTree::Print_postorder(BT_Node *ptr)
{
    if (ptr)
    {
        Print_postorder(ptr->left);
        Print_postorder(ptr->right);
        cout << ptr->data << " ";
    }
}


/******************************************************************************
 * 
 * This Function is used to print the nodes in a in Preorder fashion.
 * 
 * - void preoderPrint();
 * 
 ******************************************************************************/
void BinarySearchTree::preorderPrint()
{
    cout << "Preorder:  ";
    Print_preorder(root);
    cout << endl;
}


/******************************************************************************
 * 
 * This Function is used to print the nodes in a in order fashion.
 * 
 * - void inOrderPrint();
 * 
 ******************************************************************************/
void BinarySearchTree::inOrderPrint()
{
    cout << "Inorder:   ";
    Print_inorder(root);
    cout << endl;
}


/******************************************************************************
 * 
 * This Function is used to print the nodes in a postorder fashion.
 * 
 *  - void postorderPrint()
 * 
 ******************************************************************************/
void BinarySearchTree::postorderPrint()
{
    cout << "Postorder: ";
    Print_postorder(root);
    cout << endl;
}


/******************************************************************************
 * 
 * This Function is used to Find a node in the tree.
 * 
 * - void Find( int x)
 * 
 ******************************************************************************/
void BinarySearchTree::Find(int x)
{
    Find(root, x);
}


/******************************************************************************
 * 
 * This function is to insert a node in the tree
 * 
 * - void insert(int x)
 * 
 * 
 ******************************************************************************/
void BinarySearchTree::insert(int x)
{
    insert_Node(root, x);
}


/******************************************************************************
 * 
 * This function calculates the height of the tree and returns the height.
 *  - int Cal_Height()
 * 
 ******************************************************************************/
int BinarySearchTree::Cal_Height()
{
    int height = Tree_Height(root);
    return height;
}