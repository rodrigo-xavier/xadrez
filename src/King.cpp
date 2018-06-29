#include "../include/King.hpp"

King::King(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::King;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
}

King::~King()
{
}
