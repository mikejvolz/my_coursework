/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/22/2016
 ** Description: postfixEval function definition
 **               accespts as input string representing postfix notation
 **              function calculates mathematical result
 **              return value is double - result of calculations
 ****************************************************************/


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

double postfixEval(const string input)
{
  double result;                                // container for results
  char myLocalString [256];                     // container for c-style input string
  int charPos = 0;                              // iterator for c-style string
  vector<double> foundDigits;                   // vector to store found integers (as doubles)


  for(int kdx = 0; kdx <= 255; kdx++)           // loop through the character placeholder
    myLocalString[kdx] = '\0';                  // and clear all values - clean slate

  for (int idx = 0 ; idx<input.size(); idx++) { // loop through each input character
    if (isdigit(input[idx])) {                  // determine if character is digit
      myLocalString[charPos] = input[idx];      // if so, stash that character
      charPos++;                                // incrimenet position counter
    }
    else if (input[idx] == ' ')                 // check to see if it's a space
    {
      if (myLocalString[0] != '\0')             // if so, check to see if we have unhandled digits
      {
        int localInt = atoi(myLocalString);     // if so, convert them to an int
        foundDigits.push_back(double(localInt));// then convert that to a double and push it to the vector
        for(int kdx = 0; kdx <= charPos; kdx++) // loop through the character placeholder
          myLocalString[kdx] = '\0';            // and clear all values
        charPos = 0;                            // and reset the position counter
      }
    }
    else                                        // if it's NOT a digit or a space
    {                                           // we're assuming that it's an operator
      if (myLocalString[0] != '\0')             // check to see if we have unhanndled digits
      {
        int localInt = atoi(myLocalString);     // if so, convert them to an int
        foundDigits.push_back(double(localInt));// then convert that to a double and push then to the vector
        for(int kdx = 0; kdx <= charPos; kdx++) // loop through the character placeholder
          myLocalString[kdx] = '\0';            // clear all the values
        charPos = 0;                            // and reset the position counter
      }
      if (input[idx] == '+') {                  // if we found an addition operator
        double pop1, pop0, result;              // declare some temp value holders
        int myVectSize;                         // this could likely be more succinct
        myVectSize = foundDigits.size();        // get vector size
        pop0 = foundDigits[myVectSize-1];       // pull the two 
        pop1 = foundDigits[myVectSize-2];       //    most recently added values
        result = pop1+pop0;                     // add them
        foundDigits.resize(foundDigits.size()-2); // resize the vector
        foundDigits.push_back(result);          // and push the result to the vector
      }
      else if (input[idx] == '-') {             // if we found a subtraction operator
        double pop1, pop0, result;              // declare some temp value holders
        int myVectSize;                         // this could likely be more succinct
        myVectSize = foundDigits.size();        // get vector size
        pop0 = foundDigits[myVectSize-1];       // pull the two
        pop1 = foundDigits[myVectSize-2];       //    most recently added values
        result = pop1-pop0;                     // subtract them
        foundDigits.resize(foundDigits.size()-2); // resize the vector
        foundDigits.push_back(result);          // and push the result to the vector
      }
      else if (input[idx] == '*') {             // if we found a subtraction operator
        double pop1, pop0, result;              // declare some temp value holders
        int myVectSize;                         // this could likely be more succinct
        myVectSize = foundDigits.size();        // get vector size
        pop0 = foundDigits[myVectSize-1];       // pull the two
        pop1 = foundDigits[myVectSize-2];       //    most recently added values
        result = pop1*pop0;                     // multiply them
        foundDigits.resize(foundDigits.size()-2); // resize the vector
        foundDigits.push_back(result);          // and push the result to the vector
      }
      else if (input[idx] == '/') {             // if we found a division operator
        double pop1, pop0, result;              // declare some temp value holders
        int myVectSize;                         // this could likely be more succinct
        myVectSize = foundDigits.size();        // get vector size
        pop0 = foundDigits[myVectSize-1];       // pull the two 
        pop1 = foundDigits[myVectSize-2];       //    most recently added values
        result = pop1/pop0;                     // divide them
        foundDigits.resize(foundDigits.size()-2); // resize the vector
        foundDigits.push_back(result);          // and push the result to the vector
      }
    }
  }

  result = foundDigits.back();                  // after all characters are exhauseted, return the result
  foundDigits.erase(foundDigits.begin(),foundDigits.end());  // cleanup
  return result;                                // return the result

}

/*
int main ()
{
  double result = postfixEval("12 1 8 183 + + +");
  cout << "result is: " << result << endl;

  result = postfixEval(" 25 12 7 2 + * /");
  cout << "result is: " << result << endl;

  result = postfixEval(" 1 25 12 7 2 / + - +");
  cout << "result is: " << result << endl;

  return 0;
}
/*
