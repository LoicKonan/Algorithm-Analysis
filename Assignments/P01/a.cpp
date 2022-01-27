#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int recursive(int numb)
{
    if(numb < 1)
        return 1;
    else 
        return numb + (recursive(numb/3));

}
int main()
{
    int numb;
    cout << "Enter a number: ";
    cin >> numb;

    cout << recursive(numb);

    return 0;
}