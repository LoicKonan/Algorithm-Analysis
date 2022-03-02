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
 *                          -  Count Sort     O(N)
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

// Function prototype for the Counting Sort.
int countSort(int Array[], int SIZE);            

// Function prototype for the Merge Sort.
void mergeSort(int Array[], int SIZE, int &count); 


// The Size of our Arrays.
const int _SIZE = 5000;

// variable to store the number of comparisons for Merge Sort.
int MergeCount = 0; 


int main()
{
    
}

void fillArray(int arr[], int seed)
{
  srand(seed);
  for (int i = 0; i < _SIZE; i++)
    arr[i] = rand() % 100;
}

// Function to copy an array.
void copyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < _SIZE; i++)
        arr2[i] = arr1[i];
}

// Function to print.
void printArray(int arr[])
{
    for (int i = 0; i < _SIZE; i++)
        cout << setw(4) << arr[i];
    cout << "\n\n";
}

// to swap two array values.
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
