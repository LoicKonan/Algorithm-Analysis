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

const int NUMBER = 50;

// Function prototype to swap two integers.
void swap(int &a, int &b);

// Function prototype to
int bubble_Sort(int arr[], int NUMBER);

// Function prototype to
int selection_Sort(int arr[], int NUMBER);

// Function prototype to
int quick_Sort(int arr[], int NUMBER);

// Function prototype to
int merge_sort(int arr[], int NUMBER);

// Function prototype to
void printArray(int arr[], int NUMBER);

// Function prototype to print the time.
void printTime(int);

// Function prototype to
void header(ofstream &outfile);

int main()
{

    ifstream infile;
    ofstream outfile;

    // Initialize the array to random values.
    int arr[NUMBER];
    
    // set seed to time(0)
    srand(time(0));

    for (int i = 0; i < NUMBER; i++)
    {
        arr[i] = rand() % 5000;
    }

    // Print the array before sorting.
    header(outfile);

    cout  << termcolor::magenta << "Before sorting: \n";
    printArray(arr, NUMBER);
    cout  << termcolor::reset << endl;


    // Call the Bubble sort function.
    int bubble_counter = bubble_Sort(arr, NUMBER);
    cout << termcolor::red << "\nBubble Sort: " 
         << bubble_counter << endl;
    printTime(bubble_counter);
    printArray(arr, NUMBER);
    cout << termcolor::reset << endl;


    // Call the selection sort function.
    int selection_counter = selection_Sort(arr, NUMBER);
    cout << termcolor::yellow << "\nSelection Sort: " 
         << selection_counter << endl;
    printTime(selection_counter);
    printArray(arr, NUMBER);
    cout << termcolor::reset << endl;


    // Call the Quick sort function.
    int quick_sort_counter = quick_Sort(arr, NUMBER);
    cout << termcolor::blue << "\nQuick Sort: " 
         << quick_sort_counter << endl;
    printTime(quick_sort_counter);
    printArray(arr, NUMBER);
    cout << termcolor::reset << endl;


    // Call the Merge sort function.
    int merge_counter = merge_sort(arr, NUMBER);
    cout << termcolor::green << "\nMerge Sort: " 
         << merge_counter << endl;
    printTime(merge_counter);
    printArray(arr, NUMBER);
    cout << termcolor::reset << endl;

    return 0;
}

void printTime(int counter)
{
    cout << termcolor::cyan << "Time: " << counter << " ms" << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int bubble_Sort(int arr[], int NUMBER)
{   
    Timer time;                             // Create a timer.
    time.Start();                           // Start the timer.

    int counter = 0;                        // Initialize the counter.
    for (int i = 0; i < NUMBER; i++)
    {
        for (int j = 0; j < NUMBER - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                counter++;
            }
        }
    }
    return counter;

     time.End();

    cout << termcolor::green << time.Seconds() 
         << termcolor::reset
         << " seconds to sort the Arrays." << endl;
}


int selection_Sort(int arr[], int NUMBER)
{
    Timer time;                             // Create a timer.
    time.Start();                           // Start the timer.

    int counter = 0;
    for (int i = 0; i < NUMBER; i++)
    {
        int min = i;
        for (int j = i + 1; j < NUMBER; j++)
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

    time.End();
    cout << termcolor::green << time.Seconds() 
         << termcolor::reset
         << " seconds to sort the Arrays." << endl;
}


int merge_sort(int arr[], int NUMBER)
{
    Timer time;                             // Create a timer.
    time.Start();                           // Start the timer.

    int counter = 0;
    int mid = NUMBER / 2;
    int left[mid];
    int right[NUMBER - mid];

    for (int i = 0; i < NUMBER; i++)
    {
        if (i < mid)
        {
            left[i] = arr[i];
        }
        else
        {
            right[i - mid] = arr[i];
        }
    }

    if (NUMBER > 1)
    {
        counter += merge_sort(left, mid);
        counter += merge_sort(right, NUMBER - mid);
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < mid && j < NUMBER - mid)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
        counter++;
    }

    while (i < mid)
    {
        arr[k] = left[i];
        i++;
        k++;
        counter++;
    }

    while (j < NUMBER - mid)
    {
        arr[k] = right[j];
        j++;
        k++;
        counter++;
    }

    return counter;

    time.End();
    cout << termcolor::green << time.Seconds() 
         << termcolor::reset
         << " seconds to sort the Arrays." << endl;
}


int quick_Sort(int arr[], int NUMBER)
{
    Timer time;                             // Create a timer.
    time.Start();                           // Start the timer.


    int counter = 0;
    int pivot = arr[NUMBER - 1];
    int i = 0;
    int j = NUMBER - 1;
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
    if (j + 1 < NUMBER - 1)
    {
        quick_Sort(arr + j + 1, NUMBER - j - 2);
    }
    return counter;

    time.End();
    cout << termcolor::green << time.Seconds() 
         << termcolor::reset
         << " seconds to sort the Arrays." << endl;
}


void printArray(int arr[], int NUMBER)
{
    for (int i = 0; i < NUMBER; i++)
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