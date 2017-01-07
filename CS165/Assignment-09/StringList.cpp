/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/20/2016
 ** Description: Implementation of StringList object class
 **              uses an appropriate definition of ListNode
 **                (found in ListNode.cpp) to implement a linked-list
 **                of strings
 **              medhods include add(), positionOf() setNodeVal()
 **                getAsVector(), a default constructor, 
 **                a copy constructor, and a destructor
 **              see individual method comments for details
 ****************************************************************/
#include "StringList.hpp"

/************************************************
 * StringList default constructor
 * no arguments, no return
 ************************************************/
StringList::StringList() : head(NULL)
{
   //  nothing to do here - using initialization above to construct
}

/************************************************
 * StringList copy constructor
 * StringList object argument
 ************************************************/
StringList::StringList(StringList const &copyMyListNode)
{
  ListNode *copyNodePtr = copyMyListNode.head;                       // start at the head of the list to copy

  if (copyNodePtr != NULL) {                                         // chcking for a NULL  head
    this->head = new ListNode(copyNodePtr->value,copyNodePtr->next); // if it's null, create it
    ListNode *myNodePtr = this->head;                                // Dstart at the head of the list to copy
    while (copyNodePtr->next != NULL) {                              // chcking for a NULL next
      myNodePtr->next = new ListNode(copyNodePtr->value,copyNodePtr->next);     // if it's null, create it
      copyNodePtr = copyNodePtr->next;                               // if it is NOT NULL, go to next node
      myNodePtr = myNodePtr->next;                                   // if it is NOT NULL, go to next node
    }                                                                //
    myNodePtr = new ListNode(copyNodePtr->value);                    // if it's null, create it
  }
}

/************************************************
 * StringList destructor method
 * no arguments, no return
 ************************************************/
StringList::~StringList()
{
  ListNode *nodePtr = head;
  while (nodePtr != NULL)
  {
    ListNode *garbage = nodePtr;
    nodePtr = nodePtr->next;
    delete garbage;
  }
}

/************************************************
 * StringList add method
 * one argument: string to add
 * method adds a new node containing the value of 
 * the parameter to the end of the list
 ************************************************/
void StringList::add(std::string addNewString)
{
  if (this->head == NULL)                                 // chcking for a NULL  head
    this->head = new ListNode(addNewString);              // if it's null, create it
  else {                                                  // otherwise
    ListNode *nodePtr = head;                             // start at the head of the list
    while (nodePtr->next != NULL)                         // look for a NULL pointer at next
      nodePtr = nodePtr->next;                            // if it is NOT NULL, go to next node
    nodePtr->next = new ListNode(addNewString, NULL);     // if it's null, create new node here
  }
}

/************************************************
 * StringList positionOf method
 * one artumentstring indicating something
 * returns the (zero-based) position in the list 
 * for the first occurrence of the parameter in the list, 
 * or -1 if that value is not in the list
 ************************************************/
int StringList::positionOf (std::string searchString)
{
  int position = 0;
  ListNode *nodePtr = head;                               // start at the head of the list

  while ((nodePtr != NULL) && (nodePtr->value != searchString)) // check for null next and look for value
  {                                                       // try to match value to search string
    nodePtr = nodePtr->next;                              // while we traverse the list
    position++;                                           // incriment position counter
  }
  if (nodePtr == NULL)                                    // if we end without finding a match
    position = -1;                                        // set position value of -1
  return position;                                        // return position value
}

/************************************************
 * StringList getAsVector method
 * arguments include: zero-based integer argument for position in the list
 *                     string argument for value to be set
 * bool return indicates successful addition
 ************************************************/
bool StringList::setNodeVal(int positionInt, std::string newNodeValToSet)
{
  int currentPosition = 0;                                // position incriment holder
  bool success = 0;                                       // success flag (0 is failure, 1 is success)
  ListNode *nodePtr = head;                               // start at the head of the list

  while ((nodePtr != NULL) && (currentPosition != positionInt))  // neck for NULL head, then look for position
  {                                                       // try to match position value
    nodePtr = nodePtr->next;                              // while we traverse the list
    currentPosition++;                                    // incriment position counter
  }
  if (currentPosition == positionInt) {                   // if we end without finding a match
    nodePtr->value = newNodeValToSet;                     // assign value
    success = 1;                                          // set success flag
  }
  return success;                                         // and return the success flag
}

/************************************************
 * StringList getAsVector method
 * no arguments - returns vector of string values
 ************************************************/
std::vector<std::string> StringList::getAsVector()
{
// TBD: test this
  vector<string> tempVect;                                // create temporary vector
  ListNode *nodePtr = head;                               // start at the head of the list
  while (nodePtr != NULL)                                 // loop while node is not NULL
  {
    tempVect.push_back(nodePtr->value);                   // store each value, then
    nodePtr = nodePtr->next;                              // go to the next node
  }
  return tempVect;                                        // and return the vector
}

/*
int main ()
{
  std::string lookingForThis = "Fifth addition";

  StringList l1;
  l1.add("First addition");
  l1.add("Second addition");
  l1.add("Third addition");
  l1.add("Fourth addition");
  l1.add("Fifth addition");
  l1.add("Sixth addition");
  l1.add("Seventh addition");
  l1.add("Eigth addition");
  l1.add("Ninth addition");
  l1.add("Tenth addition");
  l1.add("Eleventh addition");

  cout << "I found " << lookingForThis << " at: " << l1.positionOf(lookingForThis) << endl;
  bool gotit = l1.setNodeVal(4,"re-wrote position four string");
  lookingForThis = "re-wrote position four string";
  cout << "I found " << lookingForThis << " at: " << l1.positionOf(lookingForThis) << endl;


  vector<string> myVect = l1.getAsVector();
  for (std::vector<string>::const_iterator i = myVect.begin(); i != myVect.end(); ++i)
    std::cout << *i << ' ';
  cout << endl;


  StringList l2 = l1;

  lookingForThis = "re-wrote position four string";
  gotit = l2.setNodeVal(4,lookingForThis);
  cout << "I found " << lookingForThis << " at: " << l2.positionOf(lookingForThis) << endl;

  vector<string> myNewVect;
  myNewVect = l2.getAsVector();
  for (std::vector<string>::const_iterator i = myNewVect.begin(); i != myNewVect.end(); ++i)
    std::cout << *i << ' ';
  cout << endl;
}
*/
