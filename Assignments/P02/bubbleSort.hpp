// Counting sort in C++ programming
// https://www.programiz.com/dsa/bubbleSort-sort
#include <iostream>

namespace BubbleSort
{

    // to swap two array values.
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    // Function to sort the array using bubble sort.
    int bubbleSort(int arr[])
    {
        bool swapped = true;
        int j = 0;
        int bubblecount = 0;

        // Continue to loop until
        // no swaps have occurred.
        while (swapped)
        {
            // Reset boolean flag
            swapped = false;
            // Because bubbleSort puts the last value in the
            // correct position eachtime through the loop, the
            // limit of the inner loop decreases by one each
            // iteration of the outer loop (_SIZE - j)
            for (int i = 1; i < _SIZE - j; i++)
            {
                bubblecount++;
                // compare two side-by-side values
                // and swap if they are out of order
                if (arr[i - 1] > arr[i])
                {
                    swapped = true;
                    swap(arr[i - 1], arr[i]);
                }
            }
            j++;
        }
        return bubblecount;
    }
}