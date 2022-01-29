#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int ROWS = 20;
const int COLS = 20;
int visited[ROWS][COLS];                        // 2-D array to store which cell is visited


void open_File(ifstream &in, ofstream &outfile);
void print_World(string world[], ofstream &outfile);
void recursion_numb_Blobs(string world[], int row, int col, int &numb_Blobs);


int main()
{    
    ifstream infile;
    ofstream outfile;
    open_File(infile, outfile);
    string char_Array[100];


    memset(visited, 0, sizeof(visited));        // Initializing visited with 0s
    string line;
    int i = 0;
    while (getline(infile, line))
    {
        char_Array[i++] = line;                        // Filling the world
    }


    outfile << "Original world:\n";
    print_World(char_Array,outfile);                   // Printing world before mutation

    int numb_Blobs = 0;                             // numb_Blobs of numb_Blobs
    recursion_numb_Blobs(char_Array, 0, 0, numb_Blobs);         // Processing numb_Blobs

    outfile << "\n\nWorld with mutated numb_Blobs:\n";
    print_World(char_Array,outfile);                  // Printing world after mutation

    outfile << numb_Blobs << " numb_Blobs were found.";
    return 0;
}


void open_File(ifstream &in, ofstream &outfile)
{
    string inName;
    string outfileName;

    cout << "Enter the input file name: ";
    cin >> inName;
    in.open(inName);

    // Print an error message if file fails to open.
    if (in.fail())
    {
        cout << "Could not open file. \n";
        cout << "Check file name and location. \n\n";
    }
    
    cout << "Enter the outfileput file name:  ";
    cin >> outfileName;
    outfile.open(outfileName);
}


void print_World(string world[], ofstream &outfile)
{
    // Print the world
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            outfile << world[i][j] << " ";
        }
        outfile << "\n";
    }
}

void recursion_numb_Blobs(string world[], int row, int col, int &numb_Blobs)
{
    // If invalid row and col then return
    if (!(row >= 0 && col >= 0 && row < ROWS && col < COLS && !visited[row][col]))   
        return;
    
    visited[row][col] = 1;
    if (world[row][col] == '*')
    {
        numb_Blobs++;                        // Blob found
        world[row][col] = '#';
    }

    // Process neighbouring cells
    recursion_numb_Blobs(world, row + 1, col, numb_Blobs);
    recursion_numb_Blobs(world, row - 1, col, numb_Blobs);
    recursion_numb_Blobs(world, row, col + 1, numb_Blobs);
    recursion_numb_Blobs(world, row, col - 1, numb_Blobs);
}
