// Quick sort in C++
// https://www.programiz.com/dsa/quick-sort

#include <iostream>

// Initialize the count for MergeSort 
int MergeCount = 0;

namespace MergeSort
{
    using namespace std;

    // to swap two array values.
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    /***************************************************
    Given a left and right array, values are copied
    into larger array, a, of size n in sorted order.
    ****************************************************/
    void merge(int lft[], int rt[], int a[], int n, int &MergeCount)
    {
        int i = 0, j = 0, k = 0;
        int lenLft = n / 2;
        int lenRt = n - lenLft;
        // Copy values in ascencing order into array a
        // until end of either left or right array is
        // reached.
        while (i < lenLft && j < lenRt)
        {
            if (lft[i] < rt[j])
            {
                a[k] = lft[i];
                i++;
                k++;
            }
            else
            {
                a[k] = rt[j];
                j++;
                k++;
            }
            MergeCount++;
        }
        // Copy any remaining values from the
        // left array.
        while (i < lenLft)
        {
            a[k] = lft[i];
            i++;
            k++;
            MergeCount++;
        }
        // Copy any remaining values from the
        // right array.
        while (j < lenRt)
        {
            a[k] = rt[j];
            j++;
            k++;
            MergeCount++;
        }
    }

    void mergeSort(int a[], int n, int &MergeCount)
    {
        MergeCount++;
        int i, mid, *left, *right;
        if (n >= 2)
        {
            mid = n / 2;
            // Dynamically create two new arrays to
            // store the left and right halves of array.
            left = new int[mid];
            right = new int[n - mid];
            // Copy into left and right arrays
            for (i = 0; i < mid; i++)
                left[i] = a[i];
            for (i = mid; i < n; i++)
                right[i - mid] = a[i];
            // Recursively sort the left half of the array.
            mergeSort(left, mid, MergeCount);
            // Recursively sort the right half of the array.
            mergeSort(right, n - mid, MergeCount);
            // Merge the array halves.
            merge(left, right, a, n, MergeCount);
        }
    }
}