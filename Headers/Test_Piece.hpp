#ifndef TEST_PIECE_HPP_INCLUDED
#define TEST_PIECE_HPP_INCLUDED

#include <new>
#include "Piece.hpp"

using namespace std;

class Test_Piece
{
private:
  const static bool FALHA;
  const static bool SUCESSO;
  bool estado;

  Piece *piece;

  void makePiece(void);
  void destroyPiece(void);

public:
  bool run(void);
};

#endif