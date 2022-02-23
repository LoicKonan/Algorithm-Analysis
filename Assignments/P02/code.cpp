// Implement 3 different sorting algorithms on arrays of size 10. 
// You may choose the sorting algorithms, but select one sort from each 
// runtime category: O(n2), O(n log n), O(n)

// Implement a separate counter for each sort. 
// Initialize the counter to zero and increment inside loops of the associated sort. 
// For example, in the O(n2) loop, increment the counter inside the inner loop. 
// Use a system clock timer to start the time immediately before each sort and end immediately after each sort. 
// Once you have the code working for one run, average the time and counter results over 20 runs.


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int SIZE = 10;

void fillArray(int arr[]);
void copyArray(int arr1[], int arr2[]);
void printArray(int arr[]);
void swap(int &x, int &y);
int bubbleSort(int arr[]);
void selectionSort(int arr[]);
void insertionSort(int arr[]);
void radixSort(int arr[]);

int main()
{
  int myArray1[SIZE], myArray2[SIZE], myArray3[SIZE];
  int bubblecount = 0;
  fillArray(myArray1);
  copyArray(myArray1, myArray2);
  copyArray(myArray1, myArray3);
  cout << "Array 1:  \n";
  printArray(myArray1);
  bubblecount = bubbleSort(myArray1);
  cout << "Bubble count:  " << bubblecount << endl;
  cout << "Array 1 sorted with Bubble Sort: \n";
  printArray(myArray1);
  cout << "Array 2:  \n";
  printArray(myArray2);
  selectionSort(myArray2);
  cout << "Array 2 sorted with Selection Sort: \n";
  printArray(myArray2);
  cout << "Array 3:  \n";
  printArray(myArray3);
  insertionSort(myArray3);
  cout << "Array 3 sorted with Insertion Sort: \n";
  printArray(myArray3);
  return 0;
}


