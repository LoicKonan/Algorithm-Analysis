/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            Recursion Blobs
*    Title:            Program 1
*    Course:           CMPS 5243
*    Semester:         Spring 2022
*    Description:
*
*                      This program use recursion to count the number 
*                      of "blobs" in a 2D array. A text file containing 
*                      a 2-D matrix of 0's and *'s is given. 
*                      A blob is connected group of *'s.  
*                      The *'s are connected if they are von Neumann neighbors 
*                      (top, bottom, left or right)
*                      This program uses 4 fuctions:
*
*                      1 - Main function: is the driver program.
*                      2 - open_File function: will prompt the user for information.
*                      3 - print_world: will print the original and mutated array.
*                      4 - recursion_blobs: will recursively replace all *  
*                          of the *'s in the blob with #'s
*                      5 - header: will Display the heading and explanation of"; 
*                          the program to the output file.";
*
*    Files:
*         main.cpp
*         outfile
*         infile 
*
*    Usage:
*           main.cpp          : driver program
*
*
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int ROWS = 20;                            // Number of ROWS.
const int COLS = 20;                            // Number of COLS.
int visited[ROWS][COLS];                        // 2-D array to store which cell is visited


// Function prototype to Prompt the user for the files names.
void open_File(ifstream &in, ofstream &outfile);

// Function prototype to print the our 2-D array on the output file.
void print_World(string world[], ofstream &outfile);

// Function prototype to recursively replace all *  of the *'s in the blob with #'s.
void recursion_Blobs(string world[], int row, int col, int &numb_Blobs);

// Function prototype to display the heading and explanation of the program.
void header(ofstream &outfile);


int main()
{    
    ifstream infile;
    ofstream outfile;
    open_File(infile, outfile);
    
    // This function Display the heading and explanation of the program to the output file.
    header(outfile);


    // Variables declarations.
    string char_Array[100];                 // Declare and initialize our array.              
    string line;                            // Will be use to fill in our array.
    int i = 0;                              // Variable to use in the while loop below.
    int numb_Blobs = 0;                     // Initialize the number of blobs to 0.       


    // This will copies 0 and Initialize our array call visited with 0s.
    memset(visited, 0, sizeof(visited));        
    
    // Using this while loop to fill our array.
    while (getline(infile, line))
    {
        char_Array[i++] = line;                        
    }

    
    // Display the world before mutated blobs.
    outfile << "Original world:\n";
    print_World(char_Array,outfile);                   

    // Calling our recursive function numb_Blobs
    recursion_Blobs(char_Array, 0, 0, numb_Blobs);         

    // Display the mutated world to the output file.
    outfile << "\n\nWorld with mutated numb_Blobs:\n";
    print_World(char_Array,outfile);                 

    // Print the number of blobs found.
    outfile << numb_Blobs << " Blobs were found.";

    return 0;
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
 *  Function Name: recursion_Blobs
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
void recursion_Blobs(string world[], int row, int col, int &numb_Blobs)
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
    recursion_Blobs(world, row + 1, col, numb_Blobs);
    recursion_Blobs(world, row - 1, col, numb_Blobs);
    recursion_Blobs(world, row, col + 1, numb_Blobs);
    recursion_Blobs(world, row, col - 1, numb_Blobs);
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
 *  Function Name: header
 * 
 *  Parameters: ofstream& outfile.	
 * 
 *  Purpose: To display the heading and explanation of program to the output file.
 * 						
 * 	Returns: Void.	
 * 					 
 */
void header(ofstream &outfile)
{
    outfile << "*****************************************************************************\n";
    outfile << "*";
    outfile << "\n*    Author:           Loic Konan";
    outfile << "\n*    Email:            loickonan.lk@gmail.com";
    outfile << "\n*    Label:            Recursion Blobs";
    outfile << "\n*    Title:            Program 1";
    outfile << "\n*    Course:           CMPS 5243";
    outfile << "\n*    Semester:         Spring 2022";
    outfile << "\n*    Description:";
    outfile << "\n*";
    outfile << "\n*                  This program use recursion to count the number";
    outfile << "\n*                  of blobs in a 2D array. A text file containing"; 
    outfile << "\n*                  a 2-D matrix of 0's and *'s is given.";
    outfile << "\n*                  A blob is connected group of *'s.";
    outfile << "\n*                  The *'s are connected if they are von Neumann neighbors";
    outfile << "\n*                  (top, bottom, left or right)";
    outfile << "\n*                  This program uses 4 fuctions:";
    outfile << "\n*";
    outfile << "\n*                   1 - Main: which is the driver program.";
    outfile << "\n*                   2 - open_File: will prompt the user for information.";
    outfile << "\n*                   3 - print_world: will print the original and mutated array.";
    outfile << "\n*                   4 - recursion_blobs: will recursively replace all *"; 
    outfile << "\n*                       of the *'s in the blob with #'s";
    outfile << "\n*                   5 - header: will Display the heading and explanation of"; 
    outfile << "\n*                       the program to the output file.";
    outfile << "\n*";
    outfile << "\n*    Files:"; 
    outfile << "\n*         main.cpp";
    outfile << "\n*         outfile";
    outfile << "\n*         infile";
    outfile << "\n*";
    outfile << "\n*    Usage:";
    outfile << "\n*           main.cpp          : driver program";
    outfile << "\n*";
    outfile << "\n*";
    outfile << "\n******************************************************************************\n\n";
}

