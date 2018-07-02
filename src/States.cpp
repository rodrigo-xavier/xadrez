#include "../include/Piece.hpp"
#include "../include/Pawn.hpp"
#include "../include/Knight.hpp"
#include "../include/Bishop.hpp"
#include "../include/Rook.hpp"
#include "../include/Queen.hpp"
#include "../include/King.hpp"
#include "../include/Board.hpp"
#include "../include/States.hpp"

States::States(void)
{
  int i;

//Inicialização dos peões
  for(i=0;i<=7;i++)
  {
    white_pieces[i] = new Pawn(true, i, 6);
    black_pieces[i] = new Pawn(false, i, 1);
  }


//Inicialização das peças brancas
  white_pieces[8]  = new Rook(true, 0, 7);
  white_pieces[9]  = new Knight(true, 1, 7);
  white_pieces[10] = new Bishop(true, 2, 7);
  white_pieces[11] = new Queen(true, 3, 7);
  white_pieces[12] = new King(true, 4, 7);
  white_pieces[13] = new Bishop(true, 5, 7);
  white_pieces[14] = new Knight(true, 6, 7);
  white_pieces[15] = new Rook(true, 7, 7);

//Inicialização das peças pretas
  black_pieces[8]  = new Rook(false, 0, 0);
  black_pieces[9]  = new Knight(false, 1, 0);
  black_pieces[10] = new Bishop(false, 2, 0);
  black_pieces[11] = new Queen(false, 3, 0);
  black_pieces[12] = new King(false, 4, 0);
  black_pieces[13] = new Bishop(false, 5, 0);
  black_pieces[14] = new Knight(false, 6, 0);
  black_pieces[15] = new Rook(false, 7, 0);

}

Obstacles States::IsInTheWay(int position_X, int position_Y, Piece * piece)
{
  int i,j;
  Piece ** aux;

  switch(piece->GetName())
  {
    case PieceName::Knight :
      return Obstacles::Empty;
      break;

    default:
      int displacement_x = position_X-piece->GetPositionX();
      int displacement_y = position_Y-piece->GetPositionY();
      int displacement_loop, vertical, horizontal;

      for(i=0;i<=15;i++)
      {
        aux = white_pieces;
        for(j=0;j<=1;j++)
        {
          displacement_loop = 0;
          vertical = 0;
          horizontal = 0;

          displacement_x != 0 ? displacement_loop = displacement_x : displacement_loop = displacement_y;
          displacement_loop = abs(displacement_loop);

          while(displacement_loop > 1)
          {
            if(abs(displacement_x) != abs(displacement_y))
            {
              displacement_y > 0 ? vertical++ : (displacement_y != 0 ? vertical-- : vertical = 0);
              displacement_x > 0 ? horizontal++ : (displacement_x != 0 ? horizontal-- : horizontal = 0);
            }
            else
            {
              displacement_y > 0 ? vertical++ : (displacement_y != 0 ? vertical-- : vertical = 0);
              displacement_x > 0 ? horizontal++ : (displacement_x != 0 ? horizontal-- : horizontal = 0);
            }

            if((aux[i]->GetPositionX() == (piece->GetPositionX() + horizontal)) &&
               (aux[i]->GetPositionY() == (piece->GetPositionY() + vertical)))
            {
              if((piece->GetColor() && aux[i]->GetColor()) || (!piece->GetColor() && !aux[i]->GetColor()))
              {
                return Obstacles::Friend;
              }
              else
              {
                return Obstacles::Enemy;
              }
            }
            displacement_loop--;
          }
          aux = black_pieces;
        }
      }
      return Obstacles::Empty;
      break;
  }
}

Obstacles States::IsInTheSpot(int position_X, int position_Y, Piece * piece)
{
  int i,j;
  Piece ** aux;

  for(i=0;i<=15;i++)
  {
    aux = white_pieces;
    for(j=0;j<=1;j++)
    {
      if((aux[i]->GetPositionX() == position_X) && (aux[i]->GetPositionY() == position_Y))
      {
        if((piece->GetColor() && aux[i]->GetColor()) || (!piece->GetColor() && !aux[i]->GetColor()))
        {
          return Obstacles::Friend;
        }
        else
        {
          return Obstacles::Enemy;
        }
      }
      aux = black_pieces;
    }
  }
  return Obstacles::Empty;
}
