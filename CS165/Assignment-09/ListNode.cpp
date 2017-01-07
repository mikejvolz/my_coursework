using namespace std;

#include <string>

struct ListNode
{
  string value;
  ListNode *next;
  ListNode(string newValue, ListNode *nextNode = NULL)
  {
    value = newValue;
    next = nextNode;
  }
};

/*
int size(ListNode *);
void displayList(ListNode *);

int main()
{
  ListNode *string2 = new ListNode("This is my other STRING!");
  ListNode *stringList = NULL;                        // define HEAD !?!
  stringList = new ListNode("This is my STRING!",string2);


  cout << "The Contents of the list are: " << endl;
  displayList(stringList);
  cout << endl << endl;

  cout << "The size of the list are: " << size(stringList) << endl;

  return 0;
}

int size(ListNode *ptr)
{
  if (ptr == NULL)
  {
    return 0;
  }
  else
    return 1 + size(ptr->next);
}

void displayList(ListNode *ptr)
{
  if (ptr != NULL)
  {
    cout << ptr->value << " ";
    displayList(ptr->next);
  }
}

*/
