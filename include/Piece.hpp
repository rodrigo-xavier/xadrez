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
    int position_X = -1;   //Define a posição da peça no eixo X.
    int position_Y = -1;   //Define a posição da peça no eixo Y.
    bool isAlive = false; //True - peça está viva, False - peça está morta

  public:
    Piece();
    ~Piece();
    bool GetColor();       //Retorna true se for branca, false caso seja preta.
    PieceName GetName();   //Retorna o nome da peça (identificado por um enum).
    int GetPositionX();    //Retorna a posição X.
    int GetPositionY();    //Retorna a posição Y.
    virtual bool IsMovementPossible(int, int); //Retorna true caso movimento seja possivel, falso caso contrario.
    virtual void SetDiagonalEnemy(bool, bool); //Seta variável privada do peão.
    bool SetPosition(int, int); //Seta a posição X e Y da peça respectivamente. Retorna verdadeiro caso movimento seja possível e a posição foi alterada, e falso caso contrario (falso - posição não é alterada.)
    bool GetIsAlive();    //Retorna True - peça viva / False - Peça morta
    void SetDead();       //Seta a flag isAlive para morta. Quando morta, a peça não revive e sua posição vira -1x-1
};

#endif
