// Implement 3 different sorting algorithms on arrays of size 5000. bubble sort, selection sort, merge sort.
// Implement a separate counter for each sort. Initialize the counter to sero and increment inside loops of the associated sort.
// For example in the bubblesort loop, increment the counter inside the inner loop.
// For recursive sorts, use a global counter.
// Use a system clock timer to start the timer immediately before each sort and end immediately after each sort.
// Once you have the code working for one run, average the time and counter results over 20 runs, using a different random seed for each run. 
// An easy way to do this is to use the loop control variable as the random seed, rather than time(NULL).Make sure that the arrays hold identical values before sorting.


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

const int SIZE = 5000;

void swap(int &a, int &b);
int bubblesort(int arr[], int n);
int selection(int arr[], int n);
int merge(int arr[], int n);
void fillArray(int arr[], int n);
void printArray(int arr[], int n);
void copyArray(int arr[], int arr2[], int n);

int main()
{
    int arr[SIZE];
    int arr2[SIZE];
    int n = SIZE;
    
    fillArray(arr, n);
    copyArray(arr, arr2, n);

}


void fillArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}


void copyArray(int arr[], int arr2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
}


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int bubblesort(int arr[], int n)
{
    int i, j;
    int counter = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            counter++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return counter;
}


int selection(int arr[], int n)
{
    int i, j, min_idx;
    int counter = 0;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            counter++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
    return counter;
}


int merge(int arr[], int n)
{
    int i, j, k;
    int counter = 0;
    int temp[n];
    for (i = 0, j = n / 2, k = 0; k < n; k++)
    {
        counter++;
        if (j >= n / 2)
        {
            temp[k] = arr[i++];
        }
        else if (i >= n / 2)
        {
            temp[k] = arr[j++];
        }
        else if (arr[i] < arr[j])
        {
            temp[k] = arr[i++];
        }
        else
        {
            temp[k] = arr[j++];
        }
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    return counter;
}