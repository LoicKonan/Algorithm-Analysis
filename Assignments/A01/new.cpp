#include <iostream>
#include <fstream>
#include <string.h>

int visited[20][20];    // 2-D array to store which cell is visited

using namespace std;

bool valid(int i, int j)
{
    // Checking if a cell is withing 2-D array
    return (i >= 0 && j >= 0 && i < 20 && j < 20 && !visited[i][j]);
}

void processBlob(string arr[], int i, int j, int &count)
{
    if (!valid(i, j))   // If invalid i and j then return
        return;

    visited[i][j] = 1;  // Making visited true
    if (arr[i][j] == '*')
    {
        count++;    // Blob found
        arr[i][j] = '#';
    }

    // Process neighbouring cells
    processBlob(arr, i + 1, j, count);
    processBlob(arr, i - 1, j, count);
    processBlob(arr, i, j + 1, count);
    processBlob(arr, i, j - 1, count);
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