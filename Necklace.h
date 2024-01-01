#ifndef NECKLACE_H
#define NECKLACE_H

#include <iostream>
#include <string>
using namespace std;

const int numBeads = 4; //Constant integer of the given bead materials

class Necklace //Necklace class declaration
{
private:
  struct beadNode //Declares a node
  {
      int loc = 0; //Stores the location
      string material; //Stores bead material
      beadNode *next; //Points to the next node
  };

  beadNode *head; //Bead head pointer

public:

  Necklace(){head = nullptr;} //Constructor
    
  //Linked list operations
  void appendNode(string);
  int insertNode(string, int);
  int deleteNode(int);
  void print() const;
  void search(string);

};

#endif