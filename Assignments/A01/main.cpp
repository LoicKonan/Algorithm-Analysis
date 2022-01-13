#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void openFileRead(ifstream &in);
void openFileWrite(ofstream &out);

const int ROWS = 20;
const int COLS = 20;

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

// Recursive method that would convert a blob * to a blob #
void mutateBlob( char world[ROWS][COLS], int currentRow, int currentCol)
{
    if(currentRow < 0 || currentRow >= ROWS || 
       currentCol < 0 || currentCol >= COLS || 
       world[currentRow][currentRow] != '*')
    {
        return;
    }
    else
    world[currentRow][currentRow] = '#';


    mutateBlob(world, currentRow + 1, currentCol);
    mutateBlob(world, currentRow, currentCol - 1);
}

// Count the number of blobs 
int countBlobs(char world[ROWS][COLS])
{
    int numBlobs = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(world[i][j] == '*')
            {
                numBlobs++;
                mutateBlob(world, i,j);
            }
        }
    }

    return numBlobs;
}

int main()
{
    ifstream in;
    ofstream out;


    openFileRead(in);
    openFileWrite(out);

    char world[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            in >> world[i][j];
        }
    }


    // Print out the original world  
    cout << '\n';
    cout << "Original world: \n";
    printWorld(world);

    // Now perform counting the number of blobs from the world
    int numBlobs = countBlobs(world);

    // Print out the updated world
    cout << '\n';
    cout << "World with mutated blobs: \n";
    printWorld(world);

    cout << '\n';

    cout << numBlobs << " blobs were found.\n";
    in.close();
    out.close();
    return 0;
}


void openFileRead(ifstream &in)
{
    string inName;
    cout << "Enter the input file name: ";
    cin >> inName;
    in.open(inName);

    // Print an error message if file fails to open.
    if (in.fail())
    {
        cout << "Could not open file. \n";
        cout << "Check file name and location. \n\n";
    }
}

void openFileWrite(ofstream &out)
{
    string outName;
    cout << "Enter the output file name:  ";
    cin >> outName;
    out.open(outName);
}