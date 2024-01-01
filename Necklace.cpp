#include "Necklace.h"
#include <iostream>

using namespace std;

void Necklace::appendNode(string mat) //End of the list
{
  string beads[numBeads] = { "turquoise", "coral", "gold", "copper" };
  
  beadNode *newNode; //To point to a new node
  beadNode *nodePtr; //To move through the list


  newNode = new beadNode;	//Allocates a new node
  newNode->material = mat;	//Stores the material data

  newNode->next = nullptr;
  
  if (!head)
    {
      head = newNode;
      cout << "\n Bead has been added to the end of the necklace \n";
    }
  
  else
    {
      nodePtr = head;

      while (nodePtr->next)
      {
          nodePtr = nodePtr->next;	//Searches for the last node in the list
      }
      
      nodePtr->next = newNode;	//Adds new node to the end of the list
      newNode->loc = nodePtr->loc + 1;
    }


}


int Necklace::insertNode(string mat, int nmbr)
{
  beadNode *prevNode = nullptr; //End of the list
  beadNode *nodePtr; //To move through the list
  beadNode *newNode; //To point to a new node

  newNode = new beadNode;
  newNode->material = mat;
  newNode->loc = nmbr;

  if (!head)
    {
      head = newNode;
      newNode->next = nullptr;
      return 0;
    }
  else
    {
      nodePtr = head;
      prevNode = nullptr;

      while ((nodePtr->loc < nmbr) && (nodePtr != nullptr))
      {
          prevNode = nodePtr;
	      nodePtr = nodePtr->next;
      }
      if (prevNode == nullptr)
      {
          head = newNode;
	      newNode->next = nodePtr;
	      return 0;
      }
      else
      {
          prevNode->next = newNode;
	      newNode->next = nodePtr;
	      return 0;
      }
    
        
    }
}


int Necklace::deleteNode(int nmbr)
{
  beadNode *prevNode = nullptr; //End of the list
  beadNode *currNode = head; //Starts from the beggining of the list
  int count = 0;
  while ((currNode != nullptr) && (count < nmbr))
    {
      prevNode = currNode;
      currNode = currNode->next;
      count++;
    }
  if (currNode == nullptr)
    {
      return 0;
    }
  else
    {
      if (prevNode == nullptr)
	  {
	    head = head->next;
	    delete currNode;
	    return 0;
	  }
      else
	  {
	  prevNode->next = currNode->next;
	  delete currNode;
	  return 0;

	  }

    }

}


void Necklace::print() const
{
  beadNode *nodePtr = head;	//Starts from the beggining of the list
  while (nodePtr != nullptr) //Stops at the end of the list
    {
      cout << "(" << nodePtr->loc << ")" << " " << nodePtr->material << endl; //Displays the position and a material
      nodePtr = nodePtr->next;	//Moves to the following node
    }
}

void Necklace::search(string mat)
{
  string beads[numBeads] = { "turquoise", "coral", "gold", "copper" };

  bool beadFind = false;
  beadNode *nodePtr = head; //Starts from the beggining of the list
  
  while (nodePtr != nullptr) //Stops at the end of the list
  {
      if (nodePtr->material == mat)
      {
          beadFind = true;
	      cout << "\n Bead is located at " << nodePtr-> loc << "." << endl;
	      break;
	  }
	  
	  nodePtr = nodePtr->next;
	 
  }
      
  if (!beadFind)
  {
      cout << "\n Bead could not be located." << endl;
  }
  
}