#include "../include/Board.hpp"

Board::Board(void)
{
    initBoard();
    // king = new King();
    // knight = new Knight();
    // pawn = new Pawn();
    // piece = new Piece();
    // queen = new Queen();
    // rook = new Rook();

    // Alocar as peças para o jogo neste construtor
}

Board::~Board()
{
    destroyBoard();
    // delete king;
    // delete knight;
    // delete pawn;
    // delete piece;
    // delete queen;
    // delete rook;
    // Chamar destrutores das peças neste destrutor
}

void Board::initBoard(void)
{
    board[8][8] =
    't', 'c', 'b', 'k', 'q', 'b', 'c', 't',
    'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
    't', 'c', 'b', 'q', 'k', 'b', 'c', 't';
}

void Board::destroyBoard(void)
{
    board[8][8] =
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0';
}

char Board::returnPiece(int x, int y)
{
    return board[x][y];
}