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
  //bool IsCheck(bool);
  //void GetGameMatrix(Board *);
};

#endif
