#ifndef PIECE_HPP_INCLUDED
#define PIECE_HPP_INCLUDED

#include <iostream>
#include <string>

enum class PieceName { Empty,Pawn,Knight,Bishop,Rook,Queen,King};

using namespace std;

class Piece
{
  protected:
    PieceName name = PieceName::Empty; //Define qual é a peça, de acordo com um enumerador.
    bool isWhite = false;     //Define a cor da peça. OBS: Peças brancas que inicializam o jogo e que ficam em cima (posição 0x0 etc...).
    int position_X = 0;   //Define a posição da peça no eixo X.
    int position_Y = 0;   //Define a posição da peça no eixo Y.

  public:
    Piece();
    ~Piece();
    bool GetColor();       //Retorna true se for branca, false caso seja preta.
    PieceName GetName();   //Retorna o nome da peça (identificado por um enum).
    int GetPositionX();    //Retorna a posição X.
    int GetPositionY();    //Retorna a posição Y.
    virtual bool IsMovementPossible(int, int); //Retorna true caso movimento seja possivel, falso caso contrario.
    virtual void SetDiagonalEnemy(bool, bool);  //Seta variável privada do peão.
};

#endif
