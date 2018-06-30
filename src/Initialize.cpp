#include "../lib/catch.hpp"
#include "../include/Piece.hpp"
#include "../include/Pawn.hpp"
#include "../include/Knight.hpp"
#include "../include/Bishop.hpp"
#include "../include/Rook.hpp"
#include "../include/Queen.hpp"
#include "../include/King.hpp"
#include "../include/Board.hpp"

Initialize::Initialize(void)
{

black_rook1 = new Rook(false, 0, 0);
black_knight1 = new Knight(false, 0, 1);
black_bishop1 = new Bishop(false, 0, 2);
black_queen = new Queen(false, 0, 3);
black_king = new King(false, 0, 4);
black_bishop2 = new Bishop(false, 0, 5);
black_knight2 = new Knight(false, 0, 6);
black_rook2 = new Rook(false, 0, 7);

black_pawn1 = new Pawn(false, 1, 0);
black_pawn2 = new Pawn(false, 1, 1);
black_pawn3 = new Pawn(false, 1, 2);
black_pawn4 = new Pawn(false, 1, 3);
black_pawn5 = new Pawn(false, 1, 4);
black_pawn6 = new Pawn(false, 1, 5);
black_pawn7 = new Pawn(false, 1, 6);
black_pawn8 = new Pawn(false, 1, 7);

white_pawn1 = new Pawn(true, 6, 0);
white_pawn2 = new Pawn(true, 6, 1);
white_pawn3 = new Pawn(true, 6, 2);
white_pawn4 = new Pawn(true, 6, 3);
white_pawn5 = new Pawn(true, 6, 4);
white_pawn6 = new Pawn(true, 6, 5);
white_pawn7 = new Pawn(true, 6, 6);
white_pawn8 = new Pawn(true, 6, 7);

white_rook1 = new Pawn(true, 7, 0);
white_knight1 = new Pawn(true, 7, 1);
white_bishop1 = new Pawn(true, 7, 2);
white_queen = new Pawn(true, 7, 3);
white_king = new Pawn(true, 7, 4);
white_bishop2 = new Pawn(true, 7, 5);
white_knight2 = new Pawn(true, 7, 6);
white_rook2 = new Pawn(true, 7, 7);

}
