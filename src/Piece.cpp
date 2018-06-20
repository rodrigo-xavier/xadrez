#include "../include/Piece.hpp"

Piece::Piece(void)
{
}

Piece::~Piece()
{
}

bool Piece::GetColor()
{
  return false;
}

int Piece::GetName()
{
  return 1;
}

int * Piece::GetPosition()
{
  int *a;
  a = (int *) malloc(2*sizeof(int));
  a[0] = 0;
  a[1] = 0;
  return a;
}

bool Piece::IsMovementPossible(int *matrix, int row_size, int column_size)
{
  return false;
}
