#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int ROWS = 20;
const int COLS = 20;
int visited[ROWS][COLS];    // 2-D array to store which cell is visited


void openFile(ifstream &in, ofstream &out);
void printWorld(string world[], ofstream &out);
void processBlob(string world[], int row, int col, int &count);
bool valid(int row, int col);


int main()
{    
    ifstream in;
    ofstream out;

    openFile(in, out);
    string world[20]; // World array

    memset(visited, 0, sizeof(visited));    // Initializing visited with 0s

    string line;
    int i = 0;

    while (getline(in, line))
    {
        world[i++] = line;    // Filling the world
    }


    out << "Original world:\n";
    printWorld(world,out);    // Printing world before mutation

    int count = 0;  // Count of blobs
    processBlob(world, 0, 0, count);  // Processing blobs

    out << "\n\nWorld with mutated blobs:\n";
    printWorld(world,out);    // Printing world after mutation

    out << count << " blobs were found.";
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


void processBlob(string world[], int row, int col, int &count)
{
    if (!(row >= 0 && col >= 0 && row < 20 && col < 20 && !visited[row][col]))   // If invalid row and col then return
        return;

    visited[row][col] = 1;              // Making visited true
    if (world[row][col] == '*')
    {
        count++;                        // Blob found
        world[row][col] = '#';
    }

    // Process neighbouring cells
    processBlob(world, row + 1, col, count);
    processBlob(world, row - 1, col, count);
    processBlob(world, row, col + 1, count);
    processBlob(world, row, col - 1, count);
}


void printWorld(string world[], ofstream &out)
{
    // Print the world
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            out << world[i][j] << " ";
        }
        out << "\n";
    }
}
