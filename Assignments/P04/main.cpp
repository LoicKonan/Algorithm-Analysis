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

using namespace std;
using namespace std::chrono;

// Function prototype to print the header.
void header();

// Function prototype to swap the values of two integers.
void swap(int &x, int &y);

// Function to get the largest element from an array
int getMax(int array[], int n);

// Function prototype for the Bubble Sort.
int bubbleSort(int Array[]);

// Function prototype to the partition function
int Partition(int a[], int b, int e, int &quickcount);

// Function prototype for quickSort.
void quickSort(int a[], int p, int r, int &quickcount);

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place, int &radixcount);

// Function prototype to fill the Array.
void fillArray(int Array[], int seed);

// Function prototype to copy the Array.
void copyArray(int Array1[], int Array2[]);

// Function prototype to print the Array.
void printArray(int Array[]);

// The Size of our Arrays.
const int SIZE = 5000;

// Initialize the count for quickSort
int quickcount = 0;

// Initialize the count for Radix
int radixcount = 0;

// Driver code
int main()
{
     // Display the header and Description of the program.
     header();

     // Initialize the size(5000) of the arrays.
     int myArray1[SIZE];
     int myArray2[SIZE];
     int myArray3[SIZE];
     // int myArray4[SIZE];
     // int myArray5[SIZE];
     // int myArray6[SIZE];
     // int myArray7[SIZE];

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
;

     // Run the each algorithm 20 times.
     for (int i = 0; i < number; i++)
     {
          // Call the fillArrays function.
          fillArray(myArray1, seed);

          // Call the copyArrays function, and pass the arrays.
          copyArray(myArray1, myArray2);
          copyArray(myArray1, myArray3);
         

          auto RadixStart = chrono::high_resolution_clock::now();
          // unsync the I/O of C and C++.
          ios_base::sync_with_stdio(false);
          radixsort(myArray3, SIZE, radixcount);
          auto RadixEnd = chrono::high_resolution_clock::now();
          // Calculating total time taken by the program.
          double RadixTime_taken = chrono::duration_cast<chrono::nanoseconds>(RadixEnd - RadixStart).count();
          // convert time taken to sort the array from nanoseconds to seconds.
          RadixTime_taken *= 1e-9;
          cout << "RadixSort count:  " << radixcount << endl;
          cout << "Time Complexity: " << termcolor::green << fixed
               << RadixTime_taken << setprecision(3) << termcolor::reset << endl;

          // Bubble sort using myArray1
          auto BubbleStart = chrono::high_resolution_clock::now();
          // unsync the I/O of C ++.
          ios_base::sync_with_stdio(false);
          bubble_count = bubbleSort(myArray1);
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
          quickSort(myArray2, 0, SIZE - 1, quickcount);
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
          radix_sum += radixcount;
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

// Function prototype for the Bubble Sort.
int bubbleSort(int Array[])
{
     bool swapped = true;
     int j = 0;

     // Number of comparisons
     int bubblecount = 0;

     // Continue to loop until
     // no swaps have occurred.
     while (swapped)
     {
          // Reset boolean flag
          swapped = false;
          // Because bubbleSort puts the last
          // value in the correct position each
          // time through the loop, the limit of
          // the inner loop decreases by one each
          // iteration of the outer loop (SIZE -j)
          for (int i = 1; i < SIZE - j; i++)
          {
               bubblecount++;
               // compare two side-by-side values
               // and swap if they are out of order
               if (Array[i - 1] > Array[i])
               {
                    swapped = true;
                    swap(Array[i - 1], Array[i]);
               }
          }
          j++;
     }
     return bubblecount;
}

// Function to get the largest element from an array
int getMax(int array[], int n)
{
     int max = array[0];
     for (int i = 1; i < n; i++)
          if (array[i] > max)
               max = array[i];
     return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place, int &radixcount)
{
     const int max = 10;
     int output[size];
     int count[max];

     for (int i = 0; i < max; ++i)
          count[i] = 0;

     // Calculate count of elements
     for (int i = 0; i < size; i++)
          count[(array[i] / place) % 10]++;

     // Calculate cumulative count
     for (int i = 1; i < max; i++)
          count[i] += count[i - 1];

     // Place the elements in sorted order
     for (int i = size - 1; i >= 0; i--)
     {
          output[count[(array[i] / place) % 10] - 1] = array[i];
          count[(array[i] / place) % 10]--;
          radixcount++;
     }

     for (int i = 0; i < size; i++)
          array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size, int &radixcount)
{
     // Get maximum element
     int max = getMax(array, size);

     // Apply counting sort to sort elements based on place value.
     for (int place = 1; max / place > 0; place *= 10)
          countingSort(array, size, place, radixcount);
}

/***************************************************
   Initially assigns the pivot position as the left-most
   (sub)array position.  Array is modified so that all
   values less than pivot are to the left of the pivot
   and all values greater than pivot are moved to the
   right of the pivot.  The pivot position is returned
   to the calling function.
   *****************************************************/

int Partition(int a[], int b, int e, int &quickcount)
{
     // Pivot position assigned to left most position
     int p = b;
     while (b < e)
     {
          // Scan from right
          while (b < e && a[b] <= a[e])
          {
               e--;
               quickcount++;
          }

          // Swap values and update pivot position
          // if needed.
          if (a[b] > a[e])
          {
               swap(a[b], a[e]);
               p = e;
               b++;
          }

          // Scan from left
          while (b < e && a[b] <= a[e])
          {
               b++;
               quickcount++;
          }

          // Swap values and update pivot position
          // if needed.
          if (a[b] > a[e])
          {
               swap(a[b], a[e]);
               p = b;
               e--;
          }
     }
     // Return pivot position
     return p;
}

void quickSort(int a[], int p, int r, int &quickcount)
{
     if (p < r)
     {
          // Partition the array and get pivot position
          int q = Partition(a, p, r, quickcount);

          // Sort left and right sub-arrays
          quickSort(a, p, q - 1, quickcount);
          quickSort(a, q + 1, r, quickcount);
     }
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