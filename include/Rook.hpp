#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef ROOK_HPP_INCLUDED
#define ROOK_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Rook : public Piece
{
  public:
    Rook(bool, int, int);
    ~Rook();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
};

#endif
