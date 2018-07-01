#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef KNIGHT_HPP_INCLUDED
#define KNIGHT_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Knight : public Piece
{
  public:
    Knight(bool, int, int);
    ~Knight();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
    bool IsMovementPossible(int, int);
};

#endif
