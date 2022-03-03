#include <iostream>
using namespace std;

namespace FillArray
{

    void fillArray(int arr[], int seed)
    {
        srand(seed);
        for (int i = 0; i < _SIZE; i++)
            arr[i] = rand() % 100;
    }

}