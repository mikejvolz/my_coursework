/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/26/2016
 ** Description: Implementation of TicTacToe class
 **              member variables include pointer to a Board object
 **               and currentPlayer (type player, defined in Board)
 **              member functions include a constructor and play method
 ***************************************************************/

#include "Board.cpp"
#include "TicTacToe.hpp"
#include <iostream>

using namespace std;

/************************************************
 * TicTacToe constructor with argument:   
 *     initial player character
 ************************************************/
TicTacToe::TicTacToe(char initalPlayer)
{
  thisBoard = new Board;                     // allocate memory for Board object
  if (initalPlayer == 'x')                   // if argument is x
    currentPlayer = Board::X;                // then set currentPlayer accordingly
  else if(initalPlayer == 'o')               // if argument is o
    currentPlayer = Board::O;                // then set currentPlayer accordingly
  else                                       // if argument is not set corectly,
    currentPlayer = Board::X;                // then set currentPlayer to x (default)
}

/************************************************
 * TicTacToe play method 
 *     no arguments, no returns
 *     this mentod primarily provides prodedural
 *     game-play arbitration and status monitoring
 *     only runs for one game - when game is complete,
 *       method returns
 ************************************************/
void TicTacToe::play()
{
  while ((thisBoard->gameState() == Board::notStarted) || 
         (thisBoard->gameState() == Board::inProgress))
  {
    bool successMove = 0;                    // placeholder for a successful move
    int xCoord, yCoord;                      // placeholders for X and Y coordinates
    cout << endl;                            // print a blankline
    thisBoard->print();                      // print the board

    if (currentPlayer == Board::X)           // if it's player X's turn
    {
      cout << "Player X: please enter your move." << endl;
      cin >> xCoord >> yCoord;               // pull in coordinates from user input
      successMove = thisBoard->makeMove(xCoord,yCoord,Board::X); // call the makeMove method
      if (successMove)                       // if the move was successful,
        currentPlayer = Board::O;            // swap player
    }
    else if (currentPlayer == Board::O)      // if it's player O's turn
    {
      cout << "Player O: please enter your move." << endl;
      cin >> xCoord >> yCoord;               // pull in coordinates from user input
      successMove = thisBoard->makeMove(xCoord,yCoord,Board::O); // call the makeMove method
      if (successMove)                       // if the move was successful,
        currentPlayer = Board::X;            // swap player
    }
  }
                                                       // we got kicked out of the while loop
  thisBoard->print();                                  // print the board
  if (thisBoard->gameState() == Board::xWon)           // determine if player X won
    cout << "Player X won the game!" << endl;          // if so, announce it
  else if (thisBoard->gameState() == Board::oWon)      // determine if player O won
    cout << "Player O won the game!" << endl;          // if so, announce it
  else if (thisBoard->gameState() == Board::itsaDraw)  // deterine if game is a draw
    cout << "The game is a draw!" << endl;             // if so, announce it
  else 
    cout << "Error: final game state is unknown." << endl; // error case
}

int main() {
  TicTacToe t1('x');
  t1.play();
}
