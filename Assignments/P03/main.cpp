/*****************************************************************************
 *
 *    Author:           Loic Konan
 *    Email:            loickonan.lk@gmail.com
 *    Label:            Sorting Algorithms
 *    Title:            Program 2
 *    Course:           CMPS 5243, Spring 2022, Dr. Johnson
 *    Semester:         Spring 2022
 *    Description:
 *
 *                      This program implements the following sorting algorithms:
 *
 *                           - RadixSort Sort O(N)
 *                           - Bubble Sort    O(N ^ 2)
 *                           - QuickSort      O(N log N)
 *                           -  Count Sort     O(N)
 *                           -  R Sort      O(N log N)
 *
 *
 *    Files:
 *         main.cpp
 *
 *    Usage:
 *           main.cpp          : driver program
 *
 *
 ******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <random>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "termcolor.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function prototype for the Heading
void header();

// Function prototype for to fill the arrays with random numbers
void fillArray(int Array[], int seed);

// Function prototype to copy content of array 1 to array 2
void copyArray(int Array1[], int Array2[]);

// Function prototype to print the array
void printArray(int Array[]);

// Function prototype to swap elements.
void swap(int &x, int &y);

// Function prototype for the Bubble Sort.
int bubbleSort(int Array[]);



// Function prototype for the Selection Sort.
int selectionSort(int arr[]);

// Function prototype for the Insertion Sort.
int insertionSort(int arr[]);




// Function prototype for the Counting Sort.
int countSort(int Array[], int SIZE);

// Function prototype for the Merge Sort.
void mergeSort(int Array[], int SIZE, int &count);

// Function prototype
void merge(int lft[], int rt[], int a[], int n, int &count);

// The Size of our Arrays.
const int _SIZE = 5000;

// variable to store the number of comparisons for Merge Sort.
int MergeCount = 0;

int main()
{
}

void fillArray(int Array[], int seed)
{
    srand(seed);
    for (int i = 0; i < _SIZE; i++)
        Array[i] = rand() % 100;
}

// Function to copy an array.
void copyArray(int Array1[], int Array2[])
{
    for (int i = 0; i < _SIZE; i++)
        Array2[i] = Array1[i];
}

// Function to print.
void printArray(int Array[])
{
    for (int i = 0; i < _SIZE; i++)
        cout << setw(4) << Array[i];
    cout << "\n\n";
}

// to swap two array values.
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}


// Function prototype for the Bubble Sort.
int bubbleSort(int Array[])
{
  bool swapped = true;
  int j = 0;

  // Number of comparisons
  int bubblecount = 0;

  // Continue to loop until
  // no swaps have occurred. 
  while (swapped)
  {
    // Reset boolean flag
    swapped = false;
    // Because bubbleSort puts the last 
    // value in the correct position each
    // time through the loop, the limit of
    // the inner loop decreases by one each
    // iteration of the outer loop (SIZE -j)
    for(int i = 1; i < _SIZE - j; i++)
    {
      bubblecount++;
      // compare two side-by-side values
      // and swap if they are out of order
      if(Array[i-1] > Array[i])
      {
        swapped = true;
        swap(Array[i-1], Array[i]);
      }
    }
    j++;
  }
  return bubblecount;
}



int selectionSort(int Array[])
{
  int minIndex;
  int selectioncount = 0;
  for (int i = 0; i < _SIZE; i++)
  {
    // Assume index of smallest value is in the
    // ith position (first value for that iteration)
    minIndex = i;
    for (int j = i + 1; j < _SIZE; j++)
    {
      // If a smaller value is found, update minIndex
      if (Array[j] < Array[minIndex])
        minIndex = j;
        selectioncount++;
    }
    // If smallest number is already in correct position
    // no need to swap.
    if (i != minIndex)
      swap(Array[i], Array[minIndex]);
  }

    return selectioncount;
}


int insertionSort(int Array[])
{
  int i, j, temp;
  int insertioncount = 0;

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
      Array[j+1] = Array[j];
      j--;
    }
    // Insert stored value in correct position.
    Array[j+1] = temp;
  }

    return insertioncount;
}



// Function prototype for the Counting Sort.
int countSort(int Array[], int SIZE);



/***************************************************
Given a left and right array, values are copied
into larger array, a, of size n in sorted order.
****************************************************/
void merge(int lft[], int rt[], int a[], int n, int &count)
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
        MergeCount++;
    }
    // Copy any remaining values from the
    // left array.
    while (i < lenLft)
    {
        a[k] = lft[i];
        i++;
        k++;
        MergeCount++;
    }
    // Copy any remaining values from the
    // right array.
    while (j < lenRt)
    {
        a[k] = rt[j];
        j++;
        k++;
        MergeCount++;
    }
}

void mergeSort(int a[], int n, int &count)
{
    MergeCount++;
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
            right[i - mid] = a[i];
        // Recursively sort the left half of the array.
        mergeSort(left, mid, MergeCount);
        // Recursively sort the right half of the array.
        mergeSort(right, n - mid, MergeCount);
        // Merge the array halves.
        merge(left, right, a, n, MergeCount);
    }
}
