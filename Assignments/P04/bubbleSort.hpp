// Quick sort in C++
// https://www.geeksforgeeks.org/bubble-sort/

#include<iostream>

namespace BubbleSort
{
    using namespace std;

    // to swap two array values.
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    // Function prototype for the Bubble Sort.
    int bubbleSort(int Array[])
    {
        bool swapped = true;
        int j = 0;

        // Number of comparisons
        int bubblecount = 0;

        // Continue to loop until
        // no swaps have occurred.
        while (swapped)
        {
            // Reset boolean flag
            swapped = false;
            // Because bubbleSort puts the last
            // value in the correct position each
            // time through the loop, the limit of
            // the inner loop decreases by one each
            // iteration of the outer loop (SIZE -j)
            for (int i = 1; i < _SIZE - j; i++)
            {
                bubblecount++;
                // compare two side-by-side values
                // and swap if they are out of order
                if (Array[i - 1] > Array[i])
                {
                    swapped = true;
                    swap(Array[i - 1], Array[i]);
                }
            }
            j++;
        }
        return bubblecount;
    }
}