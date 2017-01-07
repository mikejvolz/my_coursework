#include <iostream>
#include "Box.hpp"

using namespace std;

/* ===============================================================
 * boxSort function input arguments are an array of Box objects
 * and an integer indicating the size of that array
 * no return - array will be sorted in descending order according
 * to volume of each Box element.
 * =============================================================== */
void boxSort(Box array[], int size)
{
  Box temp;                    // temporary placeholder for Box object swapping
  bool madeAswap;              // bool varialbe to indicate a swap was made

  do
  { madeAswap = false;         // initialize madeAswap to false always
  for (int count = 0; count < (size - 1); count++)  // loop through the entire data set
    {
      if (array[count].getVolume() < array[count+1].getVolume())  // calculate if next is greater than the current
      {
        temp = array[count];              // if next element is greater than the current, then make the swap
        array[count] = array[count+1];    // using that temp placeholder here
        array[count+1] = temp;            // finishing the swap
        madeAswap = true;                 // assert madeAswap bool flag
      }
    }
  } while (madeAswap);          // keep looping until we dont' swap anything
}

/*
int main()
{

    Box b1(15.1 , 15.2 , 15.3);
    cout<<"Box1 volume is: " << b1.getVolume() << endl;

    Box b2(1.1 , 5.2 , 3.2);
    cout<<"Box2 volume is: " << b2.getVolume() << endl;

    Box b3(101.1 , 500.2 , 3.2);
    cout<<"Box2 volume is: " << b3.getVolume() << endl;

    Box b4(1.1 , 0.2 , 0.2);
    cout<<"Box2 volume is: " << b4.getVolume() << endl;

    Box BoxArray[4] = {b1, b2, b3, b4};
    for (int idx = 0 ; idx < 4; idx++) 
    {
      cout<<"Box [" << idx << "] volume is: " << BoxArray[idx].getVolume() << endl;
    }
    boxSort(BoxArray, 4);
    for (int idx = 0 ; idx < 4; idx++) 
    {
      cout<<"Box [" << idx << "] volume is: " << BoxArray[idx].getVolume() << endl;
    }

    return 0;
}
*/
