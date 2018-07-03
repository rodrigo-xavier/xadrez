#ifndef STATES_HPP_INCLUDED
#define STATES_HPP_INCLUDED

#include "Piece.hpp"

enum class Obstacles{Empty,Friend,Enemy};

class States
{
public:
  Piece * white_pieces[16];
  Piece * black_pieces[16];
  States();
  Obstacles IsInTheWay(int, int, Piece *);
  Obstacles IsInTheSpot(int, int, Piece *);
  bool IsCheck(bool, int, int);
  bool MovePiece(Piece *, int, int);  //Move a peça apenas se for possivel, retornando true quando possivel e false caso contrario (podendo comer uma peça quando uma inimiga estiver na casa final)
  void EatPiece(int, int);    //Mata a peça da posição x, y.

  //FAZER A SETAGEM/CHECAGEM DE PEÇAS QUE ESTAO NA DIAGONAL DE CADA PEAO NO MovePiece
};

#endif
