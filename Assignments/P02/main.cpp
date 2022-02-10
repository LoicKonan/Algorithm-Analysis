// Implement 3 different sorting algorithms on arrays of size 10. bubble sort, selection sort, merge sort.
// Implement a separate counter for each sort. Initialize the counter to zero and increment inside loops of the associated sort.
// For example in the bubblesort loop, increment the counter inside the inner loop.
// For recursive sorts, use a global counter.
// Use a system clock timer to start the timer immediately before each sort and end immediately after each sort.
// Once you have the code working for one run, average the time and counter results over 20 runs, using a different random seed for each run. 
// An easy way to do this is to use the loop control variable as the random seed, rather than time(NULL).Make sure that the arrays hold identical values before sorting.


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

const int SIZE = 10;

void swap(int &a, int &b);
int bubble_Sort(int arr[], int SIZE);
int selection_Sort(int arr[], int SIZE);
int merge_Sort(int arr[], int SIZE);

