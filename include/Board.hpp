#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

using namespace std;

class Board
{
private:
  const static unsigned short int LINHAS = 8;
  const static unsigned short int COLUNAS = 8;

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
  void destroyBoard(void);
  char returnPiece(int, int);
};

#endif
