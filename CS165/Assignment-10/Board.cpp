/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/26/2016
 ** Description: Implementation of Board class
 **              member variables include a two-dimensional array (char)
 **              definitiona include an enumerated type
 **               to indicate the state of the game ("state")
 **              and a player type (X, O, or unknown)
 **              member methods include a constructor, makeMove,
 **              print, and gameState
 ***************************************************************/

#include "Board.hpp"
#include <iostream>

using namespace std;

/************************************************
 * Board constructor with no arguments
 ************************************************/
Board::Board()
{
  // Initialize the "board" to a default state
  for (int idx = 0 ; idx < 3; idx ++) 
  {
    for (int kdx = 0 ; kdx < 3; kdx ++) 
    {
      myBoard[idx][kdx] = '.';
    }
  }
}

/************************************************
 * Board makeMove method 
 *  arguments include x and y coordinates (ints
 *  and the currently active player (enume type player)
 ************************************************/
bool Board::makeMove(int x, int y, player activePlayer)
{
  if ((x > 2) || (y > 2) || (x < 0) || (y < 0)) {  // checking for out-of-bounds input
    cout << "Invalid index, please try again" << endl;
    return 0;                                      // return FALSE bool value
  }
  else if(myBoard[x][y] == '.')                    // check for no previous claim on this spot
  {
    if(activePlayer == X)                          // for X player
    {
      myBoard[x][y] = 'x';                         // apply x char to array position
      return 1;                                    // and return TURE bool value
    }
    else if(activePlayer == O)                     // for O player
    {
      myBoard[x][y] = 'o';                         // apply o char to array position
      return 1;                                    // and return TURE bool value
    }
    else                                           // if we landed here,  player is unknown
    {
      return 0;                                    // and return FALSE bool value
    }
  }
  else                                             // if we landed here, the cell was already claimed
  {
    cout << "That square is already taken." << endl << endl;   // spit out a message to the player
    return 0;                                      // and return FALSE bool value
  }
}

/************************************************
 * Board gameState method 
 *  no argument, returns enume type state
 ************************************************/
Board::state Board::gameState()
{
  int xCount = 0;
  int oCount = 0;
  player winner = unknown;
  for (int idx = 0 ; idx < 3; idx ++) 
  {
    for (int kdx = 0 ; kdx < 3; kdx ++) 
    {
      if (myBoard[idx][kdx] == 'x') xCount++;
      else if (myBoard[idx][kdx] == 'o') oCount++;
    }
  }

// checking horizontals for a win
  if      ((myBoard[0][0] == 'x') &&
           (myBoard[0][1] == 'x') &&
           (myBoard[0][2] == 'x')) winner = X;
  else if ((myBoard[0][0] == 'o') &&
           (myBoard[0][1] == 'o') &&
           (myBoard[0][2] == 'o')) winner = O;
  else if ((myBoard[1][0] == 'x') &&
           (myBoard[1][1] == 'x') &&
           (myBoard[1][2] == 'x')) winner = X;
  else if ((myBoard[1][0] == 'o') &&
           (myBoard[1][1] == 'o') &&
           (myBoard[1][2] == 'o')) winner = O;
  else if ((myBoard[2][0] == 'x') &&
           (myBoard[2][1] == 'x') &&
           (myBoard[2][2] == 'x')) winner = X;
  else if ((myBoard[2][0] == 'o') &&
           (myBoard[2][1] == 'o') &&
           (myBoard[2][2] == 'o')) winner = O;

// checking verticals for a win
  else if ((myBoard[0][0] == 'x') &&
           (myBoard[1][0] == 'x') &&
           (myBoard[2][0] == 'x')) winner = X;
  else if ((myBoard[0][0] == 'o') &&
           (myBoard[1][0] == 'o') &&
           (myBoard[2][0] == 'o')) winner = O;
  else if ((myBoard[0][1] == 'x') &&
           (myBoard[1][1] == 'x') &&
           (myBoard[2][1] == 'x')) winner = X;
  else if ((myBoard[0][1] == 'o') &&
           (myBoard[1][1] == 'o') &&
           (myBoard[2][1] == 'o')) winner = O;
  else if ((myBoard[0][2] == 'x') &&
           (myBoard[1][2] == 'x') &&
           (myBoard[2][2] == 'x')) winner = X;
  else if ((myBoard[0][2] == 'o') &&
           (myBoard[1][2] == 'o') &&
           (myBoard[2][2] == 'o')) winner = O;
// checking diagonals
  else if ((myBoard[0][0] == 'x') &&
           (myBoard[1][1] == 'x') &&
           (myBoard[2][2] == 'x')) winner = X;
  else if ((myBoard[0][0] == 'o') &&
           (myBoard[1][1] == 'o') &&
           (myBoard[2][2] == 'o')) winner = O;
  else if ((myBoard[0][2] == 'x') &&
           (myBoard[1][1] == 'x') &&
           (myBoard[2][0] == 'x')) winner = X;
  else if ((myBoard[0][2] == 'o') &&
           (myBoard[1][1] == 'o') &&
           (myBoard[2][0] == 'o')) winner = O;

  if (winner == X)               // if X is the winner
    return xWon;                 // return that status
  else if (winner == O)          // if O is the winner
    return oWon;                 // return that status
  else if (xCount + oCount == 0) // check for an empty board
    return notStarted;           // if so, return that status
  else if ((winner == unknown) && (xCount + oCount < 9)) // check for unfinished game
    return inProgress;           // if so, return that status
  else if ((xCount + oCount == 9) && (winner == unknown)) // check for compelted game with now winner
    return itsaDraw;             // if so, game is a draw - return that status
}

/************************************************
 * Board print method 
 *   no arguments, no reutn - simply displays the board
 ************************************************/
void Board::print()
{
  cout << "  0 1 2"  << endl;            // pring header
  for (int idx = 0 ; idx < 3; idx ++)    // loop through for each column
  {
    cout << idx << " ";                  // add a space before each row
    for (int kdx = 0 ; kdx < 3; kdx ++)  // loop through each row
    {
      cout << myBoard[idx][kdx] << " ";  // print each value stored
    }
    cout << endl;                        // print new line between rows
  }
  cout << endl;                          // print yet another new line (terminating)
}

/*
int main ()
{
  bool result = 0;
  cout <<  "testing compile" << endl;

  Board b1;
  b1.print();
  b1.gameState();

  result = b1.makeMove(0,0,Board::X);
  b1.print();
  b1.gameState();

  result = b1.makeMove(1,1,Board::O);
  b1.print();
  b1.gameState();

  result = b1.makeMove(0,2,Board::X);
  b1.print();
  b1.gameState();

  result = b1.makeMove(0,1,Board::O);
  b1.print();
  b1.gameState();

  result = b1.makeMove(2,1,Board::X);
  b1.print();
  b1.gameState();

  result = b1.makeMove(1,0,Board::O);
  b1.print();
  b1.gameState();

  result = b1.makeMove(1,2,Board::X);
  b1.print();
  b1.gameState();

  result = b1.makeMove(1,2,Board::O);
  b1.print();
  b1.gameState();

  result = b1.makeMove(2,2,Board::O);
  b1.print();
  b1.gameState();

  result = b1.makeMove(2,0,Board::X);
  b1.print();
  b1.gameState();
}
*/
