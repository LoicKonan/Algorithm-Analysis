#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
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

    outfile << numb_Blobs << " Blobs were found.";
    return 0;
}


/**
 *  Function Name: openFiles
 * 
 *  Parameters: ifstream& infile, ofstream& outfile.	
 * 
 *  Purpose:  To prompt the user for the input and output files names.
 * 						
 * 	Returns:  Void.	
 * 					 
 */
void open_File(ifstream &in, ofstream &outfile)
{
    string infile_Name;
    string outfile_Name;

    // Prompt the user input file name.
    cout << "Enter the input file name: ";
    cin >> infile_Name;

    // open input file
    in.open(infile_Name);

    // Print an error message if file fails to open.
    if (in.fail())
    {
        cout << "Could not open file. \n";
        cout << "Check file name and location. \n\n";
    }
    
    // Prompt the user for the output file.
    cout << "Enter the output file name:  ";
    cin >> outfile_Name;

    // open input file
    outfile.open(outfile_Name);
}

/**
 *  Function Name: print_World
 * 
 *  Parameters: string world[], ofstream &outfile	
 * 
 *  Purpose:  Using a nested for loop to print the 20 X 20 world.
 *            - Time complexity  O(N^2)
 * 		
 * 	Returns:  Void.	
 * 					 
 */
void print_World(string world[], ofstream &outfile)
{
    // Printing the world to output file.
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            outfile << world[i][j] << " ";
        }
        outfile << "\n";
    }
}


/**
 *  Function Name: recursion_numb_Blobs
 * 
 *  Parameters: string world[], int row, int col, int &numb_Blobs	
 * 
 *  Purpose: 
 *          - This is the recursive function that will replace all 
 *            of the *'s in the blob with #'s.
 *          - The base case will make sure that we are not out of bounds
 *            and that it is part of the blob. 
 *          - We then convert a blob * to a blob #.
 *          - Also we counting te number of blobs and passing it by reference.
 *            
 * 
 * 	Returns:  Void.	
 * 					 
 */
void recursion_numb_Blobs(string world[], int row, int col, int &numb_Blobs)
{
    // Base case: If invalid row, col and not part of the blob then return
    if (!(row >= 0 && col >= 0 && row < ROWS && col < COLS && !visited[row][col]))   
        return;
    
    // Set all the element in our array to 1. 
    // Then in the main fuction we will use the 'memeset' to set it to zero.
    visited[row][col] = 1;

    // This if statement check to see if we found a blob,
    // by comparing the the row and col of our array to '*',
    // if found we increment the number of blobs then
    // we replace the *'s in the blob with #'s.
    if (world[row][col] == '*')
    {
        numb_Blobs++;                        
        world[row][col] = '#';
    }

    // Using a recursive call to process neighbouring cells.
    recursion_numb_Blobs(world, row + 1, col, numb_Blobs);
    recursion_numb_Blobs(world, row - 1, col, numb_Blobs);
    recursion_numb_Blobs(world, row, col + 1, numb_Blobs);
    recursion_numb_Blobs(world, row, col - 1, numb_Blobs);
}
