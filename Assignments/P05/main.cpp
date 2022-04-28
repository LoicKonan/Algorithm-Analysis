#include "RB.h"
#include "BST.h"

#include <iostream>
using namespace std;

int main()
{
    RedBlackTree Tree_two;
    BST Tree_One;

    Tree_One.insert(500);
    Tree_two.insert(500);

    int number;
    cout << "The Random numbers: ";
    for (int i = 0; i < 10; i++)
    {
        number = rand() % 100;
        cout << number << " ";
        Tree_two.insert(number);
        Tree_One.insert(number);
    }

    cout << "\n\nRB Below: \n";

    Tree_two.printTree();
    cout << endl;

    cout << endl;
    Tree_two.preorder();
    cout << endl;

    Tree_two.inorder();
    cout << endl;

    Tree_two.postorder();
    cout << endl;

    cout << "\nRed Black Tree Below: \n";

    cout << "\nHeight of Red Black Tree is " << Tree_two.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps_RB << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps_RB << "\n\n";

    Tree_two.Find(66);

    cout << "\n\nHeight of Red Black Tree is " << Tree_two.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps_RB << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps_RB << endl;

    Tree_two.insert(855);


    cout << "\n\nBST Below: \n";
    cout << endl;
    Tree_One.preorderPrint();

    Tree_One.inOrderPrint();
    Tree_One.postorderPrint();

    cout << "\nHeight of BST is " << Tree_One.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps << "\n\n";

    Tree_One.Find(66);

    cout << "\n\nHeight of BST is " << Tree_One.Cal_Height() << endl;
    cout << "Number of steps for inserting random numbers is: " << insertion_Steps << endl;
    cout << "Number of steps for searching random numbers is: " << searching_Steps << endl;

    Tree_One.insert(855);
}