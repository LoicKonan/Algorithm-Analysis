//Double linked list for student names
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

//create node with double pointers and student name
struct node
{
   string name;
   node  *prev;
   node  *next;
}*header = NULL, *tail = NULL; //declare global names header and tail

//function adds name to double linked list
void addName(string name)
{
   //code here
   if(header == NULL) //when empty header
   {
       header  = new node;//allocate new node
       header -> name = name;//store name to list
       header -> next = header -> prev = NULL;//set prev and next to null
       tail    = header;//header is also referred by tail
   }
   else if(name < header -> name) //when smaller new name
   {
       header -> prev           = new node;//allocate new node before header
       header -> prev->name     = name;//store name
       header -> prev->next     = header;//connect prev of header to header
                    header      = header->prev;//new header is new node(prev of header)
       header -> prev           = NULL;//again set prev of header is NULL
   }
   else if(name > tail->name) //when greater new name than tail
   {
       tail -> next         = new node;//allocate new node after tail
       tail -> next -> name = name;//store name
       tail -> next -> prev = tail;//connect next of tail to tail
                tail        = tail->next;//new tail is going to tail now
       tail -> next         = NULL;//again set tail next is null
   }
   else //some where in middle
   {
       node *temp = header;//temp for traversing
       while(temp -> name < name) //traverse upto list name is less than new name
       {
           temp = temp -> next;
       }
       //when temp name greater than name loop is stopped
       node *nn = new node; //allocate new node nn
       nn   ->  name = name;//store name
       temp ->  prev -> next =  nn;//connect nn is before temp
       nn   ->  prev = temp  -> prev;
       nn   ->  next = temp;
       temp ->  prev = nn;
   }
      
}

string convertLower(string st)
{
   string nst = " ";//new string
   for(unsigned int i = 0; i < strlen(st.c_str()); i++) //repeat string
       if(st[i] >= 65 && st[i] <= 90) //when upper case found
           nst +=tolower(st[i]);//convert lower and add to new string
          
   return nst;//return new string
}

//function deletes name for double linked list
void deleteName(string name)
{
   //code here
   node *temp = header;//start from header
   if(convertLower(header->name) == convertLower(name)) //when found at head
   {
       header = header -> next;//move header to next
       header -> prev  = NULL;//prev is null
       delete temp; //delete it
   }
   else if(convertLower(tail -> name) == convertLower(name)) //when found at tail
   {
       temp  = tail;//refer temp to tail
       tail  = tail -> prev;//move tail to previous
       tail -> next = NULL;//connect back null to end
       delete temp;//delete it
   }
   else //other than tail and head, may be at middle
   {
       while(temp != NULL && convertLower(temp -> name) != convertLower(name)) //repeat until it is found or null is reached
           temp = temp -> next;//move t o next

       if(temp != NULL) //when found
       {
           temp -> next -> prev = temp -> prev;
           temp -> prev -> next = temp -> next;
           delete temp;//now alone temp is remove
       }
   }
}



/*
 * Function: printMenu
 *
 * Description: Prints a menu to the user and asks for letter
 * choices based on the menu.
 *
 * Return: A single Character from the user;
 */
char printMenu() {
	char input;

	printf("*** Menu ***\n");
	printf("A: Add Record\n");
	printf("P: Print Records\n");
	printf("F: Find Record\n");
	printf("E: Edit Record\n");
	printf("D: Delete Record\n");
	printf("Q: Quit\n");
	printf("\nEnter Choice: ");
	input = getchar(); //get character input
	getchar(); //flush the newline/carrage return

	return input;
}



int main()
{
   ifstream infile("input.txt");//open file for reading
   string line, name = "";
  
   //infile >> line;//reading first line or word

   if (infile.is_open())
{
	string line;
	while (getline(infile, line))
    {
    	// note that the newline character is not included
        // in the getline() function

         if(line == "delete") //when command delete is found
       {
           infile >> name;//read name to delete
           deleteName(name);//call delete function
       }
       else
       {
           addName(line);//add function with line as argument
       }
    }
}


   infile.close();//close the file
  
   //print order in ascending
   node *temp = header;

   while(temp != NULL)//traverse forward
   {
       cout    << temp -> name << endl;
       temp    = temp  -> next;
   }
   
   return 0;
}

