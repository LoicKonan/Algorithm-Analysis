#include <iostream>
#include <fstream>
#include <string.h>


const int ROWS = 20;
const int COLS = 20;

int visited[ROWS][COLS];    // 2-D array to store which cell is visited

using namespace std;

bool valid(int row, int col)
{
    // Checking if a cell is withing 2-D array
    return (row >= 0 && col >= 0 && row < 20 && col < 20 && !visited[row][col]);
}

void processBlob(string arr[], int row, int col, int &count)
{
    if (!valid(row, col))   // If invalid i and j then return
        return;

    visited[row][col] = 1;  // Making visited true
    if (arr[row][j] == '*')
    {
        count++;    // Blob found
        arr[row][j] = '#';
    }

    // Process neighbouring cells
    processBlob(arr, row + 1, j, count);
    processBlob(arr, row - 1, j, count);
    processBlob(arr, row, col + 1, count);
    processBlob(arr, row, col - 1, count);
}

void printWorld(string arr[])
{
    // Print the world
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{

    string filename;
    cout << "Enter the filename:";  // Take input the file name
    cin >> filename;

    ifstream file;
    file.open(filename);    // Open the file

    if (!file.is_open())
    {
        // File doesn't exist
        cout << "\nFile doesn't exist!";
        exit(1);
    }

    string arr[20]; // World array

    memset(visited, 0, sizeof(visited));    // Initializing visited with 0s

    string line;

    int i = 0;
    while (getline(file, line))
    {
        arr[i++] = line;    // Filling the world
    }

    cout << "Original world:\n";
    printWorld(arr);    // Printing world before mutation

    int count = 0;  // Count of blobs
    processBlob(arr, 0, 0, count);  // Processing blobs

    cout << "World with mutated blobs:\n";
    printWorld(arr);    // Printing world after mutation

    cout << count << " blobs were found.";
    return 0;
}