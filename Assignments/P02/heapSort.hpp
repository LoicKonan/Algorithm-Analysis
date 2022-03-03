/****************************************
Tina Johnson
CMPS 5243
This program will demonstrate the nlogn
sorting algorithm, heap sort.
*******************************************/

#include <iostream>

int HeapCount = 0;

namespace HeapSort
{
    using namespace std;

    void heapify(int arr[], int n, int i, int &HeapCount)
    {
        // Find largest among root, left child and right child
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
            HeapCount++;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
            HeapCount++;
        }

        // Swap and continue heapifying if root is not largest
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest, HeapCount);
        }
    }

    // main function to do heap sort
    void heapSort(int arr[], int n, int &HeapCount)
    {
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, HeapCount);

        // Heap sort
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);

            // Heapify root element to get highest element at root again
            heapify(arr, i, 0, HeapCount);
        }
    }
}