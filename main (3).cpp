/*
*
* Ian Angel
*
* Chapter 18, Programming Assignment
*
* April 2023
*
*/

#include <iostream>
#include <iomanip>
#include "Necklace.h"
using namespace std;

void menu(); //Function that outputs the header and lists the options to the user

void appendNode(Necklace&, string[]); // Function to append the bead

void insertNode(Necklace&, string[]); // Function to insert the bead

void deleteNode(Necklace&); // Function to delete the bead

void printNode(Necklace&); // Function to print the current beads

void searchNode(Necklace&, string[]); //Function to search for the bead

void exitProgram(); //Function to exit the program


int main() 
{
  
  Necklace Beads;
  string beads[numBeads] = { "turquoise", "coral", "gold", "copper" };
  int option;
  
  while (option != 6)
    {
      menu();
        cin >> option; //User option input
        
	    switch(option) //Switch statement to create a menu loop
        {
	       case 1:
	        appendNode(Beads, beads);
	        break;
	        
	       case 2:
	         insertNode(Beads, beads);
	         break;
	         
           case 3:
	         deleteNode(Beads);
	         break;
	         
           case 4:
	         printNode(Beads);
	         break;
	         
           case 5:
	         searchNode(Beads, beads);
	         break;
	         
	       case 6:
	         void exitProgram();
	         
	       default:
	         cout << "\nThe menu option must be either 1, 2, 3, 4, 5, or 6. Please enter one of the given options.\n";
	         break;

	    }

    }
  
}


void menu()
{
  cout << "\n**MENU**\n" << "1. Append\n" << "2. Insert\n" << "3. Delete\n" << "4. Print\n"<< "5. Search\n" << "6. Exit\n";

  cout << "\nPlease choose a menu option: ";
}


void appendNode(Necklace &Beads,string beads[])
{
  bool var = false;
  string beadMaterial;

  while (!var) 
  {
   cout << "\nChoose one of the following bead material options: turquoise, coral, gold, copper: ";
   cin >> beadMaterial;
   cin.ignore();

   for (int i = 0; i < numBeads; i++) 
   {
    if (beads[i] == beadMaterial) 
    {
      var = true;
      break;
    }
   }

   if (!var)
   {
    cout << "\nInvalid bead material option. Please try again.\n";
   }
  }
    
  Beads.appendNode(beadMaterial); //Stores the material
  
}

void insertNode(Necklace &Beads,string beads[])
{

bool var = false;
string beadMaterial;
int location;

while (!var) {
  cout << "\nChoose one of the following bead material options: turquoise, coral, gold, copper: ";
  cin >> beadMaterial;
  cin.ignore();

  for (int i = 0; i < numBeads; i++) 
  {
    if (beads[i] == beadMaterial) 
    {
      var = true;
      break;
    }
  }

  if (!var) {
    cout << "\nInvalid bead material option. Please try again.\n";
  }
}

cout << "\nEnter the location where you would like your bead to be placed:";
cin >> location;

Beads.insertNode(beadMaterial, location); //Stores the bead material and location

if(Beads.insertNode(beadMaterial, location) == -1)
{
  cout << "\nError. No location found.\n";
}

else if(Beads.insertNode(beadMaterial, location) == 0)
{
    cout << "\nBead has been added succesfully.\n";
}
    
}


void deleteNode(Necklace &Beads) //Function that deletes the node from the necklace
{
  
  int location;
  Beads.print();
  
  cout << "\nSelect the location of the bead you would like to be deleted: ";
  cin >> location;
  
  Beads.deleteNode(location); //Deletes the node from the given location
  if(Beads.deleteNode(location) == -1) //If there are currently no beads at this particular location
  {
    cout << "\nError. There are currently no beads at this location.\n";
  }
  else if(Beads.deleteNode(location) == 0) //If the bead was located and deleted
  {
    cout<< "\nBead has been deleted succesfully.\n";
  }
}

void printNode(Necklace &Beads) //Outputs all the current beads
{
  Beads.print();
}

void searchNode(Necklace &Beads, string beads[]) //Searches for for a node location
{
  string beadMaterial;
  bool var = false;
  
  cout << "\nEnter the material to search for:  ";
  cin >> beadMaterial;
  cin.ignore();

  for(int i=0; i < numBeads; i++)
    {
      if(beads[i] == beadMaterial)
      {
        var = true;
      }
    }
    
  if(var == true)
  {
    Beads.search(beadMaterial); //If boolean is true, then the material of bead can be searched
  }
  
  else
  {
   cout<< "\nInvalid bead material option. Please try again.\n"; //If the material is invalid, the search cannot be performed
  }
  
}


void exitProgram()
{
  cout << "\nBye! I hope that you are liking your bead choices.\n";

  exit (0);
}


