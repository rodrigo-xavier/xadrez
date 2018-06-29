#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef KING_HPP_INCLUDED
#define KING_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class King : public Piece
{
  public:
    King(bool, int, int);
    ~King();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
};

#endif
