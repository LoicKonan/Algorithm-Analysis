/***********************************************************************************
copyright: Tina Johnson CMPS 5243

This program will demonstrate the (n log n) sorting algorithm, Quick sort.
Using a global variable to determine the number of comparisons that will occur in
this algorithm.

************************************************************************************/

#include <iostream>

int quickcount = 0;

namespace QuickSort
{
    /* This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    int partition(int arr[], int low, int high, int &quickcount)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element and
                               // indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++)
        {
            quickcount++;
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    /* The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index */
    void quickSort(int arr[], int low, int high, int &quickcount)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(arr, low, high, quickcount);

            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1, quickcount);
            quickSort(arr, pi + 1, high, quickcount);
        }
    }
}