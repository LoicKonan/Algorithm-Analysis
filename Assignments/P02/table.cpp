#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// Main method
int main()
{
    int colWidth = 15;
    // table header

     
    cout << ("***********************************************************************") 
         << ("*****************************************") << "\n\n";
    cout << setw(4.4*colWidth) << "Time Complexity\n\n";

    cout << setw(colWidth) << "Iteration" << setw(colWidth) << "BubbleSort" << setw(colWidth) 
         << "SelectionSort" << setw(colWidth) << "MergeSort" << setw(colWidth) 
         << "QuickSort" << setw(colWidth) << "RadixSort" << setw(colWidth) 
         << "CountingSort" << setw(colWidth) << "\n\n";
    
    cout << ("***********************************************************************")
         << ("*****************************************") << "\n\n";

    // create table of data
    int n = 1;
    while (n <= 20)
    {
        cout <<setw(12)<< fixed << setprecision(0) << n << setprecision(6) 
             << setw(colWidth)   << log10(n) << setw(colWidth) << sqrt(n) 
             << setw(colWidth)   << log10(n) << setw(colWidth) << sqrt(n) 
             << setw(colWidth)   << log10(n) << setw(colWidth) << sqrt(n) << "\n";
        
        n++;
    }

     cout << ("***********************************************************************") 
          << ("*****************************************") << "\n\n\n";

// table header
    cout << ("***********************************************************************") 
         << ("*****************************************") << "\n\n";
    cout << setw(4.6p *colWidth) << "Number of Comparisons \n\n";

    cout << setw(colWidth) << "Iteration" << setw(colWidth) << "BubbleSort" << setw(colWidth) 
         << "SelectionSort" << setw(colWidth) << "MergeSort" << setw(colWidth) 
         << "QuickSort" << setw(colWidth) << "RadixSort" << setw(colWidth) 
         << "CountingSort" << setw(colWidth) << "\n\n";
    
    cout << ("***********************************************************************")
         << ("*****************************************") << "\n\n";

    // create table of data
    int a = 1;
    while (a <= 20)
    {
        cout <<setw(12)<< fixed << setprecision(0) << n << setprecision(6) 
             << setw(colWidth)   << log10(a) << setw(colWidth) << sqrt(a) 
             << setw(colWidth)   << log10(a) << setw(colWidth) << sqrt(a) 
             << setw(colWidth)   << log10(a) << setw(colWidth) << sqrt(a) << "\n";
        
        a++;
    }

     cout << ("***********************************************************************") 
          << ("*****************************************") << "\n\n\n";



    cout << setw(4*colWidth)<< "Final Results\n";
    cout << ("\n\n***********************************************************************") 
          << ("*****************************************") << "\n\n";

    cout << setw(colWidth) << "Algorithms" << "\t\t\t\t" << "Average Time Complexity" 
         << "\t\t\t\t" << "Average Comparisons\n\n";
    cout << setw(4*colWidth) << "(Milliseconds)\n";

    cout << ("***********************************************************************") 
         << ("*****************************************") << "\n\n"; 
    
    
    cout << setw(colWidth)  << "BubbleSort"    << setw(2.8*colWidth) <<  "111.11" 
         << setw(2.8*colWidth) <<  "111.11"<< "\n\n"
         << setw(colWidth)  << "SelectionSort" << setw(2.8*colWidth) << "111.11"  
         << setw(2.8*colWidth) <<  "111.11"<< "\n\n"
         << setw(colWidth)  << "MergeSort"     << setw(2.8*colWidth) << "111.11"  
         << setw(2.8*colWidth) <<  "111.11"<< "\n\n"
         << setw(colWidth)  << "QuickSort"     << setw(2.8*colWidth) << "111.11"  
         << setw(2.8*colWidth) <<  "111.11"<< "\n\n"
         << setw(colWidth)  << "RadixSort"     << setw(2.8*colWidth) << "111.11"  
         << setw(2.8*colWidth) <<  "111.11"<< "\n\n"
         << setw(colWidth)  << "CountingSort"  << setw(2.8*colWidth) << "111.11"  
         << setw(2.8*colWidth) <<  "111.11"<< "\n\n";
    
    cout << ("***********************************************************************")
         << ("*****************************************") << "\n\n";


    return 0;
}