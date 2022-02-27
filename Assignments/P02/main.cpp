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

// Function prototype for bubble sort.
int bubble_Sort(int arr[], int NUMBER);

// Function prototype to quick sort.
int quick_Sort(int arr[], int NUMBER);

// Function prototype to Radix Sort
int radix_Sort(int arr[], int NUMBER);

// Function prototype to print the array.
void printArray(int arr[], int NUMBER);

// Function prototype to print the header.
void header(ofstream &outfile);

// Main function.
int main()
{}


// Function to swap two integers.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function for bubble sort.
int bubble_Sort(int arr[], int NUMBER)
{
    int i, j;
    for (i = 0; i < NUMBER - 1; i++)
    {
        for (j = 0; j < NUMBER - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return 0;
}

// Function to quick sort.
int quick_Sort(int arr[], int NUMBER)

// Function to Radix Sort
int radix_Sort(int arr[], int NUMBER);

// Function to print the array.
void printArray(int arr[], int NUMBER);

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