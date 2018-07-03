#include "../include/Board.hpp"

Board::Board(void)
{
}

Board::~Board()
{
    destroyBoard();
}

void Board::destroyBoard()
{
    int i, j;
    
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            board[i][j] = '0';
}

char Board::returnPiece(int x, int y)
{
    return board[x][y];
}