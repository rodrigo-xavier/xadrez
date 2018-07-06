#include "../include/Board.hpp"

Board::Board(void)
{
}

Board::~Board()
{
}

void Board::destroy_board()
{
    int i, j;
    
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            board[i][j] = '0';
}

char Board::return_piece(int x, int y)
{
    return board[x][y];
}

void Board::insert_piece(int x, int y, char c)
{
    board[x][y] = c;
}

