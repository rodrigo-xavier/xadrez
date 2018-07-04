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

bool States::IsCheck(bool kingColor, int position_X, int position_Y)
{
  Piece ** aux;
  kingColor ? aux = black_pieces : aux = white_pieces;

  for(int i = 0; i<16; i++)
  {
    SetPawnDiagonalEnemies(true, aux[i], position_X, position_Y); //Bota os inimigos laterais do peão
    if(aux[i]->IsMovementPossible(position_X, position_Y) &&
    (IsInTheWay(position_X, position_Y, aux[i]) == Obstacles::Empty))  //Verifica se os inimigos podem ir até o Rei, e se o caminho para ir para o Rei está livre.
      return true;
    SetPawnDiagonalEnemies(false, aux[i], -1, -1); //Remove os inimigos diagonais do peão
  }

  return false;
}

bool States::MovePiece(Piece * piece, int position_X, int position_Y)
{
  SetPawnDiagonalEnemies(true, piece, -1, -1); //Bota os inimigos laterais do peão
  Obstacles isIntheSpot = IsInTheSpot(position_X, position_Y, piece);
  if(piece->IsMovementPossible(position_X, position_Y) &&
  (IsInTheWay(position_X, position_Y, piece) == Obstacles::Empty) &&
  (isIntheSpot != Obstacles::Friend))
  {
    SetPawnDiagonalEnemies(false, piece, -1, -1); //Remove os inimigos diagonais do peão

    if(piece->GetName() == PieceName::King)
      if(IsCheck(piece->GetColor(), position_X, position_Y))
        return false;

    if(piece->GetName() == PieceName::Pawn)  //Caso tenha um inimigo na frete do peao, e ele esteja tentando ir pra frente (nao pode comer nem andar)
      if(isIntheSpot == Obstacles::Enemy && (position_X - piece->GetPositionX() == 0))
        return false;

    if(isIntheSpot == Obstacles::Enemy)
      EatPiece(position_X, position_Y);

    piece->SetPosition(position_X, position_Y);

    return true;
  }
  SetPawnDiagonalEnemies(false, piece, -1, -1); //Remove os inimigos diagonais do peão
  return false;
}

void States::EatPiece(int position_X, int position_Y)
{
  Piece ** aux;
  int i, j;
  aux = white_pieces;
  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 16; j++)
    {
      if((aux[j]->GetPositionX() == position_X) && (aux[j]->GetPositionY() == position_Y))
      {
        aux[j]->SetDead();
      }
    }
    aux = black_pieces;
  }
}

void States::SetPawnDiagonalEnemies(bool check, Piece * piece, int futureEnemyX, int futureEnemyY)
{
  int i, verticalDirection, horizontalDirection;
  bool left = false, right = false;

  if(piece->GetName() == PieceName::Pawn)
  {
    if(check)
    {
      piece->GetColor() ? (verticalDirection = (piece->GetPositionY() - 1)) : (verticalDirection = (piece->GetPositionY() + 1));
      horizontalDirection = (piece->GetPositionX() + 1);
      for(i = 0; i < 2; i++)
      {
        if(IsInTheSpot(horizontalDirection, verticalDirection, piece) == Obstacles::Enemy)
          (i == 0) ? (piece->GetColor() ? right = true : left = true) : (piece->GetColor() ? left = true : right = true);

        horizontalDirection = (piece->GetPositionX() -1);
      }

      if((abs(futureEnemyX - piece->GetPositionX()) == 1) && (abs(futureEnemyY - piece->GetPositionY()) == 1) && (futureEnemyX != -1) && (futureEnemyY != -1))
      {
        piece->GetColor() ? ((futureEnemyX - piece->GetPositionX()) == 1 ? right = true : left = true) : ((futureEnemyX - piece->GetPositionX()) == -1 ? right = true : left = true);
      }
    }
    piece->SetDiagonalEnemy(left, right);
  }
}

bool States::IsCheckMate(bool kingColor)
{
  Piece ** aux;
  Piece ** aux2;
  int i, j, k, x, y;

  if(kingColor)
  {
    aux = white_pieces;
    aux2 = black_pieces;
  }
  else
  {
    aux = black_pieces;
    aux2 = white_pieces;
  }

  if(IsCheck(aux[12]->GetColor(), aux[12]->GetPositionX(), aux[12]->GetPositionY()))
  {
    x = aux[12]->GetPositionX();
    y = aux[12]->GetPositionY();

  //Movimentos possíveis do Rei
    for(i=-1;i<2;i++)
      for(j=-1;j<2;j++)
        for(k = 0; k < 16; k++)
          if(!IsCheck(kingColor, x+i, y+j) && IsInTheSpot(x+i,y+j,aux[12]) != Obstacles::Friend &&
          (!aux2[k]->IsMovementPossible(x+i,y+j) || IsInTheWay(x+i, y+j, aux2[k]) != Obstacles::Empty) &&
          aux[12]->IsMovementPossible(x+i,y+j))
            return false;

    return true;
  }
  return false;
}

GameResult States::WhoWon(void)
{
  bool white = false, black = false;
  int i;

  white = IsCheckMate(true);
  black = IsCheckMate(false);

  if(white && black)
    return GameResult::Draw;

  if(!white && !black)
  {
    for(i = 0; i < 16; i++)
    {
      if((white_pieces[i]->GetIsAlive() && (white_pieces[i]->GetName() != PieceName::King)) || (black_pieces[i]->GetIsAlive() && (black_pieces[i]->GetName() != PieceName::King)))
        return GameResult::NoContest;
    }
    return GameResult::Draw;
  }

  if(white)
    return GameResult::BlackWins;

  if(black)
    return GameResult::WhiteWins;

  return GameResult::NoContest;
}

bool States::IsPositionValid(Piece * piece, int position_X, int position_Y)
{
  if(piece->GetName() == PieceName :: King)
  {
    if(IsCheck(piece->GetColor(), position_X, position_Y))
      return false;
  }
  if(piece->IsMovementPossible(position_X, position_Y) &&
    (IsInTheWay(position_X, position_Y, piece) == Obstacles::Empty) &&
    (IsInTheSpot(position_X, position_Y, piece) != Obstacles::Friend))
      return true;

  return false;
}
