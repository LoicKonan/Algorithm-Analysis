/*****************************************************************************
 *
 *    Author:           Loic Konan
 *    Email:            loickonan.lk@gmail.com
 *    Label:            Sorting Algorithms
 *    Title:            Program 2
 *    Course:           CMPS 5243, Spring number22, Dr. Johnson
 *    Semester:         Spring number22
 *    Description:
 *
 *                      This program implements the following sorting algorithms:
 *
 *                           - Selection Sort
 *                           - Bubble Sort
 *                           - QuickSort
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

const int _SIZE    = 5000;
int quickcount     = 0;
int RadixCount     = 0;

double quick_time  = 0.0;
double radix_time  = 0.0;
double bubble_time = 0.0;

// Function prototype to fill the Arrays.
void fillArray(int arr[]);

// Funtion prototype to copy the Arrays.
void copyArray(int arr1[], int arr2[]);

// Function prototype to print the Arrays.
void printArray(int arr[]);

// Function prototype to swap the values of two integers.
void swap(int &x, int &y);

// Function prototype to sort the Arrays using Bubble Sort.
int bubbleSort(int arr[]);

// Function prototype for partitioning the Arrays.
int partition (int arr[], int low, int high, int &quickcount);

// Function prototype to sort the Arrays using Quick Sort.
void quickSort(int arr[], int low, int high);

// Function prototype to sort the Arrays using Radix Sort.
void radixsort(int arr[], int n);

// Function prototype to sort the Arrays using Counting Sort.
void countSort(int arr[], int n, int exp);

// Function prototype to print the header.
void header();

// Main function.
int main()
{   
    // Initialize the arrays.
    int myArray1[_SIZE];
    int myArray2[_SIZE];
    int myArray3[_SIZE];


    // Initialize the counters.
    int bubblecount;

    // average time for each algorithm.
    double average_radix_Time = 0.0;
    double average_quick_Time = 0.0;
    double average_bubble_Time = 0.0;

    // average number of comparisons for each algorithm.
    double average_radix_Count = 0.0;
    double average_quick_Count = 0.0;
    double average_bubble_Count = 0.0;

    // n is the size of the array.
    int n = sizeof(myArray3) / sizeof(myArray3[0]);

    // Call the fillArrays function.
    fillArray(myArray1);

    // Call the copyArrays function, and pass the arrays.
    copyArray(myArray1, myArray2);
    copyArray(myArray1, myArray3);

    // Print the header.
    header();


    int number = 20;

    while(number)
    {
    
    bubble_time *= 1e-9;
    bubblecount = bubbleSort(myArray1);
    cout << "Bubble count:  "    << bubblecount << endl; 
    cout << "Time Complexity: "  << termcolor::green << fixed
         << bubble_time << setprecision(9) << termcolor::reset << " sec\n" <<  endl;



    quick_time *= 1e-9;
    quickSort(myArray2, 0, _SIZE - 1);
    cout << "QuickSort count:  " << quickcount << endl;
    cout << "Time Complexity: " << termcolor::green << fixed 
         << quick_time << setprecision(9) << termcolor::reset << " sec\n" <<  endl;


    radix_time *= 1e-9;
    radixsort(myArray3, n);
    cout << "RadixSort count:  " << RadixCount << endl;
    cout << "Time Complexity: " << termcolor::green << fixed
         << radix_time << setprecision(9) << termcolor::reset << " sec\n" <<  endl;
    
    radix_time++;
    quick_time++;
    bubble_time++;
    
    RadixCount++;
    quickcount++;
    bubblecount++;
    
    number--;

    }
    
    cout << "RadixCount: " << RadixCount << endl;
    cout << "quickcout: " << quickcount << endl;
    cout << "Bubble Count: " << bubblecount << endl;
    cout << endl;

    average_radix_Time = radix_time / 20;
    average_quick_Time = quick_time / 20;
    average_bubble_Time = bubble_time / 20;

    average_radix_Count = RadixCount / 20;
    average_quick_Count = quickcount / 20;
    average_bubble_Count = bubblecount / 20;


    cout << "Average Time Complexity for Bubble Sort: " << termcolor::green << fixed
         << average_bubble_Time << setprecision(9) << termcolor::reset << " sec" <<  endl;
    cout << "Average Bubble Sort Count: " << average_bubble_Count << endl << endl;


    cout << "Average Time Complexity for Quick Sort: " << termcolor::green << fixed
         << average_quick_Time << setprecision(9) << termcolor::reset << " sec" <<  endl;
    cout << "Average Quick Sort Count: " << average_quick_Count << endl << endl;


    cout << "Average Time Complexity for Radix Sort: " << termcolor::green << fixed
         << average_radix_Time << setprecision(9) << termcolor::reset << " sec" <<  endl;
    cout << "Average Radix Sort Count: " << average_radix_Count << endl << endl;


    return 0;
}

// Function to fill the array.
void fillArray(int arr[])
{
  srand(time(NULL));
  for(int i = 0; i < _SIZE; i++)
    arr[i] = rand() % 5000;
}

// Function to copy an array.
void copyArray(int arr1[], int arr2[])
{
  for(int i = 0; i < _SIZE; i++)
    arr2[i] = arr1[i];
}

// Function to print.
void printArray(int arr[])
{
  for(int i = 0; i < _SIZE; i++)
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

// Function to sort the array using bubble sort.
int bubbleSort(int arr[])
{
    auto start = chrono::high_resolution_clock::now();
 
    bool swapped = true;
    int j = 0;
    int bubblecount = 0;

    // Continue to loop until
    // no swaps have occurred. 
    while (swapped)
    {
        // Reset boolean flag
        swapped = false;
        // Because bubbleSort puts the last value in the 
        // correct position eachtime through the loop, the 
        // limit of the inner loop decreases by one each
        // iteration of the outer loop (_SIZE - j)
        for(int i = 1; i < _SIZE - j; i++)
        {
        bubblecount++;
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
    auto end = chrono::high_resolution_clock::now();

    bubble_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return bubblecount;
}

 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and 
                       // indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        quickcount++;
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    auto start = chrono::high_resolution_clock::now();

    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
    auto end = chrono::high_resolution_clock::now();
    quick_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

}


// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function that sorts arr[] of _SIZE n using Radix Sort
void radixsort(int arr[], int n)
{   
    auto start = chrono::high_resolution_clock::now();

    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        {
            countSort(arr, n, exp);
                    RadixCount++;

        }
    
    auto end = chrono::high_resolution_clock::now();

    bubble_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();


}
 

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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