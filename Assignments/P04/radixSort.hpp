// Radix Sort in C++ Programming
// https://www.programiz.com/dsa/radix-sort

#include <iostream>

// Initialize the count for Radix 
int radixcount = 0;

namespace RadixSort
{
    using namespace std;

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
}