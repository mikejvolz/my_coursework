/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:    9/22/2016
 * ** Description:  A simple program that calculates cents to coins
 * *********************************************************************/

#include <iostream>
#include <string>

int main()
{
  int centsRemain;               // declare variable for input cents
  int numberOfQuarters;          // declare variable for number of quarters
  int numberOfDimes;             // declare variable for number of dimes
  int numberOfNickles;           // declare variable for number of nickles
  int numberOfPennies;           // declare variable for number of pennies
  int runningCount;              // declare variable for a running count

  // promp user for input
  std::cout << "Please enter an amount in cents less than a dollar." << std::endl;
  std::cin >> centsRemain;       // user input to centsRemain

  // now we have the user input, and can do the calculations
  // calculate number of Quarters, and remainder
  numberOfQuarters = centsRemain / 25;
  runningCount = centsRemain % 25;

  // calculate number of Dimes, and remainder
  numberOfDimes = runningCount / 10;
  runningCount = runningCount % 10;

  // calculate number of Nickles, and remainder
  numberOfNickles = runningCount / 5;
  runningCount = runningCount % 5;

  // the remaining number of cents is simply the number of pennies
  numberOfPennies = runningCount;

  // display the resulting value
  std::cout << "Your change will be:" << std::endl; 
  std::cout << "Q: " << numberOfQuarters << std::endl; 
  std::cout << "D: " << numberOfDimes << std::endl; 
  std::cout << "N: " << numberOfNickles << std::endl; 
  std::cout << "P: " << numberOfPennies << std::endl; 
    
  return 0;
}
