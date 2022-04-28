#include "BSTree.h"

#include <iostream>
using namespace std;


int BCTR = 0;
int BFCT = 0;

class BSTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int x)
        {
            data = x;
            left = right = nullptr;
        }
    };

    Node *root;

    void insertNode(Node *&ptr, int x)
    {
        BCTR++;

        if (ptr == nullptr)
            ptr = new Node(x);
        else if (x <= ptr->data)
            insertNode(ptr->left, x);
        else
            insertNode(ptr->right, x);
    }

    int CalcHeight(Node *&ptr)
    {
        if (ptr)
        {
            int left = 1 + CalcHeight(ptr->left);
            int right = 1 + CalcHeight(ptr->right);
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

    void Find(Node *&ptr, int x)
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
             BFCT+=1;
            Find(ptr->left, x);
        }
        else
        {
             BFCT+=1;
            Find(ptr->right, x);
        }
    }

public:
    BSTree() 
    { 
        root = nullptr; 
    }

    void print(Node *ptr)
    {

        if (ptr)
        {
            print(ptr->left);
            cout << ptr->data << " ";
            print(ptr->right);
        }
    }

    void Find(int x)
    {
        Find(root, x);
    }

    void inOrderPrint()
    {
        print(root);
        cout << endl;
    }

    void insert(int x) 
    { 
        insertNode(root, x); 
    }

    int CalcH()
    {

        int height = CalcHeight(root);
        return height;
    }
};
