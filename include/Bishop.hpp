#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef BISHOP_HPP_INCLUDED
#define BISHOP_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**@brief Classe do Bispo que herda de Piece
*
*Parâmetros: Construtor e destrutor de Bispo, IsMovementPossible e
*funções herdadas de Piece como GetColor, GetName, GetPositionX, GetPositionY
*
*Descrição: Esta classe define o bispo em um jogo de Xadrez padrão, aqui são 
*definidos alguns dos métodos básicos para manipular um objeto dessa classe, 
*como o método de construir e destruir um objeto desta classe, um método para
*retornar sua cor, seu nome e sua posição no tabuleiro e outro para validar se a
*jogada é possível
*
*/

class Bishop : public Piece
{
  public:
    Bishop(bool, int, int);
    ~Bishop();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
    bool IsMovementPossible(int, int);
};

#endif
