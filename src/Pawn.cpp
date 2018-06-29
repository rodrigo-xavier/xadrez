#include "../include/Pawn.hpp"

Pawn::Pawn(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Pawn;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
}

Pawn::~Pawn()
{
}
