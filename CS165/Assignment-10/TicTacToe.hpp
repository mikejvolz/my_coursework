/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/26/2016
 ** Description: Declaration (header) of TicTacToe class
 **              member variables include pointer to a Board object
 **               and currentPlayer (type player, defined in Board)
 **              member functions include a constructor and play method
 ** ****************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <iostream>

using namespace std;

class TicTacToe
{
protected:
    Board * thisBoard;

public:
    TicTacToe(char);
    Board::player currentPlayer;
    void play();

private:

};

#endif // TICTACTOE_HPP

