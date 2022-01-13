#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openFile(ifstream &in, ofstream &out);

const int ROWS = 20;
const int COLS = 20;

// Print out the content of the matrix to the console.
void printWorld(char world[ROWS][COLS], ofstream &out)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            out << world[i][j]<< " ";
        }
        out << '\n';
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
    {
       world[currentRow][currentCol] = '#';
    }

    // mutateBlob(world, currentRow + 1, currentCol);
    // mutateBlob(world, currentRow - 1, currentCol);

    // mutateBlob(world, currentRow, currentCol + 1);
    // mutateBlob(world, currentRow, currentCol - 1);

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
                mutateBlob(world, i, j);
            }
        }
    }
    return numBlobs;
}



int main()
{
    ifstream in;
    ofstream out;

    openFile(in,out);


    char world[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            in >> world[i][j];
        }
    }


    // Print out the original world  
    out << "\nOriginal world: \n";
    printWorld(world, out);

    // Now perform counting the number of blobs from the world
    int numBlobs = countBlobs(world);

    // Print out the updated world
    out << "\nWorld with mutated blobs: \n";
    printWorld(world,out);

    out << '\n'<< numBlobs << " blobs were found.\n";


    in.close();
    out.close();
    return 0;
}

void openFile(ifstream &in, ofstream &out)
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
    
    string outName;
    cout << "Enter the output file name:  ";
    cin >> outName;
    out.open(outName);
}
