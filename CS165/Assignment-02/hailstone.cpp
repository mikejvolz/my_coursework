/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/04/2016
 * ** Description:  a function named hailstone starts with a positive integer
 * **               as an input. If that integer is even, then you divide it 
 * **               by two to get the next integer in the sequence, 
 * **               but if it is odd, then you multiply it by three and add one 
 * **               to get the next integer in the sequence.
 * **               output is the number of "steps" it took to get to 1
 * *********************************************************************/

#include <iostream>
using namespace std;

void hailstone (unsigned int &seed)
{
  unsigned int currentValue = seed,
              idx = 0;

  // using a while loop here, always looking to see if currentValue is 1
  // if so, we're doing, we kick out of the while loops and report the index
  while (currentValue != 1)
  {
    // first determine if currentValue is even or odd
    if ((currentValue % 2) == 0) {
      // we have determined that it's an even value, so we divide it by two
      currentValue = currentValue/2;
    }
    else {
      // we have determined that it's an odd value, so we multiply by three and add one
      currentValue = (currentValue * 3) + 1;
    }
    // incriment counter
    idx++;
  }
  // display final results of loop counter, which is how many steps it took to get to the value 1
  std::cout << "It took " << idx << " steps to reach 1." << endl;
}

// testbench
/*
int main()
{
  unsigned int seed;

  std::cout << "Please enter a starting value: " << endl;
  std::cin >> seed;

  hailstone (seed);

  return 0;
}
*/
