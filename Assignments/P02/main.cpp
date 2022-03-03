/*****************************************************************************
 *
 *    Author:           Loic Konan
 *    Email:            loickonan.lk@gmail.com
 *    Label:            Sorting Algorithms
 *    Title:            Program 2
 *    Course:           CMPS 6246, Spring 2022, Dr. Johnson
 *    Semester:         Spring 2022
 *    Description:
 *
 *                      This program implements the following sorting algorithms:
 *
 *                           -  RadixSort Sort  O(N)
 *                           -  Bubble Sort     O(N ^ 2)
 *                           -  QuickSort       O(N log N)
 *                           -  Count Sort      O(N)
 *                           -  Merge Sort      O(N log N)
 *                           -  Heap Sort       O(N log N)
 *                           -  Insertion Sort  O(N ^ 2)
 *                           -  Selection Sort  O(N ^ 2)
 * 
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
#include <chrono>


using namespace std;

// The size of the Arrays.
const int _SIZE = 5000;

// To print colors.
#include "termcolor.hpp"

// Different sorting algorithms and Functions
#include "mergeSort.hpp"
#include "heapSort.hpp"
#include "countSort.hpp"
#include "insertionSort.hpp"
#include "selectionSort.hpp"
#include "radixSort.hpp"
#include "bubbleSort.hpp"
#include "quickSort.hpp"
#include "printArray.hpp"
#include "header.hpp"
#include "copyArray.hpp"
#include "fillArray.hpp"


// Main function.
int main()
{
    // Initialize the arrays.
    int myArray1[_SIZE];
    int myArray2[_SIZE];
    int myArray3[_SIZE];
    int myArray4[_SIZE];
    int myArray5[_SIZE];
    int myArray6[_SIZE];
    int myArray7[_SIZE];
    int myArray8[_SIZE];

    // Initialize the counter for bubble sort.
    int bubblecount,
    selectioncount,    
    insertioncount,
    count_count;
    

    // Initialize the Timer.
    double count_time,
    radix_time,
    selection_time,
    insertion_time,
    quick_time,
    merge_time,
    heap_time,
    bubble_time;


    // n is the size of the array.
    int n = sizeof(myArray1) / sizeof(myArray1[0]);

    // Print the header.
    Header::header();

    int number = 20;
    int seed   = 0;

    // Variable to show the column width.
    int colWidth = 15;

    
    // table header
    cout << termcolor::green << ("\n\n***********************************************************************") 
         << ("*******************************************************************") << "\n\n";
    cout << setw(5*colWidth) << "Time Complexity & Number of Comparisons per Iteration\n\n";

    cout << setw(colWidth) << "Iteration" << setw(colWidth) << "RadixSort" << setw(colWidth) 
         << "CountingSort" << setw(colWidth)<< "InsertionSort" << setw(colWidth) << "MergeSort" << setw(colWidth) 
         << "QuickSort" << setw(colWidth) << "HeapSort" << setw(colWidth)<< "BubbleSort" << setw(colWidth) 
         << "SelectionSort" << setw(colWidth) << "\n\n";
    
    cout << ("***********************************************************************")
         << ("*******************************************************************") << termcolor::reset<< "\n\n";


    // Run the each algorithm 20 times.
    for (int i = 1; i <= number; i++)
    {
        // Call the fillArrays function.
        FillArray::fillArray(myArray1, seed);

        // Call the copyArrays function, and pass the arrays.
        CopyArray::copyArray(myArray1, myArray2);
        CopyArray::copyArray(myArray1, myArray3);


    
        /****************************************************************
         * 
         *                     Radix Sort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Radix sort.
        auto startRadix = chrono::high_resolution_clock::now();
        // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the radixsort function, and pass the arrays.
        RadixSort::radixsort(myArray1, n, radixcount);
        // End the clock for the Radix sort.
        auto endRadix = chrono::high_resolution_clock::now();
        // Calculate the time for the Radix sort.
        radix_time = chrono::duration_cast<chrono::nanoseconds>(endRadix - startRadix).count();
        // Converting the time to seconds
        radix_time *= 1e-9;


    
        /****************************************************************
         * 
         *                     CountSort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Countsort.
        auto startCount = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the Count Sort function, and pass the arrays.
        count_count = CountSort::countSort(myArray2, n);
        // End the clock for the Count sort.
        auto endCount = chrono::high_resolution_clock::now();
        // Calculate the time for the Count sort.
        count_time = chrono::duration_cast<chrono::nanoseconds>(endCount - startCount).count();
        // Converting the time to seconds
        count_time *= 1e-9;


        /****************************************************************
         * 
         *                     Bubble Sort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Bubble sort.
        auto startBubble = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the bubble Sort function, and pass the arrays.
        bubblecount = BubbleSort::bubbleSort(myArray3);
        // End the clock for the Bubble sort.
        auto endBubble = chrono::high_resolution_clock::now();
        // Calculate the time for the Bubble sort.
        bubble_time = chrono::duration_cast<chrono::nanoseconds>(endBubble - startBubble).count();
        // Converting the time to seconds
        bubble_time *= 1e-9;
       

        /****************************************************************
         * 
         *                     SeclectionSort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Selection sort.
        auto startSelection = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the Selection sort function, and pass the arrays.
        selectioncount = SelectionSort::selectionSort(myArray4);
        // End the clock for the Selection sort.
        auto endSelection = chrono::high_resolution_clock::now();
        // Calculate the time for the Selection sort.
        selection_time = chrono::duration_cast<chrono::nanoseconds>(endSelection - startSelection).count();
        // Converting the time to seconds
        selection_time *= 1e-9;
       

         /****************************************************************
         * 
         *                     InsertionSort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Insertion sort.
        auto startInsertion = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the Insertion sort function, and pass the arrays.
        insertioncount = InsertionSort::insertionSort(myArray5);
        // End the clock for the Insertion sort.
        auto endInsertion = chrono::high_resolution_clock::now();
        // Calculate the time for the Insertion sort.
        insertion_time = chrono::duration_cast<chrono::nanoseconds>(endInsertion - startInsertion).count();
        // Converting the time to seconds
        insertion_time *= 1e-9;


        /****************************************************************
         * 
         *                     MergeSort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Merge sort.
        auto startMerge = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the Merge sort function, and pass the arrays.
        MergeSort::mergeSort(myArray6, n, MergeCount);
        // End the clock for the Merge sort.
        auto endMerge = chrono::high_resolution_clock::now();
        // Calculate the time for the Merge sort.
        merge_time = chrono::duration_cast<chrono::nanoseconds>(endMerge - startMerge).count();
        // Converting the time to seconds
        merge_time *= 1e-9;
        

        /****************************************************************
         * 
         *                     HeapSort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Heap sort.
        auto startHeap = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the Heap sort function, and pass the arrays.
        HeapSort::heapSort(myArray7, n, HeapCount);
        // End the clock for the Heap sort.
        auto endHeap = chrono::high_resolution_clock::now();
        // Calculate the time for the Heap sort.
        heap_time = chrono::duration_cast<chrono::nanoseconds>(endHeap - startHeap).count();
        // Converting the time to seconds
        heap_time *= 1e-9;
        

        /****************************************************************
         * 
         *                     QuickSort Below
         * 
         *
         ****************************************************************/ 
        // Start the clock for the Quick sort.
        auto startQuick = chrono::high_resolution_clock::now();
         // unsync the I/O of  C++.
        ios_base::sync_with_stdio(false);
        // Call the quickSort function, and pass the arrays.
        QuickSort::quickSort(myArray8, 0, _SIZE - 1, quickcount);
        // End the clock for the Quick sort.
        auto endQuick = chrono::high_resolution_clock::now();
        // Calculate the time for the Quick sort.
        quick_time = chrono::duration_cast<chrono::nanoseconds>(endQuick - startQuick).count();
        // Converting the time to seconds
        quick_time *= 1e-9;


        // The Time for the O(n^2) algorithms.
        bubble_time++;
        insertion_time++;
        selection_time++;

        // The Number of comparisons for the O(n log n) algorithms.
        bubblecount++;
        insertioncount++;
        selectioncount++;
        
        // The Time for the O(n) algorithms.
        count_time++;
        radix_time++;

        // The Number of comparisons for the O(n) algorithms.
        count_count++;
        radixcount++;
        
        // The Time for the O(nlogn) algorithms.
        quick_time++;
        heap_time++;
        merge_time++;

        // The number of comparisons for  the O(nlogn) algorithms
        quickcount++;
        HeapCount++;
        MergeCount++;


        // Incrementing the seed for our random number generator.
        seed++;
    }

    // Calculate the average time complexity for all the algorithms.
    bubble_time    /= number;
    insertion_time /= number;
    selection_time /= number;

    count_time     /= number;
    radix_time     /= number;
    
    quick_time     /= number;
    heap_time      /= number;
    merge_time     /= number;


    // Calculate the average number of comparisons for all the algorithms.
    double Average_bubblecount    = bubblecount    / double(number);
    double Average_insertioncount = insertioncount / double(number);
    double Average_selectioncount = selectioncount / double(number);

    double Average_countcount     = count_count    / double(number);
    double Average_radixcount     = radixcount     / double(number);

    double Average_quickcount     = quickcount     / double(number);
    double Average_HeapCount      = HeapCount      / double(number);
    double Average_MergeCount     = MergeCount     / double(number);




    cout << "\n\n\t\t\t****************************************************************\n"
         << "\t\t\t*                                                              *\n"
         << "\t\t\t*                      Final Results Below                     *\n"
         << "\t\t\t*                                                              *\n"
         << "\t\t\t*                                                              *\n"
         << "\t\t\t****************************************************************\n";
    cout << ("***********************************************************************") 
         << ("********************************") << "\n\n"; 

    cout << setw(colWidth) << "Algorithms" << "\t\t\t\t" << "Average Time Complexity" 
         << "\t\t\t" << "Average Comparisons\n\n";
    cout << setw(4*colWidth) << "(Milliseconds)\n";

    cout << ("***********************************************************************") 
         << ("********************************") << "\n\n"; 
    
    cout << fixed << setprecision(6)
         << setw(colWidth)  << "BubbleSort"    << setw(2.8*colWidth) << bubble_time    << setw(2.8*colWidth) <<  Average_bubblecount    << "\n\n"
         << setw(colWidth)  << "SelectionSort" << setw(2.8*colWidth) << selection_time << setw(2.8*colWidth) <<  Average_selectioncount << "\n\n"
         << setw(colWidth)  << "InsertionSort" << setw(2.8*colWidth) << insertion_time << setw(2.8*colWidth) <<  Average_insertioncount << "\n\n"
         
         << setw(colWidth)  << "QuickSort"     << setw(2.8*colWidth) << quick_time     << setw(2.8*colWidth) <<  Average_quickcount     << "\n\n"
         << setw(colWidth)  << "MergeSort"     << setw(2.8*colWidth) << merge_time     << setw(2.8*colWidth) <<  Average_MergeCount     << "\n\n"
         << setw(colWidth)  << "HeapSort"      << setw(2.8*colWidth) << heap_time      << setw(2.8*colWidth) << Average_HeapCount       << "\n\n"


         << setw(colWidth)  << "RadixSort"     << setw(2.8*colWidth) << radix_time    << setw(2.8*colWidth)  <<  Average_radixcount     << "\n\n"
         << setw(colWidth)  << "CountingSort"  << setw(2.8*colWidth) << count_time    << setw(2.8*colWidth)  << Average_countcount      << "\n\n";
    
    cout << ("***********************************************************************")
         << ("********************************") << "\n\n"; 

    return 0;
}

