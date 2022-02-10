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

// Implement 3 different sorting algorithms on arrays of size 10. bubble sort, selection sort, merge sort.
// Implement a separate counter for each sort. Initialize the counter to zero and increment inside loops of the associated sort.
// For example in the bubblesort loop, increment the counter inside the inner loop.
// Use a system clock timer to start the timer immediately before each sort and end immediately after each sort.
// Once you have the code working for 1 run, average the time and counter results over 20 runs, using a different random seed for each run.
// use the loop control variable as the random seed.Make sure that the arrays hold identical values before sorting.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "Timer.hpp"
#include "termcolor.hpp"


using namespace std;

const int SIZE = 10;

// Function prototype to swap two integers.
void swap(int &a, int &b);

// Function prototype to
int bubble_Sort(int arr[], int SIZE);

// Function prototype to
int selection_Sort(int arr[], int SIZE);

// Function prototype to
int quick_Sort(int arr[], int SIZE);

// Function prototype to
void printArray(int arr[], int SIZE);

// Function prototype to
void header(ofstream &outfile);

int main()
{

    ifstream infile;
    ofstream outfile;

    // Initialize the array to random values.
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    // Print the array before sorting.
    header(outfile);

    cout << "Before sorting: \n";
    printArray(arr, SIZE);


    // Call the Bubble sort function.
    int bubble_counter = bubble_Sort(arr, SIZE);
    cout << "\nBubble Sort: " << bubble_counter << endl;
    printArray(arr, SIZE);


    // Call the Merge sort function.
    int quick_sort_counter = quick_Sort(arr, SIZE);
    cout << "\nquick Sort: " << quick_sort_counter << endl;
    printArray(arr, SIZE);


    // Call the selection sort function.
    int selection_counter = selection_Sort(arr, SIZE);
    cout << "\nSelection Sort: " << selection_counter << endl;
    printArray(arr, SIZE);

    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int bubble_Sort(int arr[], int SIZE)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                counter++;
            }
        }
    }
    return counter;
}

int selection_Sort(int arr[], int SIZE)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        counter++;
    }
    return counter;
}

int quick_Sort(int arr[], int SIZE)
{
    int counter = 0;
    int pivot = arr[SIZE - 1];
    int i = 0;
    int j = SIZE - 1;
    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
            counter++;
        }
        while (arr[j] > pivot)
        {
            j--;
            counter++;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            counter++;
        }
    }
    if (i - 1 > 0)
    {
        quick_Sort(arr, i - 1);
    }
    if (j + 1 < SIZE - 1)
    {
        quick_Sort(arr + j + 1, SIZE - j - 2);
    }
    return counter;
}


void printArray(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void header(ofstream &outfile)
{
    outfile << "*****************************************************************************\n";
    outfile << "*";
    outfile << "\n*    Author:           Loic Konan";
    outfile << "\n*    Email:            loickonan.lk@gmail.com";
    outfile << "\n*    Label:            Sorting Algorithms";
    outfile << "\n*    Title:            Program 2";
    outfile << "\n*    Course:           CMPS 5243,  Spring 2022, Dr. Johnson";
    outfile << "\n*    Semester:         Spring 2022";
    outfile << "\n*    Description:";
    outfile << "\n*";
    outfile << "\n*                  This program implements the following sorting algorithms:";
    outfile << "\n*";
    outfile << "\n*                     - Bubble Sort";
    outfile << "\n*                     - Selection Sort";
    outfile << "\n*                     - Merge Sort";
    outfile << "\n*";
    outfile << "\n*";
    outfile << "\n*;";
    outfile << "\n*    Files:";
    outfile << "\n*         main.cpp";
    outfile << "\n*";
    outfile << "\n*    Usage:";
    outfile << "\n*           main.cpp          : driver program";
    outfile << "\n*";
    outfile << "\n*";
    outfile << "\n******************************************************************************\n\n";
}