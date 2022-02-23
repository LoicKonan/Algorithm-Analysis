/****************************************
Tina Johnson
CMPS 5243
This program will demonstrate the nlogn 
sorting algorithm, quick sort.
*******************************************/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int SIZE = 10;

void heading();
void fillArray(int a[]);
void printArray(int a[]);
int partition(int a[], int beg, int end);
void quickSort(int a[], int p, int r);

int main() {
  int myArray[SIZE];
  heading();
  fillArray(myArray);
  cout << "Original Array:  \n";
  printArray(myArray);
  quickSort(myArray, 0, SIZE);
  cout << "Array sorted with Quick Sort: \n";
  printArray(myArray);
  return 0;
}

void heading()
{
  cout << "Tina Johnson \n";
  cout << "CMPS 5243 \n\n";
  cout << "Quick Sort using the left-most array value \n";
  cout << "as the pivot.  The partition function scans from the \n";
  cout << "opposite end to swap values with the pivot until \n";
  cout << "pivot is in correct position. \n\n";
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

/***************************************************
Initially assigns the pivot position as the left-most 
(sub)array position.  Array is modified so that all 
values less than pivot are to the left of the pivot
and all values greater than pivot are moved to the 
right of the pivot.  The pivot position is returned 
to the calling function.
*****************************************************/

int Partition(int a[], int b, int e)          
{
  // Pivot position assigned to left most position
  int p = b;
  while(b < e)
  {
    // Scan from right
    while(b < e && a[b] <= a[e])
      e--;
    // Swap values and update pivot position
    // if needed.
    if (a[b] > a[e])
    {
      swap(a[b],a[e]);
      p = e;
      b++;
    }
    // Scan from left
    while(b < e && a[b] <= a[e])
      b++;
    // Swap values and update pivot position
    // if needed.
    if (a[b] > a[e])
    {
      swap(a[b], a[e]);
      p = b;
      e--;
    }
  }
  // Return pivot position
  return p;
}

void quickSort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
    // Partition the array
 		q = Partition(a, p, r);   
    // Recursively sort the array to the left of the pivot       
		quickSort(a, p, q - 1);    
    // Recursively sort the array to the right of the pivot      
		quickSort(a, q + 1, r);			    
	}
}
