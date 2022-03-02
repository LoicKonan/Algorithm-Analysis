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


// Driver code
int main() 
{
    sortCompare SC;

    for (int i = 0; i < SC.sortNames.size(); i++) {
        SC.callSortMethod(SC.sortNames[i]);
    }

    cout << SC.sortNames[0] << endl;

    return 0;
}