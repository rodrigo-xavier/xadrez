#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "States.hpp"
#include "Piece.hpp"

using namespace std;

class Board
{
private:

  States *states;
  Piece *piece;
  bool color;

  char board[8][8] =
    {{'T', 'C', 'B', 'K', 'Q', 'B', 'C', 'T'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
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
  void update_board(States *);
};

#endif
