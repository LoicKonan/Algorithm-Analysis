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
#include <chrono>
#include <vector>
#include <ctime>
#include <cmath>
#include <random>
#include <iomanip>
#include <time.h>

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
const int SIZE = 5000;

// Driver code
int main()
{
    // Display the header and Description of the program.
    header();

    // Initialize the size(5000) of the arrays.
    int myArray1[SIZE];
    int myArray2[SIZE];
    int myArray3[SIZE];
    int myArray4[SIZE];
    int myArray5[SIZE];
    int myArray6[SIZE];
    int myArray7[SIZE];

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average Time for bubble sort.
    int bubble_count = 0;
    int bubble_sum = 0;
    double bubble_average = 0;
    double Avg_bubble_time = 0;

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average for selection sort.
    int selection_count = 0;
    int selection_sum = 0;
    double selection_average = 0;
    double Avg_selection_time = 0;

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average for insertion sort.
    int insertion_count = 0;
    int insertion_sum = 0;
    double insertion_average = 0;
    double Avg_insertion_time = 0;

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average for count sort.
    int count_count = 0;
    int count_sum = 0;
    double count_average = 0;
    double Avg_count_time = 0;

    // Initialize the sum of the comparison, the average comparison
    // and the average for Heap sort.
    int heap_sum = 0;
    double heap_average = 0;
    double Avg_heap_time = 0;

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average for Quick sort.
    int quick_sum = 0;
    double quick_average = 0;
    double Avg_quick_time = 0;

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average for Radix sort.
    int radix_sum = 0;
    double radix_average = 0;
    double Avg_radix_time = 0;

    // Initialize the comparison counter, the sum of the comparison, the average comparison
    // and the average for Merge sort.
    int merge_sum = 0;
    double merge_average = 0;
    double Avg_merge_time = 0;

    // run the loop 20 times.
    int number = 20;

    // Initialize the seed for the random number generator.
    int seed = 0;

    // n is the size of the array.
    int n = sizeof(myArray3) / sizeof(myArray3[0]);

    // Run the each algorithm 20 times.
    for (int i = 0; i < number; i++)
    {
        // Call the fillArrays function.
        fillArray(myArray1, seed);

        // Call the copyArrays function, and pass the arrays.
        copyArray(myArray1, myArray2);
        copyArray(myArray1, myArray3);
        copyArray(myArray1, myArray4);
        copyArray(myArray1, myArray5);
        copyArray(myArray1, myArray6);
        copyArray(myArray1, myArray7);

        // CountSort::countSort(copy, n, m);
        // HeapSort::heapSort(copy, n);
        // QuickSort::quickSort(copy, 0, n - 1);
        // RadixSort::radixsort(copy, n);

        auto RadixStart = chrono::high_resolution_clock::now();
        // unsync the I/O of C and C++.
        ios_base::sync_with_stdio(false);
        RadixSort::radixsort(myArray3, SIZE, radixcount);
        auto RadixEnd = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double RadixTime_taken = chrono::duration_cast<chrono::nanoseconds>(RadixEnd - RadixStart).count();
        // convert time taken to sort the array from nanoseconds to seconds.
        RadixTime_taken *= 1e-9;
        cout << "RadixSort count:  " << radixcount << endl;
        cout << "Time Complexity: " << termcolor::green << fixed
             << RadixTime_taken << setprecision(3) << termcolor::reset<< endl;



        // Bubble sort using myArray1
        auto BubbleStart = chrono::high_resolution_clock::now();
        // unsync the I/O of C ++.
        ios_base::sync_with_stdio(false);
        bubble_count = BubbleSort::bubbleSort(myArray1);
        auto BubbleEnd = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double BubbleTime_taken = chrono::duration_cast<chrono::nanoseconds>(BubbleEnd - BubbleStart).count();
        // convert time taken to sort the array from nanoseconds to seconds.
        BubbleTime_taken *= 1e-9;
        cout << "Bubble count:  " << bubble_count << endl;
        cout << "Time Complexity: " << termcolor::green << fixed
             << BubbleTime_taken << setprecision(3) << termcolor::reset << endl;




        auto QuickStart = chrono::high_resolution_clock::now();
        // unsync the I/O of C ++.
        ios_base::sync_with_stdio(false);
        QuickSort::quickSort(myArray2, 0, SIZE - 1, quickcount);
        auto QuickEnd = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double QuickTime_taken = chrono::duration_cast<chrono::nanoseconds>(QuickEnd - QuickStart).count();
        // convert time taken to sort the array from nanoseconds to seconds.
        QuickTime_taken *= 1e-9;
        cout << "QuickSort count:  " << quickcount << endl;
        cout << "Time Complexity: " << termcolor::green << fixed
             << QuickTime_taken << setprecision(3) << termcolor::reset << " sec\n"
             << endl;


        // Total number of iterations taken for each algorithim to sort 20 arrays.
        bubble_sum += bubble_count;
        merge_sum += MergeCount;
        count_sum += count_count;
        
        
        // Total time taken for each algorithim to sort 20 arrays.
        Avg_bubble_time += BubbleTime_taken;
        Avg_quick_time += QuickTime_taken;
        Avg_radix_time += RadixTime_taken;

        seed++;
    }

    // The average time complexity of the three algorithms.
    Avg_radix_time /= number;
    Avg_quick_time /= number;
    Avg_bubble_time /= number;

    // The average number of comparisons for the three algorithms.
    radixcount /= number;
    quickcount /= number;
    bubble_count /= number;

    cout << "Average Time Complexity for Bubble Sort: " << termcolor::green << fixed
         << Avg_bubble_time << setprecision(3) << termcolor::reset << endl;
    cout << "Average Bubble Sort Count: " << bubble_count << endl
         << endl;

    cout << "Average Time Complexity for Quick Sort: " << termcolor::green << fixed
         << Avg_quick_time << setprecision(3) << termcolor::reset << endl;
    cout << "Average Quick Sort Count: " << quickcount << endl
         << endl;

    cout << "Average Time Complexity for Radix Sort: " << termcolor::green << fixed
         << Avg_radix_time << setprecision(3) << termcolor::reset << endl;
    cout << "Average Radix Sort Count: " << radixcount << endl
         << endl;

    return 0;
}

// Function prototype to fill the Array.
void fillArray(int Array[], int seed)
{
    // Seed the random number generator.
    srand(seed);

    // Fill the array with random numbers.
    for (int i = 0; i < SIZE; i++)
        Array[i] = rand() % 100;
}

// Function prototype to copy the Array.
void copyArray(int Array1[], int Array2[])
{
    // Copy the array.
    for (int i = 0; i < SIZE; i++)
        Array1[i] = Array2[i];
}

// Function prototype to print the Array.
void printArray(int Array[])
{
    // Print the array.
    for (int i = 0; i < SIZE; i++)
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