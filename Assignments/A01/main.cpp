#include <iostream>
#include <fstream>

using namespace std;

void openFileRead(ifstream &in);
void openFileWrite(ofstream &out);


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
