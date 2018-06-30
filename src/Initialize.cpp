#include "../lib/catch.hpp"
#include "../include/Piece.hpp"
#include "../include/Pawn.hpp"
#include "../include/Knight.hpp"
#include "../include/Bishop.hpp"
#include "../include/Rook.hpp"
#include "../include/Queen.hpp"
#include "../include/King.hpp"
#include "../include/Board.hpp"
#include "../include/Initialize.hpp"

Initialize::Initialize(void)
{

Rook * black_rook1 = new Rook(false, 0, 0);
Knight * black_knight1 = new Knight(false, 0, 1);
Bishop * black_bishop1 = new Bishop(false, 0, 2);
Queen * black_queen = new Queen(false, 0, 3);
King * black_king = new King(false, 0, 4);
Bishop * black_bishop2 = new Bishop(false, 0, 5);
Knight * black_knight2 = new Knight(false, 0, 6);
Rook * black_rook2 = new Rook(false, 0, 7);

Pawn * black_pawn1 = new Pawn(false, 1, 0);
Pawn * black_pawn2 = new Pawn(false, 1, 1);
Pawn * black_pawn3 = new Pawn(false, 1, 2);
Pawn * black_pawn4 = new Pawn(false, 1, 3);
Pawn * black_pawn5 = new Pawn(false, 1, 4);
Pawn * black_pawn6 = new Pawn(false, 1, 5);
Pawn * black_pawn7 = new Pawn(false, 1, 6);
Pawn * black_pawn8 = new Pawn(false, 1, 7);

Pawn * white_pawn1 = new Pawn(true, 6, 0);
Pawn * white_pawn2 = new Pawn(true, 6, 1);
Pawn * white_pawn3 = new Pawn(true, 6, 2);
Pawn * white_pawn4 = new Pawn(true, 6, 3);
Pawn * white_pawn5 = new Pawn(true, 6, 4);
Pawn * white_pawn6 = new Pawn(true, 6, 5);
Pawn * white_pawn7 = new Pawn(true, 6, 6);
Pawn * white_pawn8 = new Pawn(true, 6, 7);

Rook * white_rook1 = new Rook(true, 7, 0);
Knight * white_knight1 = new Knight(true, 7, 1);
Bishop * white_bishop1 = new Bishop(true, 7, 2);
Queen * white_queen = new Queen(true, 7, 3);
King * white_king = new King(true, 7, 4);
Bishop * white_bishop2 = new Bishop(true, 7, 5);
Knight * white_knight2 = new Knight(true, 7, 6);
Rook * white_rook2 = new Rook(true, 7, 7);

}
