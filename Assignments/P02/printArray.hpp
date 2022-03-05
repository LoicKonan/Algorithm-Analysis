/*******************************************************************
copyright: Tina Johnson CMPS 5243

This program print the arrays to te console

*******************************************************************/

#include <iostream>

namespace print
{
    // Function to print.
    void printArray(int arr[])
    {
        for (int i = 0; i < _SIZE; i++)
            cout << setw(4) << arr[i];
        cout << "\n\n";
    }
}