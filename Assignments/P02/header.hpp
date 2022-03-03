#include <iostream>
using namespace std;

namespace Header
{
    void header()
    {
        cout << "*******************************************************************************************************\n";
        cout << "*";
        cout << "\n*    Author:           Loic Konan";
        cout << "\n*    Email:            loickonan.lk@gmail.com";
        cout << "\n*    Label:            Sorting Algorithms";
        cout << "\n*    Title:            Program 2";
        cout << "\n*    Course:           CMPS 5246,  Spring number22, Dr. Johnson";
        cout << "\n*    Semester:         Spring 2022";
        cout << "\n*    Description:";
        cout << "\n*";
        cout << "\n*                  This program implements the following sorting algorithms:";
        cout << "\n*";
        cout << "\n*                     - Bubble Sort     O(n^2)";
        cout << "\n*                     - Selection Sort  O(n^2)";
        cout << "\n*                     - Insertion Sort  O(n^2)";
        cout << "\n*                     - Merge Sort      O(n log n)";
        cout << "\n*                     - Quick Sort      O(n log n)";
        cout << "\n*                     - Heap Sort       O(n log n)";
        cout << "\n*                     - Radix Sort      O(n)";
        cout << "\n*                     - Counting Sort   O(n)\n*";
        cout << " \n*";
        cout << " \n*";
        cout << "                     Each algorithm is implemented in a separate .hpp file.\n*";
        cout << "                     The goal of this program is to compare the performance\n*";
        cout << "                     of each algorithm.\n*";
        cout << "                     After 20 Iterations, I calculate the average time\n*";
        cout << "                     and counter it takes to to sort the data of our Arrays of\n*";
        cout << "                     size 5000 (random numbers). The counter for each sort\n*";
        cout << "                     is first Initialize to zero and incremented inside the loops\n*";
        cout << "                     of the associated sort, or I pass back the count using a \n*";
        cout << "                     return statement or reference variable. I Use a system \n*";
        cout << "                     clock timer to start the time immediately  before each sort\n*";
        cout << "                     and end immediately after each sort.\n*";
        cout << "                     Finally The average time is calculated by dividing the total\n*";
        cout << "                     time by 20 \n*";
        cout << " \n*";
        cout << " \n*";;
        cout << "\n*";
        cout << "\n*    Files:";
        cout << "\n*                  main.cpp";
        cout << "\n*                  header.hpp";
        cout << "\n*                  bubbleSort.hpp";
        cout << "\n*                  selectionSort.hpp";
        cout << "\n*                  insertionSort.hpp";
        cout << "\n*                  mergeSort.hpp";
        cout << "\n*                  quickSort.hpp";
        cout << "\n*                  heapSort.hpp";
        cout << "\n*                  radixSort.hpp";
        cout << "\n*                  countingSort.hpp";
        cout << "\n*                  termcolor.hpp";
        cout << "\n*                  copyArray.hpp";
        cout << "\n*                  printArray.hpp";
        cout << "\n*                  fillArray.hpp";
        cout << "\n*";
        cout << "\n*";
        cout << "\n*    Usage:";
        cout << "\n*           main.cpp          : driver program";
        cout << "\n*";
        cout << "\n*";
        cout << "\n*******************************************************************************************************\n\n";
    }
}