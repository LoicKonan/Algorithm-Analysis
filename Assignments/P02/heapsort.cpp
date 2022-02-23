/****************************************
Tina Johnson
CMPS 5243
This program will demonstrate the nlogn 
sorting algorithm, heap sort.  
*******************************************/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Size one more than needed to begin with 
// index 1 rather than 0.
const int SIZE = 11;

void fillArray(int a[]);
void printArray(int a[]);
int parent(int i);
int left(int i);
int right(int i);
void heapify(int a[], int i, int s);
void buildHeap(int a[]);
void heapSort(int a[]);


int main() {
  int myArray[SIZE];
  fillArray(myArray);
  cout << "Array:  \n";
  printArray(myArray);
  buildHeap(myArray);
  cout << "Heap:  \n";
  printArray(myArray);
  heapSort(myArray);
  cout << "Array sorted with Heap Sort: \n";
  printArray(myArray);
  return 0;
}

void heading()
{
  cout << "Tina Johnson \n";
  cout << "CMPS 5243 \n\n";
  cout << "Heap Sort Demo.  Create a sorted heap by \n";
  cout << "calling heapify on array elements from position \n";
  cout << "n/2 to position 1. \n\n";
}

// Fills an array with random integers from 0-99
void fillArray(int arr[])
{
  srand(time(NULL));
  for(int i = 0; i < SIZE; i++)
    arr[i] = rand() % 100;
}

// Prints the array with each element in a field width
// of 4.  Two extra lines printed after array is printed.
void printArray(int arr[])
{
  for(int i = 0; i < SIZE; i++)
    cout << setw(4) << arr[i];
  cout << "\n\n";
}


// Used to swap two values.
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int parent(int i)
{ return i / 2; }

int left(int i)
{ return i * 2; }

int right(int i)
{ return i * 2 + 1; }

/***********************************************
Given an array and an array position, heapify 
will recursively swap the given element with 
its children to put the element in correct
heap position.
************************************************/ 

void heapify(int a[], int i, int s)
{
  int largest;
  int lft = left(i); 
  int rt = right(i);
  // Find the largest of the given node and
  // its childern
  if (lft <= s && a[lft] > a[i])
    largest = lft;
  else
    largest = i;
  if (rt <= s && a[rt] > a[largest])
    largest = rt;
  // If one of the children is larger than
  // the given node, swap with largest child
  // and recursively call heapify with that 
  // child's position.
  if (largest != i)
  {
    swap(a[i], a[largest]);
    heapify(a, largest, s);
  }
}

void buildHeap(int a[])
{
  // Because leaves are already in heap
  // order by definition, heapify is only
  // necessary for SIZE/2 downto 1.
  for(int i = SIZE/2; i > 0; i--)
    heapify(a, i, SIZE-1);
}

void heapSort(int a[])
{
  int s = SIZE - 1;
  while (s > 0)
  {
    swap(a[1], a[s]);
    s--;
    heapify(a, 1, s);
  }
}
