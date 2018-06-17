#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "Piece.hpp"

using namespace std;

class Board
{
private:
  const static unsigned short int LINHAS = 8;
  const static unsigned short int COLUNAS = 8;

  Piece **matrix;

public:
  Board(); // Construtor deve inserir o estado inicial das peças no tabuleiro
  ~Board();
};

int soma(int a,int b);

#endif
