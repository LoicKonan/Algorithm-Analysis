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


#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "termcolor.hpp"

#include "countSort.hpp"
#include "radixSort.hpp"

#include "MergeSort.hpp"
#include "quickSort.hpp"
#include "HeapSort.hpp"

#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"

using namespace std;
using namespace std::chrono;


// Function prototype to print the header.
void header();

// Function prototype to fill the Array.
void fillArray(int Array[], int seed);

// Function prototype to copy the Array.
void copyArray(int Array1[], int Array2[]);         

// Function prototype to print the Array.
void printArray(int Array[]); 

// The Size of our Arrays.
const int _SIZE = 5000;

// Driver code
int main() 
{
    // Display the header and Description of the program.
    header();
    
    // Initialize the size(5000) of the arrays.
    int myArray1[_SIZE];
    int myArray2[_SIZE];
    int myArray3[_SIZE];

    // Initialize the counter for bubble sort.
    double bubble_count;

    // Initialize the counter for selection sort.
    double selection_count;

    // Initialize the counter for insertion sort.
    double insertion_count;

    // Initialize the counter for count sort.
    double count_count;



    // CountSort::countSort(copy, n, m);
    // HeapSort::heapSort(copy, n);
    // QuickSort::quickSort(copy, 0, n - 1);
    // RadixSort::radixsort(copy, n);


    return 0;
}




// Function prototype to fill the Array.
void fillArray(int Array[], int seed)
{
    // Seed the random number generator.
    srand(seed);

    // Fill the array with random numbers.
    for (int i = 0; i < _SIZE; i++)
        Array[i] = rand() % 100;
}

// Function prototype to copy the Array.
void copyArray(int Array1[], int Array2[])
{
    // Copy the array.
    for (int i = 0; i < _SIZE; i++)
        Array1[i] = Array2[i];
}       

// Function prototype to print the Array.
void printArray(int Array[])
{
    // Print the array.
    for (int i = 0; i < _SIZE; i++)
        cout << Array[i] << " ";
    cout << endl;
}


void header()
{
    cout << "*****************************************************************************\n";
    cout << "*";
    cout << "\n*    Author:           Loic Konan";
    cout << "\n*    Email:            loickonan.lk@gmail.com";
    cout << "\n*    Label:            Sorting Algorithms";
    cout << "\n*    Title:            Program 2";
    cout << "\n*    Course:           CMPS 5243,  Spring number22, Dr. Johnson";
    cout << "\n*    Semester:         Spring number22";
    cout << "\n*    Description:";
    cout << "\n*";
    cout << "\n*                  This program implements the following sorting algorithms:";
    cout << "\n*";
    cout << "\n*                     - Bubble Sort";
    cout << "\n*                     - Selection Sort";
    cout << "\n*                     - Merge Sort";
    cout << "\n*";
    cout << "\n*";
    cout << "\n*;";
    cout << "\n*    Files:";
    cout << "\n*         main.cpp";
    cout << "\n*";
    cout << "\n*    Usage:";
    cout << "\n*           main.cpp          : driver program";
    cout << "\n*";
    cout << "\n*";
    cout << "\n******************************************************************************\n\n";
}