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
    cout << setw(5*colWidth) << "Time Complexity per Iteration\n\n";

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
    cout << setw(5*colWidth) << "Number of Comparisons per Iteration\n\n";

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
        cout <<setw(12)<< fixed << setprecision(0) << a << setprecision(6) 
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
    
//     cout << ("***********************************************************************")
//          << ("*****************************************") << "\n\n";



//     cout << ("\n\n***********************************************************************") 
//          << ("*******************************************************************") << "\n\n";
//     cout << setw(6*Column_Width) << "Time and Counter per Iteration\n\n";
//     cout << setw(5*Column_Width+6) << "(milliseconds)\n\n";


//     cout << setw(Column_Width-8) << "Loop"     << setw(Column_Width) << "BubbleSort" 
//          << setw(Column_Width) << "SelectionSort" << setw(Column_Width) << "InsertionSort" 
//          << setw(Column_Width) << "QuickSort"     << setw(Column_Width) << "HeapSort"
//          << setw(Column_Width) << "MergeSort"     << setw(Column_Width) << "RadixSort"
//          << setw(Column_Width) << "CountingSort"  << setw(Column_Width) << "\n\n";
    
//     cout << ("***********************************************************************")
//          << ("*******************************************************************") << "\n\n";




// cout << setw(6) << i        << setw(Column_Width) << bubblecount    
//             << setw(Column_Width)  << selectioncount     << setw(Column_Width) 
//             << insertioncount      << setw(Column_Width) << count_count    
//             << setw(Column_Width)  << radixcount         << setw(Column_Width)
//             << MergeCount          << setw(Column_Width) << HeapCount           
//             << setw(Column_Width)  << quickcount         << setw(Column_Width) <<"\n";
     
//       cout  <<  setw(Column_Width) 
//             << bubble_time         << " Msecs"    << setw(Column_Width-5) 
//             << selection_time      << " Msecs"    << setw(Column_Width-5)     
//             << insertion_time      << " Msecs"    << setw(Column_Width-5) 
//             << count_time          << " Msecs"    << setw(Column_Width-5)
//             << radix_time          << " Msecs"    << setw(Column_Width-5)     
//             << merge_time          << " Msecs"    << setw(Column_Width-5) 
//             << heap_time           << " Msecs"    << setw(Column_Width-5)     
//             << quick_time          << " Msecs"    << setw(Column_Width-5) 
//             << "\n\n\n";

    return 0;
}