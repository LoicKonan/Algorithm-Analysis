/**************************************************************************

Tina Johnson CMPS 5243

This program will demonstrate the (n ^ 2) sorting algorithm of the 
Insertion sort.
This program will return the number of comparisons that occur in this
algorithm.

**************************************************************************/

#include <iostream>

namespace InsertionSort
{
  using namespace std;

  // to swap two array values.
  void swap(int &x, int &y)
  {
    int temp = x;
    x = y;
    y = temp;
  }

  int insertionSort(int Array[])
  {
    int insertioncount = 0;
    int i, j, temp;
    for (i = 1; i < _SIZE; i++)
    {
      // Store the value to be inserted into
      // correct position.
      temp = Array[i];
      j = i - 1;
      // Shift values to the right in the
      // array until correct position is found.
      while (j >= 0 && Array[j] > temp)
      {
        Array[j + 1] = Array[j];
        j--;
        insertioncount++;
      }
      // Insert stored value in correct position.
      Array[j + 1] = temp;
    }
    return insertioncount;
  }
}