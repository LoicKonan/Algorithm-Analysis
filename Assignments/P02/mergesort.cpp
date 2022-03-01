/****************************************
Tina Johnson
CMPS 5243
This program will demonstrate the nlogn 
sorting algorithm, merge sort.
*******************************************/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int SIZE = 10;

void heading();
void fillArray(int a[]);
void printArray(int a[]);
void merge(int lt[], int rt[], int a[], int n);
void mergeSort(int a[], int n);

int main() {  
  int myArray[SIZE];
  heading();
  fillArray(myArray);
  cout << "Array:  \n";
  printArray(myArray);
  mergeSort(myArray, SIZE);
  cout << "Array sorted with Merge Sort: \n";
  printArray(myArray);
  return 0;
}

void heading()
{
  cout << "Tina Johnson \n";
  cout << "CMPS 5243 \n\n";
  cout << "Merge Sort Demo.  Recursively copy array halves\n";
  cout << "into dynamically created arrays until arrays are  \n";
  cout << "of size 1; then merge arrays until the initial  \n";
  cout << "array is sorted. \n\n";
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

/***************************************************
Given a left and right array, values are copied
into larger array, a, of size n in sorted order.
****************************************************/
void merge(int lft[], int rt[], int a[], int n)
{
  int i = 0, j = 0, k = 0;
  int lenLft = n / 2;
  int lenRt = n - lenLft;
  // Copy values in ascencing order into array a
  // until end of either left or right array is 
  // reached.
  while (i < lenLft && j < lenRt)
  {
    if (lft[i] < rt[j])
    {
      a[k] = lft[i];
      i++;
      k++;
    }
    else
    {
      a[k] = rt[j];
      j++;
      k++;
    }
  }
  // Copy any remaining values from the
  // left array.
  while(i < lenLft)
  {      
    a[k] = lft[i];
    i++;
    k++; 
  }
  // Copy any remaining values from the
  // right array. 
  while(j < lenRt)
  {
    a[k] = rt[j];
    j++;
    k++;    
  }  
}


void mergeSort(int a[], int n) 
{ 
  int i, mid, *left, *right;
  if (n >= 2) 
  {
    mid = n / 2;
    // Dynamically create two new arrays to
    // store the left and right halves of array.
    left = new int[mid];
    right = new int[n - mid];
    // Copy into left and right arrays
    for (i = 0; i < mid; i++)
      left[i] = a[i];
    for (i = mid; i < n; i++)
      right[i-mid] = a[i];
    // Recursively sort the left half of the array.
    mergeSort(left, mid);
    // Recursively sort the right half of the array.
    mergeSort(right, n-mid);
    // Merge the array halves.
    merge(left, right, a, n);
  }
}
