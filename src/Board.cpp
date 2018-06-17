#include "../include/Board.hpp"

Board::Board(void)
{
    int i = 0;

    matrix = new Piece *[LINHAS];

    for (i = 0; i < LINHAS; i++)
        matrix[i] = new Piece[COLUNAS];

    // Alocar as peças para o jogo neste construtor
}

Board::~Board()
{
    int i = 0;

    for (i = 0; i < LINHAS; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;

    // Chamar destrutores das peças neste destrutor
}

int soma(int a, int b){
    return a+b;
}
