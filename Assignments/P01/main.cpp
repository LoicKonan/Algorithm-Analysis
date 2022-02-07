/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            Recursion Blobs
*    Title:            Program 1
*    Course:           CMPS 5243, Spring 2022, Dr. Johnson 
*    Semester:         Spring 2022
*    Description:
*
*                      This program use recursion to count the number 
*                      of "blobs" in a 2D array. A text file containing 
*                      a 2D matrix of 0's and *'s is given. 
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
#include <algorithm>
using namespace std;

// Constant size for the environment of the blobs.
const int ROWS = 20;                            // Number of ROWS.
const int COLS = 20;                            // Number of COLUMNS.


// Function prototype to display the heading and explanation of the program.
void header(ofstream &outfile);

// Function prototype to Prompt the user for the files names.
void open_File(ifstream &in, ofstream &outfile);

// Print out the content of the world to the console.
void print_World(char world[ROWS][COLS], ofstream &outfile);

// A recursive method that would convert a blob * to a blob #
void mutate_Blob(char world[ROWS][COLS],int row, int col);

// Count the number of blobs
int count_Blobs(char world[ROWS][COLS]);

/**
 * 
 * Main Function. 
 * 
 */
int main()
{
  ifstream infile;
  ofstream outfile;
  open_File(infile, outfile);
  
  // This function Display the heading and explanation of the program to the output file.
  header(outfile);

  char world[ROWS][COLS];

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      infile >> world[i][j];
    }
  }

  // Display the world before mutated blobs.
  outfile << "Original world:\n";
  print_World(world, outfile); 

  int numBlobs = count_Blobs(world);

  outfile << endl << endl;

  // Mutated world
  outfile << "Mutated world:\n";
  print_World(world, outfile);
  // Count the number of blobs
  outfile << "Number of blobs: " << numBlobs << endl;

  infile.close();
  outfile.close();
  return 0;
}


/**
 *  Function Name: print_World
 * 
 *  Parameters: char world[][], ofstream &outfile	
 * 
 *  Purpose:  Using a nested for loop to print the 20 X 20 world.
 *            - Time complexity  O(N^2)
 * 		
 * 	Returns:  Void.	
 * 					 
 */
void print_World(char world[ROWS][COLS], ofstream &outfile)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            outfile << world[i][j];
        }
        outfile << endl;
    }
}


/**
 *  Function Name: mutate_Blob
 * 
 *  Parameters: char world[][], int row, int col	
 * 
 *  Purpose: 
 *          - This is the recursive function that will replace all 
 *            of the *'s in the blob with #'s.
 *          - The base case will make sure that we are not out of bounds
 *            and that it is part of the blob. 
 *          - We then convert a blob * to a blob #.
 *          - Also we counting the number of blobs and passing it by reference.
 *            
 * 
 * 	Returns:  Void.	
 * 					 
 */
void mutate_Blob(char world[ROWS][COLS],int row, int col)
{
    // If the blob is out of bounds, return.
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        return;
    }
    // If the blob is not a *, return.
    if (world[row][col] != '*')
    {
        return;
    }
    // If the blob is a *, convert it to a #.
    if (world[row][col] == '*')
    {
        world[row][col] = '#';
    }
    // Recursively call mutate_Blob on the blob's neighbors.
    mutate_Blob(world, row - 1, col);
    mutate_Blob(world, row + 1, col);
    mutate_Blob(world, row, col - 1);
    mutate_Blob(world, row, col + 1);
}

/**
 *  Function Name: count_Blobs
 * 
 *  Parameters: char world[][], ofstream &outfile	
 * 
 *  Purpose:  Using a nested for loop to print the 20 X 20 world.
 *            - Time complexity  O(N^2)
 * 		
 * 	Returns:  Void.	
 * 					 
 */
int count_Blobs(char world[ROWS][COLS])
{
  int count = 0;
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (world[i][j] == '*')
      {
        count++;
        mutate_Blob(world, i, j);
      }
    }
  }
  return count;
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
    outfile << "\n*    Course:           CMPS 5243,  Spring 2022, Dr. Johnson";
    outfile << "\n*    Semester:         Spring 2022";
    outfile << "\n*    Description:";
    outfile << "\n*";
    outfile << "\n*                  This program use recursion to count the number";
    outfile << "\n*                  of blobs in a 2D array. A text file containing"; 
    outfile << "\n*                  a 2D matrix of 0's and *'s is given.";
    outfile << "\n*                  A blob is connected group of *'s.";
    outfile << "\n*                  The *'s are connected if they are von Neumann neighbors";
    outfile << "\n*                  (top, bottom, left or right)";
    outfile << "\n*                  This program uses 4 fuctions:";
    outfile << "\n*";
    outfile << "\n*                  1 - Main: which is the driver program.";
    outfile << "\n*                  2 - open_File: will prompt the user for information.";
    outfile << "\n*                  3 - print_world: will print the original and mutated array.";
    outfile << "\n*                  4 - recursion_blobs: will recursively replace all *"; 
    outfile << "\n*                      of the *'s in the blob with #'s";
    outfile << "\n*                  5 - header: will Display the heading and explanation of"; 
    outfile << "\n*                      the program to the output file.";
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