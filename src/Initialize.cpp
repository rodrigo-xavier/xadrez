#include "../include/Initialize.hpp"

Initialize::Initialize(void)
{
  int i;

//Inicialização dos peões
  for(i=0;i<=7;i++)
  {
    white_pieces[i] = new Pawn(true, 6, i);
    black_pieces[i] = new Pawn(false, 1, i);
  }


//Inicialização das peças brancas
  white_pieces[8]  = new Rook(true, 7, 0);
  white_pieces[9]  = new Knight(true, 7, 1);
  white_pieces[10] = new Bishop(true, 7, 2);
  white_pieces[11] = new Queen(true, 7, 3);
  white_pieces[12] = new King(true, 7, 4);
  white_pieces[13] = new Bishop(true, 7, 5);
  white_pieces[14] = new Knight(true, 7, 6);
  white_pieces[15] = new Rook(true, 7, 7);

//Inicialização das peças pretas
  black_pieces[8]  = new Rook(false, 0, 0);
  black_pieces[9]  = new Knight(false, 0, 1);
  black_pieces[10] = new Bishop(false, 0, 2);
  black_pieces[11] = new Queen(false, 0, 3);
  black_pieces[12] = new King(false, 0, 4);
  black_pieces[13] = new Bishop(false, 0, 5);
  black_pieces[14] = new Knight(false, 0, 6);
  black_pieces[15] = new Rook(false, 0, 7);

}
