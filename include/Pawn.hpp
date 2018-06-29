#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef PAWN_HPP_INCLUDED
#define PAWN_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Pawn : public Piece
{
  private:
    bool hasDiagonalEnemyRight = false;
    bool hasDiagonalEnemyLeft = false;

  public:
    Pawn(bool, int, int);
    ~Pawn();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
    bool IsMovementPossible(int, int);
    void SetDiagonalEnemy(bool, bool);
};

#endif
