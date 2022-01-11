#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void openFileRead(ifstream &in);
void openFileWrite(ofstream &out);

const int ROWS = 22;
const int COLS = 22;

// Print out the content of the matrix to the console.
void printWorld(char world[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout<<world[i][j]<< " ";
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
}


int main()
{
    ifstream infile;
    ofstream outfile;


    openFileRead(infile);
    openFileWrite(outfile);

    // Other function calls go here.
    // Pass file stream variables as needed.

    infile.close();
    outfile.close();
    return 0;
}


void openFileRead(ifstream &in)
{
    string inFileName;
    cout << "Enter the input file name: ";
    cin >> inFileName;
    in.open(inFileName);

    // Print an error message if file fails to open.
    if (in.fail())
    {
        cout << "Could not open file. \n";
        cout << "Check file name and location. \n\n";
    }
}

void openFileWrite(ofstream &out)
{
    string outFileName;
    cout << "Enter the output file name:  ";
    cin >> outFileName;
    out.open(outFileName);
}