// Counting sort in C++ programming
// https://www.programiz.com/dsa/counting-sort
#include <iostream>

namespace CountSort
{
    using namespace std;

    int countSort(int Array[], int size, int maxVal = 9)
    {
        // The size of count must be at least the (max+1) but
        // we cannot assign declare it as int count(max+1) in C++ as
        // it does not support dynamic memory allocation.
        // So, its size is provided statically.
        int *output = new int[maxVal + 1];
        int *count = new int[maxVal + 1];
        int max = Array[0];
        int Number_Comparison = 0;

        // Find the largest element of the Array
        for (int i = 1; i < size; i++)
        {
            if (Array[i] > max)
                max = Array[i];
        }

        // Initialize count Array with all zeros.
        for (int i = 0; i <= max; ++i)
        {
            count[i] = 0;
        }

        // Store the count of each element
        for (int i = 0; i < size; i++)
        {
            count[Array[i]]++;
            Number_Comparison++;
        }

        // Store the cumulative count of each Array
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
            Number_Comparison++;
        }

        // Find the index of each element of the original Array in count Array, and
        // place the elements in output Array
        for (int i = size - 1; i >= 0; i--)
        {
            output[count[Array[i]] - 1] = Array[i];
            count[Array[i]]--;
            Number_Comparison++;
        }

        // Copy the sorted elements into original Array
        for (int i = 0; i < size; i++)
        {
            Array[i] = output[i];
        }

        return Number_Comparison;
    }
}