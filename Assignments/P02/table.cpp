#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// Main method
int main()
{
    int colWidth = 15;
    // table header
    cout << setfill('*') << setw(3 * colWidth) << "*" << "\n";

    cout << setfill(' ') << fixed << "\n\n";

    cout << setw(colWidth) << "Iterations: " << setw(colWidth) << "BubbleSort" 
         << setw(colWidth) << "SelectionSort" << setw(colWidth) << "insertionSort"
         << setw(colWidth) << "heapsort" << setw(colWidth) << "QuickSort" << setw(colWidth) 
         << setw(colWidth) << "MergeSort" << setw(colWidth) << "RadixSort" << setw(colWidth) 
         << setw(colWidth) << "CountingSort" << setw(colWidth);
    
    cout << setfill('*') << setw(3 * colWidth) << "*" << "\n";
    cout << setfill(' ') << fixed;

    // create table of data
    int n = 1;
    while (n <= 20)
    {
        cout << setprecision(0) << setw(colWidth) << n << setprecision(4) 
            << setw(colWidth)   << log10(n) << setw(colWidth) << sqrt(n) << "\n";
        
        n++;
    }

    return 0;
}