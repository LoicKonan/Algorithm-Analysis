#include <iostream>
using namespace std;

#include "BSTree.h"




int main() 
{
  BSTree b;
  int num, num2, x;
  // b.insert(250);
  for (int i = 0; i < 10; i++) 
  {
    num = rand() % 100;
    num2 = rand() % 1000;
    cout << num << " " << endl;
    b.insert(num);
  }

 // b.inOrderPrint();
  cout << "Height of BST is " << b.CalcH() << endl;
  cout << "Insert count for Bst is " << BCTR << endl;

  cout << "\n\n";
  cout << endl;
  cout << CTR << endl;
  b.Find(35);
  cout << BFCT << endl;
  //r.inOrderPrint();
  //cout << "Height is " << r.treeHeight();
}