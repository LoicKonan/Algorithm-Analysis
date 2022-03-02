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


#include "termcolor.hpp"
#include "mergeSort.hpp"
#include "heapSort.hpp"
#include "countSort.hpp"
#include "insertionSort.hpp"
#include "selectionSort.hpp"
#include "radixSort.hpp"
#include "bubbleSort.hpp"
#include "quickSort.hpp"



// Function prototype to fill the Arrays.
void fillArray(int arr[], int seed);

// Function prototype to copy the Arrays.
void copyArray(int arr1[], int arr2[]);

// Function prototype to print the Arrays.
void printArray(int arr[]);


// Function prototype to print the header.
void header();


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
    int n = sizeof(myArray3) / sizeof(myArray3[0]);

    // Print the header.
    header();

    int number = 20;
    int seed = 0;

    // Run the each algorithm 20 times.
    for (int i = 0; i < number; i++)
    {
        // Call the fillArrays function.
        fillArray(myArray1, seed);

        // Call the copyArrays function, and pass the arrays.
        copyArray(myArray1, myArray2);
        copyArray(myArray1, myArray3);


    
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
        // Display the time for the Radix sort.
        cout << "RadixSort count:  " << radixcount << endl;
        cout << "Radix Time Complexity: " << termcolor::green << fixed
             << radix_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;


    
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
        // Display the time for the Count sort.
        cout << "QuickSort count:  " << count_count << endl;
        cout << "Quick Time Complexity: " << termcolor::green << fixed
             << quick_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;



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
        // Display the time for the Bubble sort.
        cout << "Bubble count:  " << bubblecount << endl;
        cout << " Bubble Time Complexity: " << termcolor::green << fixed
             << bubble_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;



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
        // Display the time for the Selection sort.
        cout << "Selection count:  " << selectioncount << endl;
        cout << "Selection Time Complexity: " << termcolor::green << fixed
             << selection_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;



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
        // Display the time for the Insertion sort.
        cout << "Insertion count:  " << insertioncount << endl;
        cout << "Insertion Time Complexity: " << termcolor::green << fixed
             << insertion_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;



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
        // Display the time for the Merge sort.
        cout << "Merge count:  " << MergeCount << endl;
        cout << "Merge Time Complexity: " << termcolor::green << fixed
             << merge_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;



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
        // Display the time for the Heap sort.
        cout << "Heap count:  " << HeapCount << endl;
        cout << "Heap Time Complexity: " << termcolor::green << fixed
             << heap_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;
  

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
        // Display the time for the Quick sort.
        cout << "QuickSort count:  " << quickcount << endl;
        cout << "Time Complexity: " << termcolor::green << fixed
             << quick_time << setprecision(6) << termcolor::reset << " sec\n"
             << endl;

        


        // Getting the total time and total count of comparisons.
        bubble_time++;
        insertion_time++;
        selection_time++;
        
        count_time++;
        radix_time++;
        
        quick_time++;
        heap_time++;
        merge_time++;


        bubblecount++;
        insertioncount++;
        selectioncount++;

        quickcount++;
        HeapCount++;
        MergeCount++;

        count_count++;
        radixcount++;

        seed++;
    }

    // The average time complexity of the three algorithms.
    
    bubble_time /= double(number);
    insertion_time /= double(number);
    selection_time /= number;

    count_time /= double(number);
    radix_time /= double(number);
    
    quick_time /= double(number);
    heap_time /= double(number);
    merge_time /= double(number);

    // The average number of comparisons for the three algorithms.
    
    bubblecount /= double(number);
    insertioncount /= double(number);
    selectioncount /= double(number);

    count_count /= double(number);
    radixcount /= double(number);

    quickcount /= double(number);
    HeapCount /= double(number);
    MergeCount /= double(number);



    cout << "\n\n****************************************************************\n"
         << "* \n"
         << "*                      Final Results Below\n"
         << "* \n"
         << "*\n"
         << "****************************************************************\n"<< endl;

    cout << "Average Time Complexity for Bubble Sort: " << termcolor::green << fixed
         << bubble_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Bubble Sort Count: " << bubblecount << endl
         << endl;


    cout << "Average Time Complexity for Insertion Sort: " << termcolor::green << fixed
            << insertion_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Insertion Sort Count: " << insertioncount << endl
            << endl;

    cout << "Average Time Complexity for Selection Sort: " << termcolor::green << fixed
            << selection_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Selection Sort Count: " << selectioncount << endl
            << endl;

        
    cout << "Average Time Complexity for Quick Sort: " << termcolor::green << fixed
         << quick_time << " sec" << setprecision(6) << termcolor::reset << endl;
    cout << "Average Quick Sort Count: " << quickcount << endl
         << endl;

    cout << "Average Time Complexity for Heap Sort: " << termcolor::green << fixed  
            << heap_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Heap Sort Count: " << HeapCount << endl
            << endl;

    cout << "Average Time Complexity for Merge Sort: " << termcolor::green << fixed
            << merge_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Merge Sort Count: " << MergeCount << endl
            << endl;


    cout << "Average Time Complexity for Radix Sort: " << termcolor::green << fixed
         << radix_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Radix Sort Count: " << radixcount << endl
         << endl;

    cout << "Average Time Complexity for Counting Sort: " << termcolor::green << fixed
            << count_time << setprecision(6) << termcolor::reset << " sec" << endl;
    cout << "Average Counting Sort Count: " << count_count << endl
            << endl;

    return 0;
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
    cout << "\n*    Course:           CMPS 6246,  Spring number22, Dr. Johnson";
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