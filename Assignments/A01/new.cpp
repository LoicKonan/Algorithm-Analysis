#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void openFile(ifstream &in, ofstream &out);


const int ROWS = 20;
const int COLS = 20;
int visited[ROWS][COLS];    // 2-D array to store which cell is visited


bool valid(int row, int col)
{
    // Checking if a cell is withing 2-D array
    return (row >= 0 && col >= 0 && row < 20 && col < 20 && !visited[row][col]);
}

void processBlob(string world[], int row, int col, int &count)
{
    if (!valid(row, col))   // If invalid i and j then return
        return;

    visited[row][col] = 1;  // Making visited true
    if (world[row][col] == '*')
    {
        count++;    // Blob found
        world[row][col] = '#';
    }

    // Process neighbouring cells
    processBlob(world, row + 1, col, count);
    processBlob(world, row - 1, col, count);
    processBlob(world, row, col + 1, count);
    processBlob(world, row, col - 1, count);
}

void printWorld(string world[])
{
    // Print the world
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << world[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{    
    string filename;
    cout << "Enter the filename:";  // Take input the file name
    cin >> filename;

    ifstream file;
    file.open(filename);    // Open the file

    if (!file.is_open())
    {
        // File doesn't exist
        cout << "\nFile doesn't exist!";
        exit(1);
    }

    string world[20]; // World array

    memset(visited, 0, sizeof(visited));    // Initializing visited with 0s

    string line;

    int i = 0;
    while (getline(file, line))
    {
        world[i++] = line;    // Filling the world
    }

    cout << "Original world:\n";
    printWorld(world);    // Printing world before mutation

    int count = 0;  // Count of blobs
    processBlob(world, 0, 0, count);  // Processing blobs

    cout << "World with mutated blobs:\n";
    printWorld(world);    // Printing world after mutation

    cout << count << " blobs were found.";
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
