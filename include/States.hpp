#ifndef STATES_HPP_INCLUDED
#define STATES_HPP_INCLUDED

#include "Piece.hpp"

enum class Obstacles{Empty,Friend,Enemy};
enum class GameResult{WhiteWins,BlackWins,Draw,NoContest};

class States
{
public:
  Piece * white_pieces[16];
  Piece * black_pieces[16];
  States();
  Obstacles IsInTheWay(Piece *, int, int);
  Obstacles IsInTheSpot(Piece *, int, int);
  bool IsCheck(bool, int, int);
  bool MovePiece(Piece *, int, int);  //Move a peça apenas se for possivel, retornando true quando possivel e false caso contrario (podendo comer uma peça quando uma inimiga estiver na casa final)
  void EatPiece(int, int);    //Mata a peça da posição x, y.
  void SetPawnDiagonalEnemies(bool, Piece *, int, int);  //Se true, ele checa se ha inimigos e seta as flags, se false ele bota false nas flags de inimigo nas diagonais.
  bool IsCheckMate(bool);
  GameResult WhoWon(void);
  bool IsPositionValid(Piece *, int, int);  //Função que passa a peça, e uma posição x e y. A função retorna se o movimento é possivel para a peça, para aquela posição.
};

#endif
