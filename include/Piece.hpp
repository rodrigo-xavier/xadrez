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
    bool isWhite = false;     //Define a cor da peça. OBS: Peças brancas que inicializam o jogo.
    int position_X = 0;   //Define a posição da peça no eixo X.
    int position_Y = 0;   //Define a posição da peça no eixo Y.

  public:
    Piece();
    virtual ~Piece();
    virtual bool GetColor();        //Retorna true se for branca, false caso seja preta.
    virtual PieceName GetName();   //Retorna o nome da peça (identificado por um enum).
    virtual int GetPositionX();    //Retorna a posição X.
    virtual int GetPositionY();    //Retorna a posição Y.
    virtual bool IsMovementPossible(int *matrix, int row_size, int column_size); //Retorna true caso movimento seja possivel, falso caso contrario.
};

#endif
