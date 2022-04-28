#include <iostream>
#include "BST.h"

using namespace std;

int main()
{

  BST Tree;
  int number;

  // b.insert(250);

  for (int i = 0; i < 10; i++)
  {
    number = rand() % 100;
    cout << number << " " << endl;
    Tree.insert(number);
  }

  // b.inOrderPrint();
  cout << "Height of BST is " << Tree.CalcH() << endl;
  // cout << "Insert count for Bst is " << BCTR << endl;

  cout << "\n\n";
  cout << endl;

  // cout << BCTR << endl;

  Tree.Find(35);

  // cout << BFCT << endl;
  // r.inOrderPrint();
  // cout << "Height is " << r.treeHeight();
}