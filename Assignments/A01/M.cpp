#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void openFile(ifstream &in, ofstream &out);

const int ROWS = 20;
const int COLS = 20;


int visited[ROWS][COLS];    

using namespace std;

bool valid(int i, int j)
{
    // Checking if a cell is withing 2-D array
    return (i >= 0 && j >= 0 && i < 20 && j < 20 && !visited[i][j]);
}

void processBlob(string arr[], int i, int j, int &count)
{
    if (!valid(i, j))   // If invalid i and j then return
        return;

    visited[i][j] = 1;  // Making visited true
    if (arr[i][j] == '*')
    {
        count++;    // Blob found
        arr[i][j] = '#';
    }

    // Process neighbouring cells
    processBlob(arr, i + 1, j, count);
    processBlob(arr, i - 1, j, count);
    processBlob(arr, i, j + 1, count);
    processBlob(arr, i, j - 1, count);
}



// Print out the content of the matrix to the console.
void printWorld(char world[ROWS][COLS])
{

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << world[i][j]<< " ";
        }
        cout << '\n';
    }
}



int main()
{
    ifstream in;
    ofstream out;


    openFile(in, out);

    char world[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            in >> world[i][j];
        }
    }


    // Print out the original world  
    cout << "\nOriginal world: \n";
    printWorld(world);

    // Now perform counting the number of blobs from the world
    int numBlobs = countBlobs(world);

    // Print out the updated world
    cout << "\nWorld with mutated blobs: \n";
    printWorld(world);

    cout << '\n'<< numBlobs << " blobs were found.\n";


    in.close();
    out.close();
    return 0;
}


void openFile(ifstream &in, ofstream &out)
{
    string inName;
    string outName;

    cout << "Enter the input file name: ";
    cin >> inName;
    in.open(inName);

    // Print an error message if file fails to open.
    if (in.fail())
    {
        cout << "Could not open file. \n";
        cout << "Check file name and location. \n\n";
    }

    cout << "Enter the output file name:  ";
    cin >> outName;
    out.open(outName);
}
