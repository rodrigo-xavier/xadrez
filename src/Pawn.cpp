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

bool Pawn::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  if(FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8)  //Assertivas de entrada, X e Y precisam ser positivos e maiores ou iguais a zero e menores que 8 (para estarem no tabuleiro).
  {
    //Calculo do deslocamento entre a posição da peça e a nova jogada
    int movement_x = FinalPosition_X - position_X;
    int movement_y = FinalPosition_Y - position_Y;

    if(movement_x == 0 || (movement_x == -1 && hasDiagonalEnemyLeft) || (movement_x == 1 && hasDiagonalEnemyRight)) //Checa se Peao pode comer na diagonal
    {
      if((isWhite && movement_y > 0) || (!isWhite && movement_y < 0)) //Impede do Peao andar para trás.
      {
        movement_y = abs(movement_y);
        if(movement_y == 2 && movement_x == 0) //Andar duas vezes (não pode fazer isso caso esteja 'comendo' uma peça na diagonal)
        {
          if(isWhite && position_Y == 1) //Checa se é branca e se é a primeira jogada
          {
            return true;
          }

          if(!isWhite && position_Y == 6) //Checa se é preta e se é a primeira jogada
          {
            return true;
          }

          return false; //Caso não seja a primeira jogada, não se pode andar duas vezes.
        }

        if(movement_y == 1) //Andar apenas uma casa
        {
          return true;
        }
      }
    }
  }

  return false;
}

void Pawn::SetDiagonalEnemy(bool hasDiagonalEnemyLeft, bool hasDiagonalEnemyRight)
{
  if(isWhite)
  {
    this->hasDiagonalEnemyRight = hasDiagonalEnemyLeft;
    this->hasDiagonalEnemyLeft = hasDiagonalEnemyRight;
  }
  else
  {
    this->hasDiagonalEnemyRight = hasDiagonalEnemyRight;
    this->hasDiagonalEnemyLeft = hasDiagonalEnemyLeft;
  }

}
