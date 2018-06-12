#include "../Headers/Test_Piece.hpp"

const bool Test_Piece::FALHA = false;
const bool Test_Piece::SUCESSO = true;
bool Test_Piece::estado = SUCESSO;

bool Test_Piece::run(void)
{

    return estado;
}
