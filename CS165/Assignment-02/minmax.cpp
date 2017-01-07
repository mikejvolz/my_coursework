/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/03/2016
 * ** Description:  a program which take user input of user-defined
 * **               number of integers, those integers, and then outputs 
 * **               the miminum and maximum of those input values.
 * *********************************************************************/

#include <iostream>
#include <string>

// a simple five-number averaging program
int main()
{
    int userNumberOfIntegers;          // user-input number of integers to enter
    int maxInput;                      // running maximum value placeholder
    int minInput;                      // running minimum value placeholder
    int tempInput;                     // a temporary placeholder for cin values

    // promp user for input
    std::cout << "How many integers would you like to enter?" << std::endl;

    // save first user input to userNumberOfIntegers, which will be used in below loop
    std::cin >> userNumberOfIntegers;

    // promp user for integers
    std::cout << "Please enter " << userNumberOfIntegers << " integers." << std::endl;

    // loop for userNumberOfIntegers and compare user input as we go
    for (int idx = 0 ; idx < userNumberOfIntegers ; idx++) {  // idx is our counter
      std::cin >> tempInput;            // user input to tempInput

      if (tempInput > maxInput) {       // determining if user input is greater than maxInput
        maxInput = tempInput;           // if so, store new user input as maxInput
      }

      if (tempInput < minInput) {       // determining if user input is less than minInput
        minInput = tempInput;           // if so, store new user input as minInput
      }
    }

    // display minimum and maximum values that were captured above
    std::cout << "min:" << minInput << std::endl; 
    std::cout << "max:" << maxInput << std::endl; 

    return 0;
}
