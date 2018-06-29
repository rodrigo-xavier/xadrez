#include "../include/Rook.hpp"

Rook::Rook(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Rook;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
}

Rook::~Rook()
{
}
