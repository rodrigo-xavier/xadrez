#include <iostream>
#include <string>
#include "Piece.hpp"

class Initialize : public Piece
{
public:
  Piece * white_pieces[16];
  Piece * black_pieces[16];
  using Piece::Piece;
  Initialize();

};
