#include "RB.h"
#include "BST.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    RedBlackTree RB_Tree1, RB_Tree2, RB_Tree3;
    BST Binary_Tree1, Binary_Tree2, Binary_Tree3;

    Binary_Tree1.insert(5000);
    RB_Tree1.insert(5000);

    ifstream infile1, infile2, infile3;

    infile1.open("randnums1.txt");
    infile2.open("randnums2.txt");
    infile3.open("randnums3.txt");

    int number;


    // Using a while loop to read in numbers from the file randnums1.txt
   while(infile1)
    {
        infile1 >> number;
        Binary_Tree1.insert(number);
        RB_Tree1.insert(number);
    }

    // Using a while loop to read in numbers from the file randnums2.txt
   while(infile2)
    {
        infile2 >> number;
        Binary_Tree2.insert(number);
        RB_Tree2.insert(number);
    }  
  
  // Using a while loop to read in numbers from the file randnums3.txt
   while(infile3)
    {
        infile3 >> number;
        Binary_Tree3.insert(number);
        RB_Tree3.insert(number);
    }

    int averageRB, averageBST;
  
    int numb, key;

    // Using a for loop to enter randoms number;
    // for(int i = 0; i < 100; i++)
    //   {
    //     numb = rand() % 10000;
    //     RB_Tree1.insert(numb);
    //     Binary_Tree1.insert(numb);
    //   }

    
    // cout << "The Random numbers From the 1st file: \n";
    for (int i = 0; i < 100; i++) 
    {
      int target;
      target = rand() % 10000;
      RB_Tree1.Find(target);
      Binary_Tree1.Find(target);
    
    }

   // cout << "The Random numbers From the 2nd file: \n";
    for (int i = 0; i < 100; i++) 
    {
      int target;
      target = rand() % 10000;
      RB_Tree2.Find(target);
      Binary_Tree2.Find(target);
    
    }

   // cout << "The Random numbers From the 3rd file: \n";
    for (int i = 0; i < 100; i++) 
    {
      int target;
      target = rand() % 10000;
      RB_Tree3.Find(target);
      Binary_Tree3.Find(target);
    
    }
    

    cout << "\n\n\nRed Black Tree Below: ";
    cout << "\n\nHeight of the 1st Red Black Tree using randnums1.txt is " << RB_Tree1.Cal_Height() << endl;
  
  //   cout << "Number of steps for inserting random numbers is in the 1st Red black Tree: " << insertion_Steps_RB << endl;
  //   // cout << "Average Number of steps for inserting random numbers is: " << insertion_Steps_RB / 100 << endl;
  //   cout << "Number of steps for searching random numbers is in the 1st Red black Tree: " << searching_Steps_RB << endl;
  //   // cout << "Average Number of steps for searching random numbers is: " << searching_Steps_RB / 10 << endl;

    cout << "Height of the 2nd Red Black Tree using randnums2.txt is " << RB_Tree2.Cal_Height() << endl;
  
  //   cout << "Number of steps for inserting random numbers is in the 2nd Red black Tree: " << insertion_Steps_RB << endl;
  //   // cout << "Average Number of steps for inserting random numbers is: " << insertion_Steps_RB / 100 << endl;
  //   cout << "Number of steps for searching random numbers is in the 2nd Red black Tree: " << searching_Steps_RB << endl;
  //   // cout << "Average Number of steps for searching random numbers is: " << searching_Steps_RB / 10 << endl;

  cout << "Height of the 3rd Red Black Tree is " << RB_Tree3.Cal_Height() << endl;
  
  //   cout << "Number of steps for inserting random numbers is in the 1st Red black Tree: " << insertion_Steps_RB << endl;
  //   // cout << "Average Number of steps for inserting random numbers is: " << insertion_Steps_RB / 100 << endl;
  //   cout << "Number of steps for searching random numbers is in the 1st Red black Tree: " << searching_Steps_RB << endl;
  //   // cout << "Average Number of steps for searching random numbers is: " << searching_Steps_RB / 10 << endl;

  




  
    cout << "\n\nBinary Search Tree Below: \n";
    cout << "\nHeight of 1st BST is " << Binary_Tree1.Cal_Height() << endl;
    cout << "Height of 2nd BST is " << Binary_Tree2.Cal_Height() << endl;
    cout << "Height of 3rd BST is " << Binary_Tree3.Cal_Height() << endl;

    // cout << "Number of steps for inserting random numbers is: " << insertion_Steps << endl;
    // // cout << "Average Number of steps for inserting random numbers is: " << insertion_Steps << endl;
    // cout << "Number of steps for searching random numbers is: " << searching_Steps << "\n\n";
    // // cout << "Average Number of steps for inserting random numbers is: " << insertion_Steps / 100 << endl;


    ofstream outFile;
    outFile.close();
}