/***********************************************************************************
copyright: https://www.geeksforgeeks.org/selection-sort/

This program will demonstrate the (n ^ 2) sorting algorithm, Selection sort.
This program will return the number of comparisons that occur in this
algorithm.

************************************************************************************/
#include <iostream>

namespace SelectionSort
{
    using namespace std;

    // to swap two Array values.
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    int selectionSort(int Array[])
    {
        // Initialize the variables.
        int selectioncount = 0;
        int minIndex;
        for (int i = 0; i < _SIZE; i++)
        {
            // Assume index of smallest value is in the
            // ith position (first value for that iteration)
            minIndex = i;
            for (int j = i + 1; j < _SIZE; j++)
            {
                // If a smaller value is found, update minIndex
                if (Array[j] < Array[minIndex])
                    minIndex = j;
                selectioncount++;
            }
            // If smallest number is already in correct position
            // no need to swap.
            if (i != minIndex)
                swap(Array[i], Array[minIndex]);
        }
        return selectioncount;
    }
}