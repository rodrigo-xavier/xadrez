#include "../include/Piece.hpp"

Piece::Piece()
{
}

Piece::~Piece()
{
}

bool Piece::GetColor()
{
  return isWhite;
}

PieceName Piece::GetName()
{
  return name;
}

int Piece::GetPositionX()
{
  return position_X;
}

int Piece::GetPositionY()
{
  return position_Y;
}

bool Piece::IsMovementPossible(int *matrix, int row_size, int column_size)
{
  return false;
}
