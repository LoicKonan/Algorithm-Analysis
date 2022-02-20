/****************************************
Tina Johnson
CMPS 5243
This program will demonstrate n-squared
sorting algorithms:  bubble sort, selection
sort, and insertion sort.
*******************************************/

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

int main() {
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
  cout << "Array 3:  \n";
  printArray(myArray3);
  return 0;
}

void fillArray(int arr[])
{
  srand(time(NULL));
  for(int i = 0; i < SIZE; i++)
    arr[i] = rand() % 100;
}
void copyArray(int arr1[], int arr2[])
{
  for(int i = 0; i < SIZE; i++)
    arr2[i] = arr1[i];
}

void printArray(int arr[])
{
  for(int i = 0; i < SIZE; i++)
    cout << setw(4) << arr[i];
  cout << "\n\n";
}

// Used with bubbleSort and selectionSort 
// to swap two array values.
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int bubbleSort(int arr[])
{
  bool swapped = true;
  int j = 0, c = 0;
  // Continue to loop until
  // no swaps have occurred. 
  while (swapped)
  {
    // Reset boolean flag
    swapped = false;
    // Because bubbleSort puts the last value in the 
    // correct position eachtime through the loop, the 
    // limit of the inner loop decreases by one each
    // iteration of the outer loop (SIZE -j)
    for(int i = 1; i < SIZE - j; i++)
    {
      c++;
      // compare two side-by-side values
      // and swap if they are out of order
      if(arr[i-1] > arr[i])
      {
        swapped = true;
        swap(arr[i-1], arr[i]);
      }
    }
    j++;
  }
  return c;
}