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
    ifstream infile;
    ofstream outfile;


    openFileRead(infile);
    openFileWrite(outfile);

    char world[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            infile >> world[i][j];
        }
    }


    // Print out the original world  
    outfile << '\n';
    outfile << "Original world: \n";
    printWorld(world);

    // Now perform counting the number of blobs from the world
    int numBlobs = countBlobs(world);

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