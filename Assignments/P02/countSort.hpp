/******************************************************************************

https://www.programiz.com/dsa/counting-sort

This program will demonstrate the (n) sorting algorithm of the Counting sort.
This program will return the number of comparisons that occur in this
algorithm.

******************************************************************************/

#include <iostream>

namespace CountSort
{
    using namespace std;

    int countSort(int array[], int _SIZE)
    {
        // The _SIZE of count must be at least the (max+1) but
        // we cannot assign declare it as int count(max+1) in C++ as
        // it does not support dynamic memory allocation.
        // So, its _SIZE is provided statically . 
        // I believe this solved the problem.
        
        int output[5001];
        int count[5001];
        int comparisons = 0;
        int max = array[0];

        // Find the largest element of the array
        for (int i = 1; i < _SIZE; i++)
        {
            if (array[i] > max)
                max = array[i];
                comparisons++;
        }

        // Initialize count array with all zeros.
        for (int i = 0; i <= max; ++i)
        {
            count[i] = 0;
        }

        // Store the count of each element
        for (int i = 0; i < _SIZE; i++)
        {
            count[array[i]]++;
            comparisons++;
        }

        // Store the cumulative count of each array
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
            comparisons++;
        }

        // Find the index of each element of the original array in count array, and
        // place the elements in output array
        for (int i = _SIZE - 1; i >= 0; i--)
        {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
            comparisons++;
        }

        // Copy the sorted elements into original array
        for (int i = 0; i < _SIZE; i++)
        {
            array[i] = output[i];
        }
        return comparisons;
    }
}
