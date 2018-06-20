#ifndef PIECE_HPP_INCLUDED
#define PIECE_HPP_INCLUDED

#include <iostream>
#include <string>

enum class PieceName { Pawn,Knight,Bishop,Rook,Queen,King};

using namespace std;

class Piece
{
  private:
    int name;         //Define qual é a peça, de acordo com um enumerador.
    bool isWhite;     //Define a cor da peça. OBS: Peças brancas que inicializam o jogo.
    int position_X;   //Define a posição da peça no eixo X.
    int position_Y;   //Define a posição da peça no eixo Y.

  public:
    Piece();
    virtual ~Piece();
    virtual bool GetColor();        //Retorna true se for branca, false caso seja preta.
    virtual int GetName();          //Retorna o nome da peça (identificado por um enum).
    virtual int * GetPosition();    //Retorna um vetor com a posição X no elemento 0 e Y no elemento 1.
    virtual bool IsMovementPossible(int *matrix, int row_size, int column_size); //Retorna true caso movimento seja possivel, falso caso contrario.
};

class Pawn : Piece
{
private:

public:
  Pawn();
  ~Pawn();
};

class Knight : Piece
{
private:

public:
  Knight();
  ~Knight();
};

class Bishop : Piece
{
private:

public:
  Bishop();
  ~Bishop();
};

class Rook : Piece
{
private:

public:
  Rook();
  ~Rook();
};

class Queen : Piece
{
private:

public:
  Queen();
  ~Queen();
};

class King : Piece
{
private:

public:
  King();
  ~King();
};

#endif
