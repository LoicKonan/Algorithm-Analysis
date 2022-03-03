#include <iostream>
using namespace std;

namespace CopyArray
{

// Function to copy an array.
void copyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < _SIZE; i++)
        arr2[i] = arr1[i];
}

}
