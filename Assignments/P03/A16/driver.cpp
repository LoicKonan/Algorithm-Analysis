#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "countSort.hpp"
#include "heapSort.hpp"
#include "quickSort.hpp"
#include "radixSort.hpp"
#include "BubbleSort.hpp"

using namespace std;
using namespace std::chrono;

const int _SIZE    = 5000;
const int SEED     = 20;

struct sortCompare 
{
    int*             data;  // array of numbers
    int*             copy;  // copy of array to actually sort
    int              _SIZE;     // size or number of values to sort
    int              m;     // max number
    vector< string > sortNames;

    sortCompare() 
    {
        m = 1073741824;
        sortNames = {"countSort", "heapSort", "quickSort", "radixSort"};
    }

    // function to print the array
    void printArray() 
    {
        for (int i = 0; i < _SIZE; i++) 
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void copyArray() 
    {
        copy = new int[_SIZE];

        for (int i = 0; i < _SIZE; i++) 
        {
            copy[i] = data[i];
        }
    }

    // Set the seed value
    void Seed()
    {
        for (int i = 0; i < SEED; i++)
            srand(i);
    }

    // Function to fill the array.
    void fillArray(int data[])
    {
        for (int i = 0; i < _SIZE; i++)
            data[i] = rand() % 5000;
    }

    void callSortMethod(string sortName) 
    {
        cout << "Making copy of data: \n";
        copyArray();

        cout << "Performing " << sortName << "..." << endl;

        auto start = high_resolution_clock::now();

        if (sortName == "countSort") 
        {
            CountSort::countSort(copy, _SIZE, m);
        } 
        else if (sortName == "heapSort") 
        {
            HeapSort::heapSort(copy, _SIZE);
        } 
        else if (sortName == "quickSort") 
        {
            QuickSort::quickSort(copy, 0, _SIZE - 1);
        } 
        else if (sortName == "radixSort") 
        {
            RadixSort::radixsort(copy, _SIZE);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast< microseconds >(stop - start);

        cout << "Duration: " << duration.count() << " microSeconds."<<endl;
        cout << "Writing " << sortName << ".out" << endl;
        
        delete[] copy;
    }
};

// Driver code
int main() 
{
    sortCompare SC;

    for (int i = 0; i < SC.sortNames.size(); i++) 
    {
        SC.callSortMethod(SC.sortNames[i]);
    }

    cout << SC.sortNames[0] << endl;

    return 0;
}