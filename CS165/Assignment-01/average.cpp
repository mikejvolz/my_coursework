/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:    9/22/2016
 * ** Description:  A simple five-number averaging program
 * *********************************************************************/

#include <iostream>
#include <string>

// a simple five-number averaging program
int main()
{
    float numberOne;                   // declare first number
    float numberTwo;                   // declare second number
    float numberThree;                 // declare third number
    float numberFour;                  // declare fourth number
    float numberFive;                  // declare fifth number 
    float numberAverage;               // declare average

    // promp user for input
    std::cout << "Please enter five numbers." << std::endl;
    std::cin >> numberOne;             // user input to numberOne
    std::cin >> numberTwo;             // user input to numberTwo
    std::cin >> numberThree;           // user input to numberThree
    std::cin >> numberFour;            // user input to numberFour
    std::cin >> numberFive;            // user input to numberFive
    std::cout << "The average of those numbers is:" << std::endl; 

    // now we have the user input, and can calculate the averate
    numberAverage = (numberOne + numberTwo + numberThree + numberFour + numberFive)/5;
    std::cout << numberAverage << std::endl; // display calculated average
    
    return 0;
}
