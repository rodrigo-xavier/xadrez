#include "../include/Rook.hpp"

/**@brief Método que retorna um booleano indicando se o movimento é possível
*
*Parâmetros: 
*
*Tratamento de Erros:
*
*Descrição:
*
*Assertivas de entrada:
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida:
*
*Interface explicita:
*
*Interface implicita:
*
*Contrato na especificação: 
*
*/

Rook::Rook(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Rook;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
  isAlive = true;
  PieceValue = 5;
}

Rook::~Rook()
{
}

/**@brief Método que retorna um booleano indicando se o movimento é possível
*
*Parâmetros: 
*
*Tratamento de Erros:
*
*Descrição:
*
*Assertivas de entrada:
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida:
*
*Interface explicita:
*
*Interface implicita:
*
*Contrato na especificação: 
*
*/

bool Rook::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  if(FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8 && isAlive) //Peça tem que estar no tabuleiro e estar viva
  {
    int movement_x = abs(FinalPosition_X - position_X);
    int movement_y = abs(FinalPosition_Y - position_Y);

    if((movement_x == 0 || movement_y == 0) && movement_x != movement_y) //Movimento na vertical/horizontal apenas (não ambos) e posição final diferente da inicial
    {
      return true;
    }
  }

  return false;
}
