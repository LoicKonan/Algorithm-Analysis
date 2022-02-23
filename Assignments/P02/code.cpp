// Implement 3 different sorting algorithms on arrays of size 5000. 
// You may choose the sorting algorithms, but select one sort from each 
// runtime category: O(n2), O(n log n), O(n)

// Implement a separate counter for each sort. 
// Initialize the counter to zero and increment inside loops of the associated sort. 
// For example, in the O(n2) loop, increment the counter inside the inner loop. 
// Use a system clock timer to start the time immediately before each sort and end immediately after each sort. 
// Once you have the code working for one run, average the time and counter results over 20 runs.


#include <iostream>
#include <random>

using namespace std;

const int NUMBER = 5000;

