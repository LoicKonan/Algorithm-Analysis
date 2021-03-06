/*
    Name:       Byron Dowling and Loic Konan
    Course:     5243 Algorithm Analysis
    Date:       4/22/2022

    Assignment: Balanced vs Non-Balanced Trees Experiment

        Working alone or in a group no larger than 3 students, compare the efficiency of a regular, non-balanced
        binary search tree to a balanced binary search tree (AVL, RB, or some other balanced tree).

        - Datasets: Insert each number generated into two trees – a regular BST & a Balanced BST. The size of 
          the dataset, n, is your choice. Suggestion: Start with a small size (Ex. n = 10) and increase once you
          are confident your code is producing accurate results. Bigger datasets will likely produce a greater
          disparity between the two trees. Dataset variations should include:

                - Insert random values within a specified range of your choice with no restrictions on the order of the 
                  data is inserted.

                - Insert a root value that is the median of a specified range and then follow with random numbers
                  within that range. Ex. Insert 5,000 as the root value if numbers range from 1-10,000.

                - Insert a root value that is closer to one of a specified range and then follow with random numbers 
                  within that range. Ex. Insert 2,500 as the root value if numbers range from 1-10,000.

        - After the trees are created with identical datasets, implement code that will:

                - Compare the height of the unbalanced trees to the balanced trees.

                - Compare the number of steps for insertion of random numbers. Use a counter and document 
                  where you increment the counter. This should be addressed in your report.

                - Compare the number of steps required for searching random numbers. Use a counter for this as with 
                  the previous program.

        - After you have compared the two types of trees with each of the three datasets, loop for multiple runs 
          so that results can be averaged. Remember to document the number of runs in your report.

        - If time allows and you are feeling industrious, include an outer loop that will vary the dataset size, 
          n. This is not required but might produce interesting results.
*/


#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "RedBlackTree.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace std::chrono;

typedef vector<float> Vfloat;       // typedef for a float vector
typedef vector<int> Vint;           // typedef for an int vector
typedef vector<string> Vstring;     // typedef for a string vector



/*
     $$$$$$$$\                                                                                        
     \__$$  __|                                                                                       
        $$ | $$$$$$\   $$$$$$\   $$$$$$\                                                              
        $$ |$$  __$$\ $$  __$$\ $$  __$$\                                                             
        $$ |$$ |  \__|$$$$$$$$ |$$$$$$$$ |                                                            
        $$ |$$ |      $$   ____|$$   ____|                                                            
        $$ |$$ |      \$$$$$$$\ \$$$$$$$\                                                             
        \__|\__|       \_______| \_______|                                                            
                                                                                                                                                                                          
                                                                                                    
    $$$$$$$$\                                         $$\                                    $$\     
    $$  _____|                                        \__|                                   $$ |    
    $$ |      $$\   $$\  $$$$$$\   $$$$$$\   $$$$$$\  $$\ $$$$$$\$$$$\   $$$$$$\  $$$$$$$\ $$$$$$\   
    $$$$$\    \$$\ $$  |$$  __$$\ $$  __$$\ $$  __$$\ $$ |$$  _$$  _$$\ $$  __$$\ $$  __$$\\_$$  _|  
    $$  __|    \$$$$  / $$ /  $$ |$$$$$$$$ |$$ |  \__|$$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  $$ | $$ |    
    $$ |       $$  $$<  $$ |  $$ |$$   ____|$$ |      $$ |$$ | $$ | $$ |$$   ____|$$ |  $$ | $$ |$$\ 
    $$$$$$$$\ $$  /\$$\ $$$$$$$  |\$$$$$$$\ $$ |      $$ |$$ | $$ | $$ |\$$$$$$$\ $$ |  $$ | \$$$$  |
    \________|\__/  \__|$$  ____/  \_______|\__|      \__|\__| \__| \__| \_______|\__|  \__|  \____/ 
                        $$ |                                                                         
                        $$ |                                                                         
                        \__|                                                                         

        
    Description:

		This class is responsible for instantiating an instance of the tree experiment. When an object
        of this class is created, it will initialize an integer vector with random numbers and load them
        in both a Binary Search Tree and a Red Black Tree and log certain statistics such as the number 
        of comparisons per insertion, the height of the tree, and the time it takes to build the tree.

        This class shares many similarities between my previous submission for the sorting experiment.

	Public Methods:

		- TreeExperiment() - Default Constructor
		- TreeExperiment(int S) - Overloaded Constructer
		- vector<float> getTimes() - Returns a vector of run times
        - vector<int> getComps() - Returns a vector of computations
        - void loadData() - Initializes the vector of numbers to be sorted with random numbers
        - void loadData(string) - Initializes the vector of numbers to be sorted with numbers from an input file
		- void runExperiment() - Method that runs the search test
        - void runExperiment(int, int) - Method that runs the main experiment

	Usage:

		- This class creates an object that will run an instance of the Tree experiment  

*/

class TreeExperiment
{
    protected:

        Vint data;
        int size;
        int computations;
        Vstring Trees;
        Vstring Files;
        Vfloat treeTimes;
        Vint comps;

    public:

        TreeExperiment()
        {
            Trees = {"Binary Search Tree", "Red Black Tree"};                   // Tree Structures
            Files = {"randomnums1.txt", "randomnums2.txt", "randomnums3.txt"};  // Datasets for testing
            size = 20;
            computations = 0;
        }


        TreeExperiment(int S)
        {
            Trees = {"Binary Search Tree", "Red Black Tree"};                   // Tree structures
            Files = {"randomnums1.txt", "randomnums2.txt", "randomnums3.txt"};  // Datasets for testing
            size = S;
            computations = 0;
        }


        Vfloat getTimes()
        {
            return treeTimes;
        }


        Vint getComps()
        {
            return comps;
        }


        void loadData()
        {
            for (int i = 0; i < size; i++)
            {
                int x = rand();
                x = x % 10000;
                data.push_back(x);
            }
        }


        void loadData(string fileName)
        {
            ifstream infile;
            infile.open(fileName);

            while(!infile.eof())
            {
                int x;
                infile >> x;
                data.push_back(x);
            }
        }


        void runExperiment()
        {
            BinarySearchTree BST;
            RedBlackTree RBT;

            for (int i = 0; i < size; i++)
            {
                BST.insert(data[i]);
                RBT.insert(data[i]);
            }

            int selection = -1;

            while (selection != 0)
            {
                cout << "Please enter a number to search for in both trees.\n";
                cout << "If you would like to stop enter 0\n";
                cin >> selection;

                if (selection == 0)
                {
                    break;
                }

                else
                {
                    cout << "Searching for " << selection << "..." << endl;
                    RBT.Find(selection);
                    BST.Find(selection);

                    cout << "The number of steps for searching in the Red Black Tree is: ";
                    cout << searching_Steps_RB << endl;
                    cout << "The number of steps for searching in the Binary Search Tree is: ";
                    cout << searching_Steps_BST << endl << endl;

                    searching_Steps_BST = searching_Steps_RB = 0;
                }
            }
        }


        void runExperiment(int ds, int count)
        {
            for (int j = 0; j < Trees.size(); j++)
            {
                cout << "Loading Dataset #" << ds << " into " << Trees[j] << " #" << count << "..." << endl;

                auto start = high_resolution_clock::now();

                if (Trees[j] == "Binary Search Tree")
                {
                    BinarySearchTree BST;

                    for (int k = 0; k < data.size(); k++)
                    {
                        insertion_Steps_BST = 0;
                        BST.insert(data[k]);
                        computations += insertion_Steps_BST;
                    }

                    cout << "\nHeight of Tree is: " << BST.Cal_Height() << endl;
                } 
                
                else if (Trees[j] == "Red Black Tree") 
                {
                    RedBlackTree RBT;

                    for (int k = 0; k < data.size(); k++)
                    {
                        insertion_Steps_RB = 0;
                        RBT.insert(data[k]);
                        computations += insertion_Steps_RB;
                    }

                    cout << "\nHeight of Tree is: " << RBT.Cal_Height() << endl;
                } 

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast< microseconds >(stop - start);

                if (Trees[j] == "Binary Search Tree")
                {
                    computations /= data.size();
                    insertion_Steps_BST = 0;
                }

                else if (Trees[j] == "Red Black Tree")
                {
                    computations /= data.size();
                    insertion_Steps_RB = 0;
                }

                treeTimes.push_back(duration.count());
                comps.push_back(computations);

                cout << "Data was loaded into Tree in: " << duration.count() << " microSeconds."<< endl;
                cout << "Average Number of Comparisons for Insertion: " << computations << endl << endl << endl;

                computations = 0;
            }
        }
};



/*
 
    $$$$$$$$\                                                                                        
    \__$$  __|                                                                                       
        $$ | $$$$$$\   $$$$$$\   $$$$$$\                                                              
        $$ |$$  __$$\ $$  __$$\ $$  __$$\                                                             
        $$ |$$ |  \__|$$$$$$$$ |$$$$$$$$ |                                                            
        $$ |$$ |      $$   ____|$$   ____|                                                            
        $$ |$$ |      \$$$$$$$\ \$$$$$$$\                                                             
        \__|\__|       \_______| \_______|                                                            
                                                                                                                                                                                        
                                                                                                    
    $$$$$$$$\                                         $$\                                    $$\     
    $$  _____|                                        \__|                                   $$ |    
    $$ |      $$\   $$\  $$$$$$\   $$$$$$\   $$$$$$\  $$\ $$$$$$\$$$$\   $$$$$$\  $$$$$$$\ $$$$$$\   
    $$$$$\    \$$\ $$  |$$  __$$\ $$  __$$\ $$  __$$\ $$ |$$  _$$  _$$\ $$  __$$\ $$  __$$\\_$$  _|  
    $$  __|    \$$$$  / $$ /  $$ |$$$$$$$$ |$$ |  \__|$$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  $$ | $$ |    
    $$ |       $$  $$<  $$ |  $$ |$$   ____|$$ |      $$ |$$ | $$ | $$ |$$   ____|$$ |  $$ | $$ |$$\ 
    $$$$$$$$\ $$  /\$$\ $$$$$$$  |\$$$$$$$\ $$ |      $$ |$$ | $$ | $$ |\$$$$$$$\ $$ |  $$ | \$$$$  |
    \________|\__/  \__|$$  ____/  \_______|\__|      \__|\__| \__| \__| \_______|\__|  \__|  \____/ 
                        $$ |                                                                         
                        $$ |                                                                         
                        \__|                                                                         
     $$$$$$\                       $$\                         $$\ $$\                               
    $$  __$$\                      $$ |                        $$ |$$ |                              
    $$ /  \__| $$$$$$\  $$$$$$$\ $$$$$$\    $$$$$$\   $$$$$$\  $$ |$$ | $$$$$$\   $$$$$$\            
    $$ |      $$  __$$\ $$  __$$\\_$$  _|  $$  __$$\ $$  __$$\ $$ |$$ |$$  __$$\ $$  __$$\           
    $$ |      $$ /  $$ |$$ |  $$ | $$ |    $$ |  \__|$$ /  $$ |$$ |$$ |$$$$$$$$ |$$ |  \__|          
    $$ |  $$\ $$ |  $$ |$$ |  $$ | $$ |$$\ $$ |      $$ |  $$ |$$ |$$ |$$   ____|$$ |                
    \$$$$$$  |\$$$$$$  |$$ |  $$ | \$$$$  |$$ |      \$$$$$$  |$$ |$$ |\$$$$$$$\ $$ |                
     \______/  \______/ \__|  \__|  \____/ \__|       \______/ \__|\__| \_______|\__|                
                                                                                                    


        Description:

            This class is the main driver of the program. The class will either take a default int
            or have an integer passed in at object declaration that will serve as how many "runs"
            we will conduct on the Tree Experiment. This will then start a loop up to this number
            and at each iteration, a new TreeExperiment object is created to conduct an instance of the
            experiment. Once that object's experiment is complete, the results are written, then the
            object is destroyed and a new one is created when the loop increments.

            In order to get easier access to some of the data that is calaculated in the other class,
            these classes make use of the friend operator that allows them to have access to and call
            their public methods. 

            Once the runs are complete, the results are printed


        Public Methods:

            - TreeExperimentController() - Default Constructor
            - TreeExperimentController(int num) - Overloaded Constructer
            - void startExperiment() - Starts the process of running the experiment multiple times
            - void searchCompare() - responsible for comparing the searching of numbers between trees


        Usage:

            - This class creates an object that will coordinate running the sort experiment several times                                                                                 
                                                                                                  
*/

class TreeExperimentController
{
    protected:

        int runs;
        vector<Vfloat> averages;
        vector<Vint> comps;
        vector<float> results;
        vector<int> Avg_Comps;
        ofstream outfile;
        Vstring Files;

    public:

        friend class TreeExperiment;

        TreeExperimentController()
        {
            runs = 10;
            outfile.open("tree_experiment_results.txt");
            Files = {"randomnums1.txt", "randomnums2.txt", "randomnums3.txt"};
        }

        TreeExperimentController(int size)
        {
            runs = size;
            outfile.open("tree_experiment_results.txt");
            Files = {"randomnums1.txt", "randomnums2.txt", "randomnums3.txt"};
        }



        void startExperiment(int runs)
        {
            for (int j = 0; j < Files.size(); j++)
            {
                for (int i = 0; i < runs; i++)
                {
                    TreeExperiment* Temp = new TreeExperiment();
                    Temp->loadData(Files[j]);
                    Temp->runExperiment(j+1, i+1);
                    averages.push_back(Temp->getTimes());
                    comps.push_back(Temp->getComps());
                    delete Temp;
                }
            }
        }
        
        void searchCompare()
        {
            int s;

            cout << "\nPlease enter a dataset size for the Tree search comparison...\n";
            cin >> s;

            TreeExperiment* Temp = new TreeExperiment(s);
            Temp->loadData();
            Temp->runExperiment();
            
        }
};

int main()
{
    /*
        Below is all that is needed to run the experiment.

        We pass in 10 for 10 runs per dataset on each tree.
    */

    TreeExperimentController T1000;
    T1000.startExperiment(10);
    T1000.searchCompare();
}