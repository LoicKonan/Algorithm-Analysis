#include <iostream>
#include "BST.h"

using namespace std;

int main()
{

  int BCTR;
  int BFCT;

  BST Tree;
  int number;

  Tree.insert(50);

  for (int i = 0; i < 10; i++)
  {
    number = rand() % 100;
    cout << number << " " << endl;
    Tree.insert(number);
  }

  Tree.inOrderPrint();
  cout << "Height of BST is " << Tree.Cal_Height() << endl;
  cout << "Insert count for Bst is " << BCTR << endl;

  cout << "\n\n";
  cout << endl;

  cout << BCTR << endl;

  Tree.Find(35);

  cout << BFCT << endl;
  Tree.inOrderPrint();
}