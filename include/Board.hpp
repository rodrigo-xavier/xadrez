#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "Piece.hpp"

using namespace std;

class Board
{
private:

  PieceName name;

  char board[8][8] =
    {{'t', 'c', 'b', 'k', 'q', 'b', 'c', 't'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'0', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'t', 'c', 'b', 'q', 'k', 'b', 'c', 't'}};

public:
  Board(void);
  ~Board();
  void destroy_board(void);
  char return_piece(int, int);
  void insert_piece(int, int, char);
};

#endif
