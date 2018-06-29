#include "../include/Queen.hpp"

Queen::Queen(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Queen;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
}

Queen::~Queen()
{
}
