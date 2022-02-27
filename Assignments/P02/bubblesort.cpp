
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int SIZE = 5;

void fillArray(int arr[]);
void copyArray(int arr1[], int arr2[]);
void printArray(int arr[]);
void swap(int &x, int &y);

int bubbleSort(int arr[]);

int partition(int a[], int beg, int end);
void quickSort(int a[], int p, int r);

void countSort(int array[], int);


int main() 
{
  int myArray1[SIZE];
  int myArray2[SIZE];
  int myArray3[SIZE];

  int bubblecount = 0;
  int quickcount  = 0;
  int CountingCount  = 0;


  fillArray(myArray1);
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
  quickSort(myArray2, 0, SIZE);
  cout << "QuickSort count:  " << quickcount << endl;
  cout << "Array 2 sorted with Quick Sort: \n";
  printArray(myArray2);

  int n = sizeof(myArray3) / sizeof(myArray3[0]);

  cout << "Array 3:  \n";
  printArray(myArray3);
  countSort(myArray3, n);
  cout << "radix count:  " << CountingCount << endl;
  cout << "Array 3 sorted with Radix Sort: \n"; 
  printArray(myArray3);

  return 0;
}

void fillArray(int arr[])
{
  srand(time(NULL));
  for(int i = 0; i < SIZE; i++)
    arr[i] = rand() % 100;
}

void copyArray(int arr1[], int arr2[])
{
  for(int i = 0; i < SIZE; i++)
    arr2[i] = arr1[i];
}

void printArray(int arr[])
{
  for(int i = 0; i < SIZE; i++)
    cout << setw(4) << arr[i];
  cout << "\n\n";
}

// to swap two array values.
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}


int bubbleSort(int arr[])
{
  bool swapped = true;
  int j = 0, c = 0;
  // Continue to loop until
  // no swaps have occurred. 
  while (swapped)
  {
    // Reset boolean flag
    swapped = false;
    // Because bubbleSort puts the last value in the 
    // correct position eachtime through the loop, the 
    // limit of the inner loop decreases by one each
    // iteration of the outer loop (SIZE -j)
    for(int i = 1; i < SIZE - j; i++)
    {
      c++;
      // compare two side-by-side values
      // and swap if they are out of order
      if(arr[i-1] > arr[i])
      {
        swapped = true;
        swap(arr[i-1], arr[i]);
      }
    }
    j++;
  }
  return c;
}


int Partition(int a[], int b, int e)          
{
  // Pivot position assigned to left most position
  int p = b;
  while(b < e)
  {
    // Scan from right
    while(b < e && a[b] <= a[e])
      e--;
    // Swap values and update pivot position
    // if needed.
    if (a[b] > a[e])
    {
      swap(a[b],a[e]);
      p = e;
      b++;
    }
    // Scan from left
    while(b < e && a[b] <= a[e])
      b++;
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

void quickSort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
    // Partition the array
 		q = Partition(a, p, r);   
    // Recursively sort the array to the left of the pivot       
		quickSort(a, p, q - 1);    
    // Recursively sort the array to the right of the pivot      
		quickSort(a, q + 1, r);			    
	}
}

void countSort(int array[], int SIZE) 
{
  // The SIZE of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its SIZE is provided statically.
  int output[10];
  int count[10];
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < SIZE; i++) 
  {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) 
  {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < SIZE; i++) 
  {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) 
  {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = SIZE - 1; i >= 0; i--) 
  {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < SIZE; i++) 
  {
    array[i] = output[i];
  }
}
