#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif

#ifndef PAWN_HPP_INCLUDED
#define PAWN_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**@brief Classe do Peão que herda de Piece
*
*Parâmetros: Construtor e destrutor de Peão, IsMovementPossible e
*funções herdadas de Piece como GetColor, GetName, GetPositionX, GetPositionY
*
*Descrição: Esta classe define o Peão em um jogo de Xadrez padrão, aqui são 
*definidos alguns dos métodos básicos para manipular um objeto dessa classe, 
*como o método de construir e destruir um objeto desta classe, um método para
*retornar sua cor, seu nome e sua posição no tabuleiro e outro para validar se a
*jogada é possível
*
*/

class Pawn : public Piece
{
  private:
    bool hasDiagonalEnemyRight = false;
    bool hasDiagonalEnemyLeft = false;

  public:
    Pawn(bool, int, int);
    ~Pawn();
    using Piece::GetColor;
    using Piece::GetName;
    using Piece::GetPositionX;
    using Piece::GetPositionY;
    bool IsMovementPossible(int, int);
    void SetDiagonalEnemy(bool, bool);
};

#endif
