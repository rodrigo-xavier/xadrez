#include "../Headers/Test_Piece.hpp"

const bool Test_Piece::FALHA = false;
const bool Test_Piece::SUCESSO = true;

void Test_Piece::makePiece(void)
{
    try
    {
        piece = new Piece();
    }
    catch (invalid_argument excecao)
    {
        estado = FALHA;
    }
}

void Test_Piece::destroyPiece(void)
{
    try
    {
        piece = new Piece();
    }
    catch (invalid_argument excecao)
    {
        estado = FALHA;
    }
}

bool Test_Piece::run(void)
{
    estado = SUCESSO;

    makePiece();
    destroyPiece();

    return estado;
}
