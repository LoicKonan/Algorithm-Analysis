/****************************************
Tina Johnson
CMPS 5243
This program will demonstrate O(n) sorting 
algorithms, counting sort and radix sort.
*******************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

// SIZE is one more than number of elements; This 
// version of counting sort begins index at 1
const int SIZE = 11;

// K represents the range of numbers stored.
// In this case the array will be filled with
// integers from 0-9999.
const int K = 10000;

// KD represents the range of values for each 
// digit 0..9; used for counting sort that is 
// called by radix sort.
const int KD = 10;

void fillArray(int a[]);
void printArray(int a[]);
void copyArray(int arr1[], int arr2[]);
void countingSort(int a[], int b[]);
void countingSortDigit(int a[], int b[], int d);
void radixSort(int a[], int d);

int main() {
  int myArray[SIZE], myArray2[SIZE];
  fillArray(myArray);
  countingSort(myArray, myArray2);
  cout << "Original Array:  \n";
  printArray(myArray);
  countingSort(myArray, myArray2);
  cout << "Array sorted with Counting Sort: \n";
  printArray(myArray2);
  cout << "Original Array:  \n";
  printArray(myArray);
  radixSort(myArray, 4);
  cout << "Array sorted with Radix Sort: \n";
  printArray(myArray);
  return 0;
}

void heading()
{
  cout << "Tina Johnson \n";
  cout << "CMPS 5243 \n\n";
  cout << "Counting and Radix Sort Demo. \n\n";
}

void fillArray(int arr[])
{
/*  srand(time(NULL));
  for(int i = 1; i < SIZE; i++)
    arr[i] = rand() % K;
*/
  // This code is modified to check answers with worksheet.
  // Notice that 0th position is zero since counting sort and
  // radix sort start indexing with 1.
  int arr2[] = {0, 756, 2000, 15, 195, 3410, 253, 963, 7, 144, 8020};
  copyArray(arr2, arr);
}

void printArray(int arr[])
{
  for(int i = 1; i < SIZE; i++)
    cout << setw(6) << arr[i];
  cout << "\n\n";
}

void copyArray(int arr1[], int arr2[])
{
  for(int i = 1; i < SIZE; i++)
    arr2[i] = arr1[i];
}

/*
countingSort sorts a given array in linear time
by using an auxiliary array C, which counts the
number of elements less than or equal to each 
value in the array.  This is a stable sort, which  
means that when sorting numbers that have repeated 
values, relative order is maintained.
*/
void countingSort(int a[], int b[])
{
  int i, j, *c = new int[K];
  // Initialize array C to zero
  for (i = 0; i < K; i++)
    c[i] = 0;
  // Fill array c with the count of each 
  // integer in array a
  for (i = 1; i < SIZE; i++)
    c[a[i]]++;
  // Convert array c to a partial sum array, which
  // indicates the number of elements in array a
  // with a value that is less than or equal to the 
  // index value of c.
  for (i = 1; i < K; i++)
    c[i] += c[i-1];
  // Scan array a from the right and copy values
  // into array b based on location indicated 
  // by array c.
  for (j = SIZE - 1; j > 0; j--)
  {
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}

/*
countingSortDigit sorts a given array in order of
the specified digit value, 1 being the right-most
digit, 10^0 place value; 2 = 10^1 place value, etc.
This is a stable sort which is important when it
is used in conjunction with Radix sort.  This means
that when sorting numbers with the same digit value, 
relative order is maintained.
*/

void countingSortDigit(int a[], int b[], int d)
{
  int i, j, *c = new int[KD];
  // Determine place value based on the digit.
  // 1's place = 10^0; 10's place = 10^1; etc.
  int place = pow(10, (d-1));
  // Initialize array c to zero
  for (i = 0; i < KD; i++)
    c[i] = 0;
  // Fill array c with the count of the digits 0-9
  // for the specified digit location, d, of array a.
  // Ex. c[2] = 5 indicates that the array contains     
  // 5 values that have the digit 2 in location d.
  for (i = 1; i < SIZE; i++)
    c[a[i]/place % 10]++;

  // Convert array c to a partial sum array, which
  // indicates the number of elements with the digit
  // value less than or equal to the specified digit.
  for (i = 1; i < KD; i++)
    c[i] += c[i-1];

  // Scan array a from the right and copy values
  // into array b based on digit value location 
  // indicated by array c.
  for (j = SIZE - 1; j > 0; j--)
  {
    b[c[a[j]/place % 10]] = a[j];
    c[a[j]/place % 10]--;
  }
}

void radixSort(int a[], int d)
{
  int b[SIZE];
  for(int i = 1; i <= d; i++)
  {
    countingSortDigit(a, b, i);
    cout << "Array sorted after digit " << i << ": \n";
    // printArray inside radix sort to show
    // intermediate steps
    printArray(b);
    copyArray(b, a);
  }
}
