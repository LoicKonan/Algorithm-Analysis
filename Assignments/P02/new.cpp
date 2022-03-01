/*#include <iostream>
 // C++ program for implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;

void swap(int &xp, int &yp)
{
        int temp = xp;
        xp = yp;
        yp = temp;
}
void bubbleSort(int arr[]);
void printArray(int arr[])
;
// Driver code
int main() {

int size;
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr)/sizeof(arr[0]);
        bubbleSort(arr);
        cout<<"Sorted array: \n";
        printArray(arr);
        return 0;
}
// A function to implement bubble sort
void bubbleSort(int arr[])
{
        int i, j;
        for (i = 0; i < size; i++)    
        
        // Last i elements are already in place
        for (j = 0; j < size-i-1; j++)
                if (arr[j] > arr[j+1])
                        swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
/*void printArray(int arr[], int size)
{
        int i;
        for (i = 0; i < size; i++)
                cout << arr[i] << " ";
        cout << endl;
}*/

/****************************************
/ Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;

        // Create temp arrays
        auto *leftArray = new int[subArrayOne],
                *rightArray = new int[subArrayTwo];

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++)
                leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
                rightArray[j] = array[mid + 1 + j];

        auto indexOfSubArrayOne = 0, // Initial index of first sub-array
                indexOfSubArrayTwo = 0; // Initial index of second sub-array
        int indexOfMergedArray = left; // Initial index of merged array

        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
                if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                        indexOfSubArrayOne++;
                }
                else {
                        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                        indexOfSubArrayTwo++;
                }
                indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
                indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
                indexOfMergedArray++;
        }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
/*void mergeSort(int array[], int const begin, int const end)
{
        if (begin >= end)
                return; // Returns recursively

        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
        for (auto i = 0; i < size; i++)
                cout << A[i] << " ";
}
*******************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
#include <thread>




using namespace std;

/*class timez
{
private:
    // Type aliases to make accessing nested type easier
    using clock_type = std::chrono::steady_clock;
    using second_type = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_type> m_beg{ clock_type::now() };

public:

    void reset()
    {
        m_beg = clock_type::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
    
};*/
class timez{
  public:
  //std::chrono::time_point<std::chrono::system_clock> start;
  std::chrono::time_point <std::chrono::system_clock> start,end;
   std::chrono::duration<float> duration;
  timez(){
    start = std::chrono::high_resolution_clock::now();
    


  }
  ~timez(){
    //start = std::chrono::high_resolution_clock::now();
   fun();
    
 
  }
float fun(){
  end = std::chrono::high_resolution_clock::now();

   duration = end-start;
   float ms= duration.count()*10000.0f;
   std::cout <<ms <<std::endl;
    }
  };


/*class timez{
  public:
  timez()
{
m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

~timez()
{

stop();

}

float stop(){
auto endpoint = std::chrono::high_resolution_clock::now();
auto start =std::chrono::time_point_cast<std::chrono::microseconds> (m_StartTimepoint).time_since_epoch().count();
auto end =std::chrono::time_point_cast<std::chrono::microseconds> (endpoint).time_since_epoch().count();

auto duration =end -start;
double ms=duration *0.001;


std::cout << duration <<"us("<<ms<<"ms)\n";
return ms;
}

  private:
std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;

};*/


const int SIZE = 10;

void fillArray(int arr[],int seed);
void copyArray(int arr1[], int arr2[]);
void printArray(int arr[]);
void swap(int &x, int &y);
int bubbleSort(int arr[]);
int selectionSort(int arr[]);
int insertionSort(int arr[]);

int main() {
  
  int myArray1[SIZE], myArray2[SIZE], myArray3[SIZE];
  int bubblecount = 0;
  int insertioncount=0;
  int mergecount=0;
  int time,runs,r;
  int bublesum,insertionsum,mergesum,Avbubble,Avinsertion,Avmerge;
  runs=0;
  r=0;
  bublesum=0;
  insertionsum=0;
  mergesum=0;
  for (runs=0;runs<1;runs++){
    int seed;
    seed=seed+20;
    
    
  fillArray(myArray1,seed);
  copyArray(myArray1, myArray2);
  copyArray(myArray1, myArray3);
  cout << "Array 1:  \n";
  printArray(myArray1);
  bubblecount = bubbleSort(myArray1);
  cout << "Bubble count:  " << bubblecount << endl;
 cout << "Array 1 sorted with Bubble Sort: \n";
  printArray(myArray1);
  //cout << "Array 2:  \n";
  //printArray(myArray2);
 //bubblecount = selectionSort(myArray2);
 // cout << "selection count:  " << bubblecount << endl;
 // cout << "Array 2 sorted with Selection Sort: \n";
  //printArray(myArray2);
  cout << "Array 3:  \n";
  printArray(myArray3);
 insertioncount = insertionSort(myArray3);
  cout << "insertion count:  " << insertioncount << endl;
 cout << "Array 3 sorted with Insertion Sort: \n";
  
  printArray(myArray3);

   bublesum=bublesum+bubblecount;
   insertionsum=insertionsum+insertioncount;
  r=r+1;
   
  
  }
  Avinsertion=(insertionsum/r);
   Avbubble=(bublesum/r);
  cout <<Avbubble<< "  avarage buble \n";
  cout <<r<< " \n";
  //cout <<sum<< " \n";


cout <<Avinsertion<< "  average insertion \n";

  /*r=0;
  sum=0;
  cout <<sum<< " \n";

   cout <<sum<< " \n";
  for (runs=0;runs<2;runs++){

     int seed;
    seed=seed+20;
      fillArray(myArray1,seed);
  copyArray(myArray1, myArray2);
cout << "Array 1:  \n";
 printArray(myArray1);
  bubblecount = bubbleSort(myArray1);
  cout << "Bubble count:  " << bubblecount << endl;
 cout << "Array 1 sorted with Bubble Sort: \n";
 printArray(myArray1);
 
 sum=sum+bubblecount;
  r=r+1;
   
 
  }
  x=(sum/r);
  cout <<x<< " \n";
  cout <<r<< " \n";
  cout <<sum<< " \n";*/

  return 0;
}

void fillArray(int arr[],int seed)
{
  srand(seed);
  for(int i = 0; i < SIZE; i++)
    arr[i] = rand()%100;
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

// Used with bubbleSort and selectionSort 
// to swap two array values.
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int bubbleSort(int arr[])
{
  timez time;
  bool swapped = true;
  int j = 0, c = 0;
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

int selectionSort(int arr[])
{
  timez time;
  
  int minIndex,c;
  c=0;
  for (int i = 0; i < SIZE; i++)
  {
    // Assume index of smallest value is in the
    // ith position (first value for that iteration)
    minIndex = i;
    for (int j = i + 1; j < SIZE; j++)
    {c++;
      // If a smaller value is found, update minIndex
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    // If smallest number is already in correct position
    // no need to swap.
    if (i != minIndex)
      swap(arr[i], arr[minIndex]);
  }
  return c;
 //float e =time.duration;
}

int insertionSort(int arr[])
{
  timez time;
  int i, j, temp,c;
  c=0;
  for (i = 1; i < SIZE; i++)
  {
   
    // Store the value to be inserted into
    // correct position.
    temp = arr[i];
    j = i - 1;
    // Shift values to the right in the
    // array until correct position is found.
    while (j >= 0 && arr[j] > temp)
    {
      arr[j+1] = arr[j];
      j--;
       c++;
    }
    // Insert stored value in correct position.
    arr[j+1] = temp;
  }
  return c;
 
}