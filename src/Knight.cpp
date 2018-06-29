#include "../include/Knight.hpp"

Knight::Knight(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Knight;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
}

Knight::~Knight()
{
}
