// Implementing Red-Black Tree in C++

#pragma once

#include <iostream>
using namespace std;

int insertion_Steps_RB = 0;
int searching_Steps_RB = 0;

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class RedBlackTree
{
private:
    NodePtr root;
    NodePtr TNULL;

    void initializeNULLNode(NodePtr node, NodePtr parent)
    {
        node->data = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = 0;
    }

    // Preorder
    void preOrderHelper(NodePtr node);

    // Inorder
    void inOrderHelper(NodePtr node);

    // Post order
    void postOrderHelper(NodePtr node);

    void Find(Node *&ptr, int x);

    void rbTransplant(NodePtr u, NodePtr v);

    // For balancing the tree after insertion
    void insertFix(NodePtr k);

    void printHelper(NodePtr root, string indent, bool last);

    int Tree_Height(Node *&ptr);

public:
    RedBlackTree()
    {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    void Find(int x);

    void preorder();

    void inorder();

    void postorder();

    void leftRotate(NodePtr x);

    void rightRotate(NodePtr x);

    // Inserting a node
    void insert(int key);

    NodePtr getRoot();

    void printTree();

    int Cal_Height();
};

// Preorder
void RedBlackTree::preOrderHelper(NodePtr node)
{
    if (node != TNULL)
    {
        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

// Inorder
void RedBlackTree::inOrderHelper(NodePtr node)
{
    if (node != TNULL)
    {
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

// Post order
void RedBlackTree::postOrderHelper(NodePtr node)
{
    if (node != TNULL)
    {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }
}

void RedBlackTree::Find(Node *&ptr, int x)
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

void RedBlackTree::rbTransplant(NodePtr u, NodePtr v)
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

// For balancing the tree after insertion
void RedBlackTree::insertFix(NodePtr k)
{
    insertion_Steps_RB++;

    NodePtr u;
    while (k->parent->color == 1)
    {
        if (k->parent == k->parent->parent->right)
        {
            u = k->parent->parent->left;

            if (u->color == 1)
            {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->left)
                {
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
            u = k->parent->parent->right;

            if (u->color == 1)
            {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->right)
                {
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

void RedBlackTree::printHelper(NodePtr root, string indent, bool last)
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

int RedBlackTree::Tree_Height(Node *&ptr)
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

void RedBlackTree::Find(int x)
{
    Find(root, x);
}
void RedBlackTree::preorder()
{
    cout << "Preorder:  ";
    preOrderHelper(this->root);
}

void RedBlackTree::inorder()
{
    cout << "Inorder:   ";
    inOrderHelper(this->root);
}

void RedBlackTree::postorder()
{
    cout << "Postorder: ";
    postOrderHelper(this->root);
}

void RedBlackTree::leftRotate(NodePtr x)
{
    NodePtr y = x->right;
    x->right = y->left;

    if (y->left != TNULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        this->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(NodePtr x)
{
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        this->root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Inserting a node
void RedBlackTree::insert(int key)
{
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL)
    {
        y = x;
        if (node->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr)
    {
        root = node;
    }
    else if (node->data < y->data)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    if (node->parent == nullptr)
    {
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr)
    {
        return;
    }

    insertFix(node);
}

NodePtr RedBlackTree::getRoot()
{
    return this->root;
}

void RedBlackTree::printTree()
{
    if (root)
    {
        printHelper(this->root, "", true);
    }
}

int RedBlackTree::Cal_Height()
{
    int height = Tree_Height(root);
    return height;
}