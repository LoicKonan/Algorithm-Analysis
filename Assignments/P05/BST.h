#pragma once
#ifndef BSTree
#define BSTree

#include <iostream>
using namespace std;

class BSTree
{
private:
    struct Node;

    Node *root;

    void insertNode(Node *&ptr, int x);

    int CalcHeight(Node *&ptr);

    void Find(Node *&ptr, int x);

public:
    BSTree();

    void print(Node *ptr);

    void Find(int x);
    void inOrderPrint();
    void insert(int x);
    int CalcH();
};
