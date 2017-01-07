/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:   10/03/2016
 * ** Description:  This program asks the user for the name of a file 
 * **                and then tries to open it. If the file exists and 
 * **                can be opened, then the program will read a list of
 * **                integers from the file, calculate the sum, and
 * **                write that sum to a file named "sum.txt"
 * *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  std::string inputFileName;          // declare the input file name
  int sum = 0;                        // declare the running sumation

  // promp user for input
  std::cout << "Please enter name of file to read:" << std::endl;
  std::cin >> inputFileName;      // user input stored in inputFileName string

  // establish file input and attempt to open
  std::ifstream input;
  input.open(inputFileName);

  // check to see if file was successfully opened
  if (std::ifstream(inputFileName)) {
    // if so, continue with normal operation
    int numList;                  // declare placeholder for input integers
    input >> numList;             // pull first integer from input

    while(input.good())           // check to see if we have valid input
    {
      sum = sum + numList;        // if so, add the number to our sum
      input >> numList;           // check for the next valid input
    }                             // kick out of the while loop at EOF
    input.close();                // at this point we're done with the input file

    std::ofstream output;         // establish file output
    output.open("./sum.txt");     // and attempt to open
    output << sum;                // write calculated sum to output file
    output.close();               // close output file
  }
  else // if file was not opened successfully, then issue an error message here
  {
    std::cout << "File could not be opened!" << std::endl;
  }

  return 0;
}
