#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef QUEEN_HPP_INCLUDED
#define QUEEN_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

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

class Queen : public Piece
{
  public:
    Queen(bool, int, int);
    ~Queen();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
    bool IsMovementPossible(int, int);
};

#endif
