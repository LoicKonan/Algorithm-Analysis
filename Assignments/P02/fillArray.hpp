#include <iostream>
using namespace std;

/****************************************
This program will help me fill each array
with random numbers, using the seed 
variable.
*******************************************/
namespace FillArray
{
    // Using this function to fill the array with random numbers.
    void fillArray(int arr[], int seed)
    {
        srand(seed);
        for (int i = 0; i < _SIZE; i++)
            arr[i] = rand() % 100;
    }
}