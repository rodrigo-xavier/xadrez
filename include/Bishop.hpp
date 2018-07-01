#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef BISHOP_HPP_INCLUDED
#define BISHOP_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Bishop : public Piece
{
  public:
    Bishop(bool, int, int);
    ~Bishop();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
    bool IsMovementPossible(int, int);
};

#endif
