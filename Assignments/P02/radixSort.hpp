/***********************************************************************************
copyright: https://www.programiz.com/dsa/radix-sort

This program will demonstrate the (n) sorting algorithm, Radix sort.
Using a global variable to determine the number of comparisons that will occur in
this algorithm.

************************************************************************************/
#include <iostream>

// Initialize the counter for RadixSort.
int radixcount = 0;

namespace RadixSort
{
    using namespace std;
    // A utility function to get maximum value in arr[]
    int getMax(int arr[], int n)
    {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

    // A function to do counting sort of arr[] according to
    // the digit represented by exp.
    void countSort(int arr[], int n, int exp, int &radixcount)
    {
        int output[n]; // output array
        int i, count[10] = {0};

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual
        // position of this digit in output[]
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
            radixcount++;
        }

        // Build the output array
        for (i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
            radixcount++;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < n; i++)
        {
            arr[i] = output[i];
            radixcount++;
        }
    }

    // The main function that sorts arr[] of _SIZE n using Radix Sort
    void radixsort(int arr[], int n, int &radixcount)
    {
        // Find the maximum number to know number of digits
        int m = getMax(arr, n);

        // Do counting sort for every digit. Note that instead
        // of passing digit number, exp is passed. exp is 10^i
        // where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
        {
            countSort(arr, n, exp, radixcount);
            radixcount++;
        }
    }
}