// Implement 3 different sorting algorithms on arrays of size 10. 
// You may choose the sorting algorithms, but select one sort from each 
// runtime category: O(n2), O(n log n), O(n)

// Implement a separate counter for each sort. 
// Initialize the counter to zero and increment inside loops of the associated sort. 
// For example, in the O(n2) loop, increment the counter inside the inner loop. 
// Use a system clock timer to start the time immediately before each sort and end immediately after each sort. 
// Once you have the code working for one run, average the time and counter results over 20 runs.


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int SIZE = 10;

void fillArray(int arr[]);
void copyArray(int arr1[], int arr2[]);
void printArray(int arr[]);
void swap(int &x, int &y);
int bubbleSort(int arr[]);
int partition(int a[], int beg, int end);
void quickSort(int a[], int p, int r);
void countingsSort(int arr[]);

int main()
{
    // Initialize the array to random values.
    int myArray1[SIZE], myArray2[SIZE], myArray3[SIZE];
    // Initialize the counter to zero and increment inside loops of the associated sort.
    int bubblecount = 0;

    // 
    fillArray(myArray1);

    // 
    copyArray(myArray1, myArray2);
    copyArray(myArray1, myArray3);

    cout << "Array 1:  \n";
    printArray(myArray1);

    bubblecount = bubbleSort(myArray1);
    cout << "Bubble count:  " << bubblecount << endl;
    cout << "Array 1 sorted with Bubble Sort: \n";
    printArray(myArray1);

    cout << "Array 2:  \n";
    printArray(myArray2);
    quickSort(myArray2, 0, SIZE - 1);
    cout << "Array 2 sorted with Quick Sort: \n";
    printArray(myArray2);

    cout << "Array 3:  \n";
    printArray(myArray3);
    countingsSort(myArray3);
    cout << "Array 3 sorted with Counting Sort: \n";
    printArray(myArray3);

    return 0;
}

void fillArray(int arr[])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;
}

void copyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < SIZE; i++)
        arr2[i] = arr1[i];
}

void printArray(int arr[])
{
    for (int i = 0; i < SIZE; i++)
        cout << setw(4) << arr[i];
    cout << "\n\n";
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int bubbleSort(int arr[])
{
    int bubblecount = 0;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                bubblecount++;
            }
        }
    }
    return bubblecount;
}

int partition(int a[], int beg, int end)
{
    int pivot = a[beg];
    int i = beg + 1;
    int j = end;
    while (i <= j)
    {
        while (i <= end && a[i] <= pivot)
            i++;
        while (j >= beg && a[j] > pivot)
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[beg], a[j]);
    return j;
}

void quickSort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

void countingsSort(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < SIZE; i++)
        if (arr[i] > max)
            max = arr[i];
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < SIZE; i++)
        count[arr[i]]++;
    for (int i = 0, j = 0; i <= max; i++)
        while (count[i]-- > 0)
            arr[j++] = i;
}