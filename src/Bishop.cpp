#include "../include/Bishop.hpp"

Bishop::Bishop(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Bishop;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
}

Bishop::~Bishop()
{
}
