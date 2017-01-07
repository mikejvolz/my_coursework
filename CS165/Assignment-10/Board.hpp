/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/26/2016
 ** Description: Declaration (header) of Board class
 **              member variables include a two-dimensional array (char)
 **              definitiona include an enumerated type 
 **               to indicate the state of the game ("state")
 **              and a player type (X, O, or unknown)
 **              member methods include a constructor, makeMove, 
 **              print, and gameState
 ** ****************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

using namespace std;

class Board
{
protected:
    char myBoard [3][3];

public:
    Board();

    enum state {notStarted,inProgress,xWon,oWon,itsaDraw};
    enum player {X,O,unknown};
    bool makeMove(int, int, player);
    void print();
    state gameState();

private:

};

#endif // BOARD_HPP


