#include "../include/Board.hpp"

Board::Board(void)
{
    initBoard();
    // Alocar as peças para o jogo neste construtor
}

Board::~Board()
{
    destroyBoard();
    // Chamar destrutores das peças neste destrutor
}

void Board::initBoard(void)
{
    board[8][8] =
        't',
    'c', 'b', 'k', 'q', 'b', 'c', 't',
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
        '0',
    '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0';
}

char Board::returnBoardPosition(int x, int y)
{
    return board[x][y];
}