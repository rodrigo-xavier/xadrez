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

bool Bishop::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  if(FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8)
  {
    int movement_x = abs(FinalPosition_X - position_X);
    int movement_y = abs(FinalPosition_Y - position_Y);

    if(movement_x == movement_y && movement_x > 0)
    {
      return true;
    }
  }

  return false;
}
