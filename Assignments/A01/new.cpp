#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int ROWS = 20;
const int COLS = 20;
int visited[ROWS][COLS];                        // 2-D array to store which cell is visited

void open_File(ifstream &in, ofstream &out);
void print_World(string  world[], ofstream &out);
void recursion_Blobs(string world[], int row, int col, int &count);

int main()
{    
    ifstream in;
    ofstream out;
    open_File(in, out);
    string line;
    int i = 0;
    string world[20];                           // World array

    memset(visited, 0, sizeof(visited));        // Initializing visited with 0s

    while (getline(in, line))
    {
        world[i++] = line;                      // Filling the world
    }


    out << "Original world:\n";
    print_World(world,out);                      // Printing world before mutation

    int count = 0;                              // Count of blobs
    recursion_Blobs(world, 0, 0, count);        // Processing blobs

    out << "\n\nWorld with mutated blobs:\n";
    print_World(world,out);                      // Printing world after mutation

    out << count << " blobs were found.";
    return 0;
}


void open_File(ifstream &in, ofstream &out)
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


void recursion_Blobs(string world[], int row, int col, int &count)
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
    recursion_Blobs(world, row + 1, col, count);
    recursion_Blobs(world, row - 1, col, count);
    recursion_Blobs(world, row, col + 1, count);
    recursion_Blobs(world, row, col - 1, count);
}


void print_World(string world[], ofstream &out)
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
