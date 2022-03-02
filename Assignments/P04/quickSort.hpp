// Quick sort in C++
// https://www.programiz.com/dsa/quick-sort

#include <iostream>

// Initialize the count for quickSort
int quickcount = 0;

namespace QuickSort
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
}