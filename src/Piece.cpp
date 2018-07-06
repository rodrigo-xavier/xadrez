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

bool Piece::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  return false;
}

void Piece::SetDiagonalEnemy(bool hasDiagonalEnemyRight, bool hasDiagonalEnemyLeft)
{
}

void Piece::SetPosition(int position_X, int position_Y)
{
  if(isAlive)
  {
    this->position_X = position_X;
    this->position_Y = position_Y;
  }
}

bool Piece::GetIsAlive()
{
  return isAlive;
}

void Piece::SetDead()
{
  isAlive = false;
  this->position_X = -1;
  this->position_Y = -1;
}
