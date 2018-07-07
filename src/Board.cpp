#include "../include/Board.hpp"

Board::Board(void)
{
    states = new States();
}

Board::~Board()
{
    delete states;
    destroy_board();
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

void Board::update_board(States *states)
{
    int i, j;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            piece = states->GetPiece(i,j);
            color = piece->GetColor();
            switch (piece->GetName())
            {
                case PieceName::Empty:
                insert_piece(i, j, '0');
                break;
                case PieceName::Pawn:
                color ? insert_piece(i, j, 'p') : insert_piece(i, j, 'P');
                break;
                case PieceName::Knight:
                color ? insert_piece(i, j, 'c') : insert_piece(i, j, 'C');
                break;
                case PieceName::Bishop:
                color ? insert_piece(i, j, 'b') : insert_piece(i, j, 'B');
                break;
                case PieceName::Rook:
                color ? insert_piece(i, j, 'r') : insert_piece(i, j, 'R');
                break;
                case PieceName::Queen:
                color ? insert_piece(i, j, 'q') : insert_piece(i, j, 'Q');
                break;
                case PieceName::King:
                color ? insert_piece(i, j, 'k') : insert_piece(i, j, 'K');
                break;
            }
        }
    }
}