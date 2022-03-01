#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 5000;//total number of elements in an array.
void heading();//prints out program header and brief description of assignment
void fillArray(int arr[],int seed);//generates an array of random numbers using Rand  and a srand  with seed 20.
void copyArray(int arr1[], int arr2[]);//copies content of array 1 to array 2 such that both have same contents each single iteration.
void printArray(int arr[]);//prints array.
void swap(int &x, int &y);//used by bubble sort to swap items in their correct order.
int bubbleSort(int arr[]);//perform bubble sort.
int countSort(int array[],int SIZE);//perform counting sort.
void mergeSort (int arr[],int SIZE,int& count);//perform merge sort.
int MergeCount = 0;//number iterations performed by merge sort.

int main() 
{
  //gives the details of the program
  heading();
  int myArray1[SIZE], myArray2[SIZE], myArray3[SIZE];
  int bubblecount = 0;//mark number iterations performed by bubble sort
  int CountSortcount = 0;//mark number iterations performed by count sort
  int NumberOfRuns = 0;//mark number of arrays generated and sorted
  int SumBubbleSort,
      SumMergeSort,
      SumCountSort;

  double AverbubbleTime,
        AverMergeSortTime,
        SumMergeSortTime,
        SumBubblesortTime,
        AverCountSortTime,
        SumCountSortTime,
        AvCountSort,
        AvBubbleSort,
        AvMergeSort;

    for (int runs = 0; runs < 20; runs++)
  {
    
    SumBubbleSort = 0;
    SumMergeSort = 0;
    SumCountSort = 0;
    SumCountSortTime = 0;
    SumMergeSortTime = 0;
    SumBubblesortTime = 0;
    int seed;
    seed+= 20;
    NumberOfRuns+=1;

    //Generate an array of random numbers using a seed
    fillArray(myArray1,seed);

    //copy contents from the generated myarray1 to myArray2 and myArray3
    copyArray(myArray1, myArray2);
    copyArray(myArray1, myArray3);

    // Bubble sort using myArray1
    auto BubbleStart = chrono::high_resolution_clock::now();
  
      // unsync the I/O of C ++.
      ios_base::sync_with_stdio(false);
  
      bubblecount = bubbleSort(myArray1);
  
    auto BubbleEnd = chrono::high_resolution_clock::now();
  
     // Calculating total time taken by the program.
    double BubbleTime_taken = chrono::duration_cast<chrono::nanoseconds>(BubbleEnd - BubbleStart).count();


    //convert time taken to sort the array from nanoseconds to seconds.
    BubbleTime_taken *= 1e-9;
      
    // Counting sort using myArray2
    auto CountStart = chrono::high_resolution_clock::now();
  
     // unsync the I/O of C and C++.
     ios_base::sync_with_stdio(false);
    
      CountSortcount = countSort(myArray2,SIZE);
    
    auto CountEnd = chrono::high_resolution_clock::now();
  
     // Calculating total time taken by the program.
     double CountTime_taken = chrono::duration_cast<chrono::nanoseconds>(CountEnd - CountStart).count();
     //convert time taken to sort the array from nanoseconds to seconds.
     CountTime_taken *= 1e-9;
     
    
    //Merge sort using myArray3);
    
   auto startMerge = chrono::high_resolution_clock::now();
  
     // unsync the I/O of  C++.
     ios_base::sync_with_stdio(false);
  
    mergeSort(myArray3,SIZE,MergeCount);
  
   auto EndMerge = chrono::high_resolution_clock::now();
  
     // Calculating total time taken by the program.
     double MergeTime_taken = chrono::duration_cast<chrono::nanoseconds>(EndMerge - startMerge).count();
     //convert time taken to sort the array from nanoseconds to seconds.
     MergeTime_taken *= 1e-9;
  
      
    //Total number of iterations taken for each algorithim to sort 20 arrays.
     SumBubbleSort+=bubblecount;
     SumMergeSort+=MergeCount;
     SumCountSort+=CountSortcount;
    //Total time taken for each algorithim to sort 20 arrays.
     SumBubblesortTime+=BubbleTime_taken;
     SumMergeSortTime+=MergeTime_taken;
     SumCountSortTime+= CountTime_taken;
  }

  //average time taken for each algorithim to sort 20 arrays
  AvBubbleSort = (SumBubbleSort/NumberOfRuns);
  AvMergeSort = (SumMergeSort/NumberOfRuns);
  AvCountSort = (SumCountSort/NumberOfRuns);
  
  //average time taken for each algorithim to sort 20 arrays
  AverCountSortTime=(SumCountSortTime/NumberOfRuns);
  AverMergeSortTime=(SumMergeSortTime/NumberOfRuns);
  AverbubbleTime=(SumBubblesortTime/NumberOfRuns);
  
  cout << "1) BUBBLE SORT ALGORITHM(using myArray1):  \n\n";
  cout << "Average Time taken to sort 20 arrays is: " <<AverbubbleTime<< " seconds\n";
  cout <<"Average number of iterations: "<<AvBubbleSort<< " \n\n";
    
  cout << "2) MERGE SORT ALGORITHM(using myArray3): \n\n";
  cout << "Average Time taken to sort 20 arrays is  : " << fixed << setprecision(5) << AverMergeSortTime<< " seconds\n";
  cout <<"Average number of iterations: "<<AvMergeSort<< " \n\n";
  
  cout << "3) COUNTING SORT ALGORITHM(using myArray2):  \n\n";
  cout << "Average  Time taken to sort 20 arrays is : " << fixed << setprecision(5) << AverCountSortTime<< " seconds\n";
  cout <<"Average number of iterations: "<<AvCountSort<< " \n";
  
  return 0;
 }





/**********************************************************************
  Used to generate an array of random values using a seed
************************************************************************/
 void fillArray(int arr[],int seed)
  {
  srand(seed);
  for(int i = 0; i < SIZE; i++)
    arr[i] = rand()%100;
 }
 /**********************************************************************
  Used to copy out  array values from the array generated to other 
  arrays that are to be used in the other sort algorithms to ensure
  that all arrays have the same values for each run during sorting.
************************************************************************/
 void copyArray(int arr1[], int arr2[])
{
  for(int i = 0; i < SIZE; i++)
    arr2[i] = arr1[i];
 }
 // Used to print out  array values.
 void printArray(int arr[])
 {
  for(int i = 0; i < SIZE; i++)
    cout << setw(4) << arr[i];
  cout << "\n\n";
}

// Used with bubble sort to swap two array values.
void swap(int &m, int &n)
{
  int temp = m;
  m = n;
  n = temp;
}
//perform bubble sort
//citing bubble sort from https://d2l.msutexas.edu/d2l/le/content/82590/viewContent/1191933/View
int bubbleSort(int arr[])
{
 
  bool swapped = true;// flag to determinine if a swap has been made
  int j = 0, c = 0;
  // Continue to loop until no swaps have occurred. 
  while (swapped)
  {
    // Reset boolean flag
    swapped = false;
    // Because bubbleSort puts the last  value in the correct position each time through the 
    //loop, the limit of the inner loop decreases by one each iteration of the outer loop (SIZE -j)
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
//End cited code

/***************************************************
Given a left and right array, values are copied
into a larger array, a, of size n in sorted order.
****************************************************/
//citing mergesort https://d2l.msutexas.edu/d2l/le/content/82590/viewContent/1189940/View?ou=82590
void merge(int left[], int right[], int a[], int n,int &count )
{
  // i - to mark the index of left sub-array (left)
	// j - to mark the index of right sub-raay (right)
	// k - to mark the index of merged sub-array (a)
  int i = 0, j = 0, k = 0;

  int lenleft = n / 2;
  int lenright = n - lenleft;
  // Copy values in ascencing order into array a
  // until end of either left or right array is 
  // reached.
  while (i < lenleft && j < lenright)
  {
    if (left[i] < right[j])
    {
      a[k] = left[i];
      i++;
      k++;
      
    }
    else
    {
      a[k] = right[j];
      j++;
      k++;
      
    }
   MergeCount++; 
  }
  // Copy any remaining values from the
  // left array.
  while(i < lenleft)
  {      
    a[k] = left[i];
    i++;
    k++; 
    MergeCount++;
  }
  // Copy any remaining values from the
  // right array. 
  while(j < lenright)
  {
    a[k] = right[j];
    j++;
    k++;    
    MergeCount++;
  }  
}


void mergeSort(int a[], int n,int &count ) 
{ 
  int i, mid, *left, *right;
  MergeCount++;
     
  if(n < 2) return; // base condition. If the array has less than two element, do nothing.
    mid = n / 2; // find the mid index.
    // Dynamically create two new sub-arrays to
    // store the left and right halves of array.
    left = new int[mid];
    right = new int[n - mid];
    // Copy into left and right arrays
    for (i = 0; i < mid; i++)// creating left sub-array
      left[i] = a[i];
      
    for (i = mid; i < n; i++)
      right[i-mid] = a[i];
       
    // Recursively sort the left half of the sub-array.
    mergeSort(left, mid,MergeCount);
    // Recursively sort the right half of the sub-array.
    mergeSort(right, n-mid,MergeCount);
    // Merge the sub-arrays halves.
    merge(left, right, a, n,MergeCount );
}
//End cited code


// Counting sort
//Citing counting sort from https://www.programiz.com/dsa/counting-sort
 int countSort(int array[],int SIZE)
{
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int output[SIZE];
  int count[SIZE];
   int c = 0;
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < SIZE; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < SIZE; i++) {
    count[array[i]]++;
     c++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) 
  {
    count[i] += count[i - 1];
   c++;
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = SIZE - 1; i >= 0; i--) 
  {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
    c++;
  }  

  // Copy the sorted elements into original array
  for (int i = 0; i < SIZE; i++) 
  {
    array[i] = output[i];
  }
   return c;
}
//End cited code
void heading()
{

}