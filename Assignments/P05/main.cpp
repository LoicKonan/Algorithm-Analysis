#include "RB.h"
#include "BST.h"

#include <iostream>
using namespace std;

int main()
{
    RedBlackTree RB_Tree;
    BST Binary_Tree;

    Binary_Tree.insert(500);
    RB_Tree.insert(500);

    int number;
    cout << "The Random numbers: ";
    for (int i = 0; i < 10; i++)
    {
        number = rand() % 100;
        cout << number << " ";
        RB_Tree.insert(number);
        Binary_Tree.insert(number);
    }

    cout << "\n\nRB Below: \n";

    RB_Tree.printTree();
    cout << endl;

    cout << endl;
    RB_Tree.preorder();
    cout << endl;

    RB_Tree.inorder();
    cout << endl;

    RB_Tree.postorder();
    cout << endl;

    cout << "\nRed Black Tree Below: \n";

    cout << "\nHeight of Red Black Tree is " << RB_Tree.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps_RB << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps_RB << "\n\n";

    RB_Tree.Find(66);

    cout << "\n\nHeight of Red Black Tree is " << RB_Tree.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps_RB << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps_RB << endl;

    RB_Tree.insert(855);


    cout << "\n\nBST Below: \n";
    cout << endl;
    Binary_Tree.preorderPrint();

    Binary_Tree.inOrderPrint();
    Binary_Tree.postorderPrint();

    cout << "\nHeight of BST is " << Binary_Tree.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps << "\n\n";

    Binary_Tree.Find(66);

    cout << "\n\nHeight of BST is " << Binary_Tree.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps << endl;

    Binary_Tree.insert(855);
}