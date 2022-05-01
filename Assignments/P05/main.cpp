#include "BST.h"
#include <iostream>
using namespace std;
#include <iostream>

using namespace std;

int main()
{

  BST Tree_One;
  int number;

  Tree_One.insert(50);

  for (int i = 0; i < 10; i++)
  {
    number = rand() % 100;
    cout << number << " " << endl;
    Tree_One.insert(number);
  }

  cout << endl;
  Tree_One.inOrderPrint();
  Tree_One.preorderPrint();
  Tree_One.postorderPrint();


  cout << "\nHeight of BST is " << Tree_One.Cal_Height() << endl;
  cout << "Number of steps for insertion of random numbers is: " << insertion_Steps << endl;
  cout << "Number of steps for searching of random numbers is: " << searching_Steps << "\n\n";

  Tree_One.Find(2);

  cout << "\n\nHeight of BST is " << Tree_One.Cal_Height() << endl;
  cout << "Number of steps for insertion of random numbers is: " << insertion_Steps << endl;
  cout << "Number of steps for searching of random numbers is: " << searching_Steps << endl;

  Tree_One.insert(5);

}