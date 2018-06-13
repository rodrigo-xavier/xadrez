#include "../Headers/Test_Piece.hpp"

const bool Test_Piece::FALHA = false;
const bool Test_Piece::SUCESSO = true;

void Test_Piece::makePiece(void)
{
    try
    {
        piece = new Piece();

        if (piece == NULL)
            estado = FALHA;
    }
    catch (bad_alloc &bad_allocation)
    {
        cerr << "Falha de alocacao causada por: " << bad_allocation.what() << '\n';
        estado = FALHA;
    }
}

void Test_Piece::destroyPiece(void)
{
    try
    {
        delete piece;
        piece = NULL;

        if (piece != NULL)
            estado = FALHA;
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
