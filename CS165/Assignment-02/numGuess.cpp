/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/03/2016
 * ** Description:  a program that prompt the user for an integer value,
 * **               and then propts for further input to guess the initial value
 * **               final output includes number of guesses
 * *********************************************************************/

#include <iostream>
#include <string>

// a simple five-number averaging program
int main()
{
    int theNumber;                     // user input number to be guessed
    int tempGuessedNumbmer;            // user guess - only need one
    int idx = 0;                       // index loop counter tracks number of guesses
    bool numberGuessed = 0;            // s flag to indicate when the number has been guessed

    // promp user for input
    std::cout << "Enter the number for the player to guess." << std::endl;

    // save first user input to theNumber, which is the number to be guessed
    std::cin >> theNumber;

    // promp user for first guess
    std::cout << "Enter your guess." << std::endl;

    while (!numberGuessed) {           // loop while the number has not been guessed successfully
      std::cin >> tempGuessedNumbmer;  // pull the user guess

      idx++;                           // incriment the counter - note that we initialized to zero above
      // look for guess greater than theNumber
      if (tempGuessedNumbmer > theNumber) {
        // return result of comparison and promp user for next guess
        std::cout << "Too high - try again." << std::endl;
      }
      // look for guess less than theNumber
      else if (tempGuessedNumbmer < theNumber) {
        // return result of comparison and promp user for next guess
        std::cout << "Too low - try again." << std::endl;
      }
      // look for guess equal to theNumber
      else if (tempGuessedNumbmer == theNumber) {
        // if guess is equal to theNumber, then set numberGuessed flag, which will end while loop
        numberGuessed = 1;
        // return result of comparison and final count index, which is the number of guesses
        std::cout << "You guessed it in " << idx << " tries." << std::endl;
      }
      // looking for a failure case in the math - this is just in case
      else {
        std::cout << "ERROR:  something went wrong!" << std::endl;
      }
    }

    return 0;
}
