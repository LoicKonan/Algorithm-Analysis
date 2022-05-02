/******************************************************************************
 * 
 * C++ 11 RB-Tree
 * copyright: https://www.programiz.com/dsa/red-black-tree
 * author: Programiz
 * license: MIT
 * file: RB.hpp
 * last-updated: 07/12/2019
 * Added few functions to make it compatible with our program specification.
 * 
******************************************************************************/

#pragma once
#include<iostream>

using namespace std;

// Global variables to calculate the number of steps for the    
// inserting and searching the tree.  
int insertion_Steps_RB = 0;
int searching_Steps_RB = 0;


/******************************************************************************
 * 
 * This is RBT_Node structure for RB-Tree.
 * It contains the data, parent, left and right pointers.
 * A default Constructor is also provided.
 * 
 *  -     RBT_Node();
 * 
 * And a user-defined constructor is also provided.
 * 
 *  -     RBT_Node(int n);

 * It also contains the color of the node.
 * The color of the node is either red or black.
 * The color of the node is red by default.
 * The color of the node is red when the node is inserted in the tree.
 * The color of the node is black when the node is inserted in the tree. 
 * 
 ******************************************************************************/

struct RBT_Node
{
    int data;
    RBT_Node *parent;
    RBT_Node *left;
    RBT_Node *right;
    int color;

    // Initialize the node with default values
    // set the color of the node to red
    RBT_Node()
    {
        data = -1;
        color = 1;
        parent = left = right = nullptr;
    }

    // Initialize the node with given data
    // set the color of the node to red
    RBT_Node(int n)
    {
        data = n;
        left = right = parent = nullptr;
        color = 1;
    }
};


/******************************************************************************
 * 
 * This a class for RB-Tree.
 * It contains the root pointer.
 * It also contains the functions for different operations such as:
 * 
 *  - void preOrderHelper(RBT_Node* node);
 *  - void inOrderHelper(RBT_Node* node);
 *  - void postOrderHelper(RBT_Node* node);
 *  - void Find(RBT_Node *&ptr, int x);
 *  - void rbTransplant(RBT_Node* u, RBT_Node* v);
 *  - void insertFix(RBT_Node* k);
 *  - void printHelper(RBT_Node* root, string indent, bool last);
 *  - int Tree_Height(RBT_Node *&ptr);
 * 
 *  - RedBlackTree();
 *  - void Find(int x);
 *  - void preorder();
 *  - void in order();
 *  - void postorder();
 *  - void leftRotate(RBT_Node* x);
 *  - void rightRotate(RBT_Node* x);
 *  - void insert(int key);
 *  - RBT_Node* getRoot();
 *  - void printTree();
 *  - int Cal_Height();
 * 
 ******************************************************************************/ 
class RedBlackTree
{
    private:

        RBT_Node* root;
        RBT_Node* TNULL;

        // This function is used to Initialize the parent and the data.
        void initializeNULLNode(RBT_Node* node, RBT_Node* parent)
        {
            node->data = 0;
            node->parent = parent;
            node->left = nullptr;
            node->right = nullptr;
            node->color = 0;
        }

        // Different Private functions prototypes.
        void preOrderHelper(RBT_Node* node);
        void inOrderHelper(RBT_Node* node);
        void postOrderHelper(RBT_Node* node);
        void Find(RBT_Node *&ptr, int x);
        void rbTransplant(RBT_Node* u, RBT_Node* v);
        void insertFix(RBT_Node* k);
        void printHelper(RBT_Node* root, string indent, bool last);
        int Tree_Height(RBT_Node *&ptr);

    public:

        // Default Constructor
        RedBlackTree()
        {
            TNULL = new RBT_Node();
            TNULL->color = 0;
            TNULL->left = nullptr;
            TNULL->right = nullptr;
            root = TNULL;
        }

        // Public Functions Prototypes.
        void Find(int x);
        void preorder();
        void inorder();
        void postorder();
        void leftRotate(RBT_Node* x);
        void rightRotate(RBT_Node* x);
        void insert(int key);
        RBT_Node* getRoot();
        void printTree();
        int Cal_Height();
};


/******************************************************************************
 * 
 * This function is used to print the tree in pre-order.
 * 
 *  - void preorder();
 * 
 ******************************************************************************/ 
void RedBlackTree::preOrderHelper(RBT_Node* node)
{
    if (node != TNULL)
    {
        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

/******************************************************************************
 * 
 * This function is used to print the tree in in-order.
 * 
 *  - void inorder();
 * 
 ******************************************************************************/
void RedBlackTree::inOrderHelper(RBT_Node* node)
{
    if (node != TNULL)
    {
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }
}


/******************************************************************************
 * 
 * This function is used to print the tree in post-order.
 * 
 *  - void postorder();
 * 
 ******************************************************************************/
void RedBlackTree::postOrderHelper(RBT_Node* node)
{
    if (node != TNULL)
    {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }
}

/******************************************************************************
 * 
 * This function is used to find the node with the given data.
 * 
 *  - void Find(RBT_Node *&ptr, int x);
 *  - We also increment the number of searching steps in this function.
 * 
 ******************************************************************************/
void RedBlackTree::Find(RBT_Node *&ptr, int x)
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
        searching_Steps_RB++;
        Find(ptr->left, x);
    }
    else
    {
        searching_Steps_RB++;
        Find(ptr->right, x);
    }
}

/******************************************************************************
 * 
 * This function is used to transplant the node with the given node.
 * 
 *  - void rbTransplant(RBT_Node* u, RBT_Node* v);
 * 
 ******************************************************************************/
void RedBlackTree::rbTransplant(RBT_Node* u, RBT_Node* v)
{
    if (u->parent == nullptr)
    {
        root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}


/******************************************************************************
 * 
 * This function is used to insert the node with the given data.
 * 
 *  - void insertFix(RBT_Node* k);
 * 
 * This function is used to fix the tree after inserting the node by using 
 *  these properties:
 * 
 * 1 - Every node is colored, either red or black.
 * 2 - The root is black.
 * 3 - Every leaf (NIL) is black.
 * 4 - If a red node has children then, the children are always black.
 * 5 - For each node, any simple path from this node to any of its descendant 
 *      leaf has the same black-depth (the number of black nodes).
 * 
 * 
 ******************************************************************************/
void RedBlackTree::insertFix(RBT_Node* k)
{
    insertion_Steps_RB++;

    RBT_Node* u;
    while (k->parent->color == 1)
    {
        if (k->parent == k->parent->parent->right)
        {
            insertion_Steps_RB++;
            u = k->parent->parent->left;

            if (u->color == 1)
            {
                insertion_Steps_RB++;
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->left)
                {
                    insertion_Steps_RB++;
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
            }
        }
        else
        {
            insertion_Steps_RB++;
            u = k->parent->parent->right;

            if (u->color == 1)
            {
                insertion_Steps_RB++;
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->right)
                {
                    insertion_Steps_RB++;
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root)
        {
            break;
        }
    }
    root->color = 0;
}

/******************************************************************************
 * 
 * This function is used to Print the red and black tree and assign the color
 * 
 *  - voidprintHelper(RBT_Node* root, string indent, bool last);
 * 
 ******************************************************************************/
void RedBlackTree::printHelper(RBT_Node* root, string indent, bool last)
{
    if (root != TNULL)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }

        string sColor = root->color ? "RED" : "BLACK";
        cout << root->data << "(" << sColor << ")" << endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
}

/******************************************************************************
 * 
 * This function is Calculate the height of the tree.
 * 
 *  - void Tree_Height(RBT_Node *&ptr);
 * 
 ******************************************************************************/
int RedBlackTree::Tree_Height(RBT_Node *&ptr)
{
    if (ptr)
    {
        int left  = 1 + Tree_Height(ptr->left);
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
 * This function is used to a key in the red black tree.
 * 
 *  - void Find(int x);
 * 
 ******************************************************************************/
void RedBlackTree::Find(int x)
{
    Find(root, x);
}


/******************************************************************************
 * 
 * This function is used to print the preorder of the red black tree.
 * 
 *  - void preorder();
 * 
 ******************************************************************************/
void RedBlackTree::preorder()
{
    cout << "Preorder:  ";
    preOrderHelper(this->root);
}


/******************************************************************************
 * 
 * This function is used to print the In order of the red black tree.
 * 
 *  - void Inorder();
 * 
 ******************************************************************************/
void RedBlackTree::inorder()
{
    cout << "Inorder:   ";
    inOrderHelper(this->root);
}


/******************************************************************************
 * 
 * This function is used to print the postorder of the red black tree.
 * 
 *  - void postorder();
 * 
 ******************************************************************************/
void RedBlackTree::postorder()
{
    cout << "Postorder: ";
    postOrderHelper(this->root);
}


/******************************************************************************
 * 
 * This function is used to rotate the tree to the Left.
 * 
 * - void leftRotate(RBT_Node* x);
 * 
 ******************************************************************************/
void RedBlackTree::leftRotate(RBT_Node* x)
{
    RBT_Node* y = x->right;
    x->right = y->left;

    // 
    if (y->left != TNULL)
    {
        insertion_Steps_RB++;
        y->left->parent = x;
    }
    y->parent = x->parent;

    
    if (x->parent == nullptr)
    {
        insertion_Steps_RB++;
        this->root = y;
    }
    else if (x == x->parent->left)
    {
        insertion_Steps_RB++;
        x->parent->left = y;
    }

    else
    {
        insertion_Steps_RB++;
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}


/******************************************************************************
 * 
 * This function is used to rotate the tree to the Right.
 * 
 * - void rightRotate(RBT_Node* x);
 * 
 ******************************************************************************/
void RedBlackTree::rightRotate(RBT_Node* x)
{
    RBT_Node* y = x->left;
    x->left = y->right;
    if (y->right != TNULL)
    {
        insertion_Steps_RB++;
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        insertion_Steps_RB++;
        this->root = y;
    }
    else if (x == x->parent->right)
    {
        insertion_Steps_RB++;
        x->parent->right = y;
    }
    else
    {
        insertion_Steps_RB++;
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}



/******************************************************************************
 * 
 * This function is used to insert a key in the red black tree.
 * 
 * - void insert(int x);
 * - We also increment the number of steps in the insertion process.
 * 
 ******************************************************************************/
void RedBlackTree::insert(int key)
{
    RBT_Node* node = new RBT_Node();
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    RBT_Node* y = nullptr;
    RBT_Node* x = this->root;

    while (x != TNULL)
    {
        y = x;
        if (node->data < x->data)
        {
            insertion_Steps_RB++;
            x = x->left;
        }
        else
        {
            insertion_Steps_RB++;
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr)
    {
        insertion_Steps_RB++;
        root = node;
    }
    else if (node->data < y->data)
    {
        insertion_Steps_RB++;
        y->left = node;
    }
    else
    {
        insertion_Steps_RB++;
        y->right = node;
    }

    if (node->parent == nullptr)
    {
        insertion_Steps_RB++;
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr)
    {
        return;
    }

    insertFix(node);
}


/******************************************************************************
 * 
 * This function return the root of the tree
 * 
 * - RBT_Node* getRoot();
 * 
 ******************************************************************************/
RBT_Node* RedBlackTree::getRoot()
{
    return this->root;
}


/******************************************************************************
 * 
 * This function is used to print the red black tree.
 * 
 * - void print();
 * 
 ******************************************************************************/
void RedBlackTree::printTree()
{
    if (root)
    {
        printHelper(this->root, "", true);
    }
}


/******************************************************************************
 * 
 * This function is used to calculate the Height of the tree.
 * 
 * - int getHeight();
 * 
 ******************************************************************************/
int RedBlackTree::Cal_Height()
{
    int height = Tree_Height(root);
    return height;
}