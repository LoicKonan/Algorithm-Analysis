/****************************************************************************************************
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
 *                           -  RadixSort Sort  O(N)
 *                           -  Bubble Sort     O(N ^ 2)
 *                           -  QuickSort       O(N log N)
 *                           -  Count Sort      O(N)
 *                           -  Merge Sort      O(N log N)
 *                           -  Heap Sort       O(N log N)
 *                           -  Insertion Sort  O(N ^ 2)
 *                           -  Selection Sort  O(N ^ 2)
 *
 *                      Each algorithm is implemented in a separate .hpp file.
 *                      The goal of this program is to compare the performance
 *                      of each algorithm.
 *                      After 20 Iterations, I calculate the average time
 *                      and counter it takes to sort the data of our Arrays of
 *                      size 5000 (random numbers). The counter for each sort
 *                      is first Initialize to zero and incremented inside the loops
 *                      of the associated sort, or I pass back the count using a
 *                      return statement or reference variable. I Use a system
 *                      clock timer to start the time immediately  before each
 *                      sort and end immediately after each sort.
 *                      Finally The average time is then calculated by
 *                      dividing the total time by 20
 *
 *
 *    Files:
 *         main.cpp
 *         radixSort.hpp
 *         bubbleSort.hpp
 *         quickSort.hpp
 *         countSort.hpp
 *         mergeSort.hpp
 *         heapSort.hpp
 *         insertionSort.hpp
 *         selectionSort.hpp
 *         printArray.hpp
 *         header.hpp
 *         copyArray.hpp
 *         fillArray.hpp
 *         termcolor.hpp
 *
 *
 *    Usage:
 *           main.cpp          : driver program
 *
 *
 ****************************************************************************************************/
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
using namespace std::chrono;

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
     int width  = 15;

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
          radix_time = chrono::duration_cast<chrono::milliseconds>(endRadix - startRadix).count();

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
          count_time = chrono::duration_cast<chrono::milliseconds>(endCount - startCount).count();

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
          bubble_time = chrono::duration_cast<chrono::milliseconds>(endBubble - startBubble).count();

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
          selection_time = chrono::duration_cast<chrono::milliseconds>(endSelection - startSelection).count();

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
          insertion_time = chrono::duration_cast<chrono::milliseconds>(endInsertion - startInsertion).count();

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
          merge_time = chrono::duration_cast<chrono::milliseconds>(endMerge - startMerge).count();

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
          heap_time = chrono::duration_cast<chrono::milliseconds>(endHeap - startHeap).count();

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
          quick_time = chrono::duration_cast<chrono::milliseconds>(endQuick - startQuick).count();

          // The Time and counter for the O(n^2) algorithms.
          bubble_time++;
          insertion_time++;
          selection_time++;

          bubblecount++;
          insertioncount++;
          selectioncount++;

          // The Time and counter for the O(n) algorithms.
          count_time++;
          radix_time++;

          count_count++;
          radixcount++;

          // The Time and counter for the O(n log n) algorithms.
          quick_time++;
          heap_time++;
          merge_time++;

          quickcount++;
          HeapCount++;
          MergeCount++;

          // Incrementing the seed for our random number generator.
          seed++;
     }

     // Print the Total TIME of each algorithm to the console.

     cout << "\n\n\t\t\t****************************************************************\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t*         Total time complexity for each algorithms            *\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t****************************************************************\n\n";

     cout << setw(3.5 * width) << "Bubble Sort:"    << setw(width)       
          << bubble_time       << " milliseconds"   << "\n\n";

     cout << setw(3.5 * width) << "Insertion Sort:" << setw(width) 
          << insertion_time    << " milliseconds"   << "\n\n";

     cout << setw(3.5 * width) << "Selection Sort:" << setw(width) 
          << selection_time    << " milliseconds"   << "\n\n";

      cout << setw(3.5 * width)<< "Quick Sort:"     << setw(width) 
          << quick_time        << " milliseconds"   << "\n\n";

     cout << setw(3.5 * width) << "Merge Sort:"     << setw(width) 
          << merge_time        << " milliseconds"   << "\n\n";

     cout << setw(3.5 * width) << "Heap Sort:"      << setw(width) 
          << heap_time         << " milliseconds"   << "\n\n";

     cout << setw(3.5 * width) << "Radix Sort:"     << setw(width) 
          << radix_time        << " milliseconds"   << "\n\n";

     cout << setw(3.5 * width) << "Count Sort:"     << setw(width) 
          << count_time        << " milliseconds"   << "\n\n";
   

     // Print the Total COUNTER of each algorithm to the console.
     cout << "\n\n\t\t\t****************************************************************\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t*               Total Counter for each algorithms              *\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t****************************************************************\n\n";

     cout << setw(3.5 * width) << "Bubble Sort:"
          << setw(width)       << bubblecount    << " times\n\n";

     cout << setw(3.5 * width) << "Insertion Sort:"
          << setw(width)       << insertioncount << " times\n\n";

     cout << setw(3.5 * width) << "Selection Sort:"
          << setw(width)       << selectioncount << " times\n\n";

     cout << setw(3.5 * width) << "Quick Sort:"
          << setw(width)       << quickcount     << " times\n\n";

     cout << setw(3.5 * width) << "Merge Sort:"
          << setw(width)       << MergeCount     << " times\n\n";

     cout << setw(3.5 * width) << "Heap Sort:"
          << setw(width)       << HeapCount      << " times\n\n";

     cout << setw(3.5 * width) << "Radix Sort:"
          << setw(width)       << radixcount     << " times\n\n";

     cout << setw(3.5 * width) << "Count Sort:"
          << setw(width)       << count_count    << " times\n\n";
     

     // Calculate the average time complexity for all the algorithms.
     double Avg_bubble_time    = bubble_time    / number;
     double Avg_selectiontime  = selection_time / number;
     double Avg_insertiontime  = insertion_time / number;

     double Avg_count_time     = count_time     / number;
     double Avg_radix_time     = radix_time     / number;

     double Avg_merge_time     = merge_time     / number;
     double Avg_heap_time      = heap_time      / number;
     double Avg_quick_time     = quick_time     / number;

     // Calculate the average number of comparisons for all the algorithms.
     double Avg_bubblecount    = bubblecount    / double(number);
     double Avg_insertioncount = insertioncount / double(number);
     double Avg_selectioncount = selectioncount / double(number);

     double Avg_countcount     = count_count    / double(number);
     double Avg_radixcount     = radixcount     / double(number);

     double Avg_quickcount     = quickcount     / double(number);
     double Avg_HeapCount      = HeapCount      / double(number);
     double Avg_MergeCount     = MergeCount     / double(number);


     // Print the results to the screen.
     cout << "\n\n\t\t\t****************************************************************\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t*                      Final Results Below                     *\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t*                                                              *\n"
          << "\t\t\t****************************************************************\n";
     cout << ("***********************************************************************")
          << ("********************************")    << "\n\n";

     cout << setw(width) << "Algorithms"
          << "\t\t\t\t"
          << "Average Time Complexity"
          << "\t\t\t"
          << "Average Comparisons\n\n";
     cout << setw(4 * width)   << "(milliseconds)\n";

     cout << ("***********************************************************************")
          << ("********************************")    << "\n\n";

     cout << fixed << setprecision(6)
          << setw(width)       << "BubbleSort"       << setw(2.8 * width) 
          << Avg_bubble_time   << setw(2.8 * width)  << Avg_bubblecount    << "\n\n"

          << setw(width)       << "InsertionSort"    << setw(2.8 * width) 
          << Avg_insertiontime << setw(2.8 * width)  << Avg_insertioncount << "\n\n"

          << setw(width)       << "SelectionSort"    << setw(2.8 * width) 
          << Avg_selectiontime << setw(2.8 * width)  << Avg_selectioncount << "\n\n"

          << setw(width)       << "QuickSort"        << setw(2.8 * width) 
          << Avg_quick_time    << setw(2.8 * width)  << Avg_quickcount     << "\n\n"

          << setw(width)       << "MergeSort"        << setw(2.8 * width) 
          << Avg_merge_time    << setw(2.8 * width)  << Avg_MergeCount     << "\n\n"

          << setw(width)       << "HeapSort"         << setw(2.8 * width)  
          << Avg_heap_time     << setw(2.8 * width)  << Avg_HeapCount      << "\n\n"

          << setw(width)       << "RadixSort"        << setw(2.8 * width)  
          << Avg_radix_time    << setw(2.8 * width)  << Avg_radixcount     << "\n\n"

          << setw(width)       << "CountingSort"     << setw(2.8 * width)  
          << Avg_count_time    << setw(2.8 * width)  << Avg_countcount     << "\n\n";

     cout << ("***********************************************************************")
          << ("********************************") << "\n\n";

     return 0;
}
