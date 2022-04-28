#pragma

#include <iostream>
using namespace std;

class BST
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

    void insert_Node(Node *&ptr, int x);

    int Tree_Height(Node *&ptr);

    void Find(Node *&ptr, int x);

public:
    BST()
    {
        root = nullptr;
    }

    void Print_inorder(Node *ptr);

    void Find(int x);
    void inOrderPrint();
    void insert(int x);
    int Cal_Height();
};
