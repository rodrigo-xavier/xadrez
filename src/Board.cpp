#include "../include/Board.hpp"

Board::Board(void)
{
    pieces = new Initialize();
}

Board::~Board()
{
    destroyBoard();
    delete pieces;
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

void Board::update_board(void)
{
    int x, y, i;
    char c;

    for(i = 0; i < 16; i++)
    {
        x = pieces->black_pieces[i]->GetPositionX();
        y = pieces->black_pieces[i]->GetPositionY();
        name = pieces->black_pieces[i]->GetName();

        insert_piece(x, y, c);

        x = pieces->white_pieces[i]->GetPositionX();
        y = pieces->white_pieces[i]->GetPositionY();
        name = pieces->white_pieces[i]->GetName();

        insert_piece(x, y, c);
    }
}