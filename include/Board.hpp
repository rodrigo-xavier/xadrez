#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include <map>

using namespace std;

class Board
{
private:
  const static unsigned short int LINHAS = 8;
  const static unsigned short int COLUNAS = 8;

  map<char, Piece> piece;
  map<char, Piece> id_king['k'] = new King;
  char board[8][8];

  void initBoard(void);
  void destroyBoard(void);
  void updateBoard(void);

public:
  Board(); // Construtor deve inserir o estado inicial das peças no tabuleiro
  ~Board();
  char returnBoardPosition(int, int);
};

#endif