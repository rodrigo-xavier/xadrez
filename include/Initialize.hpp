#include <iostream>
#include <string>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Board.hpp"

class Initialize : public Piece
{
public:
  Piece * white_pieces[16];
  Piece * black_pieces[16];
  using Piece::Piece;
  Initialize();

};
