#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const int ROWS = 20;
const int COLS = 20;

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


int main()
{
    ifstream in;
    ofstream out;
    openFile(in,out);

    int numBlobs = 0;
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
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(world[i][j] == '*')
            {
                numBlobs++;
            }
            out << world[i][j]<< " ";
        }
        out << '\n';
    }

    // Print out the updated world
    out << "\nWorld with mutated blobs: \n";
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(world[i][j] == '*')
            {
                world[i][j] = '#';
            }
            out << world[i][j]<< " ";
        }
        out << '\n';
    }
    out << '\n'<< numBlobs << " blobs were found.\n";

    in.close();
    out.close();
    return 0;
}
