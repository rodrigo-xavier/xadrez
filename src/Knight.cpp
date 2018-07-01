#include "../include/Knight.hpp"

Knight::Knight(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Knight;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
  isAlive = true;
}

Knight::~Knight()
{
}

bool Knight::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  if(FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8) //Peça tem que estar no tabuleiro
  {
    int movement_x = abs(FinalPosition_X - position_X);
    int movement_y = abs(FinalPosition_Y - position_Y);

    if((movement_x == 1 && movement_y == 2) || (movement_x == 2 && movement_y == 1)) //Movimento em 'L' e posição final diferente da inicial
    {
      return true;
    }
  }

  return false;
}
