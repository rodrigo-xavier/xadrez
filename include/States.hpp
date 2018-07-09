#ifndef STATES_HPP_INCLUDED
#define STATES_HPP_INCLUDED

#include "Piece.hpp"
#include "GameState.hpp"


enum class Obstacles{Empty,Friend,Enemy};
enum class GameResult{WhiteWins,BlackWins,Draw,NoContest};
enum class Level{Easy, Medium, Hard};

struct PiecesValues
{
  int max_Value_X = -1;
  int max_Value_Y = -1;
  int value = -20;
};

/**@brief Classe que define estados para uma peça
*
*Descrição: Nesta classe estão definidos os mecanismos do jogo de xadrez
*Como transformar um peão em rainha, comer uma peça, validar se é cheque mate
*Verificar quem venceu o jogo, salvar o jogo, carregar o jogo, validar quem foi o
*vencedor da partida, entre outros métodos, aqui basicamente está definida toda a
*lógica do jogo de xadrez, sendo assim uma das classes mais importantes deste código
*
*
*/

class States
{
  private:
    void SetPawnDiagonalEnemies(bool, Piece *, int, int);  //Se true, ele checa se ha inimigos e seta as flags, se false ele bota false nas flags de inimigo nas diagonais.
    void EatPiece(int, int);    //Mata a peça da posição x, y.
    bool pieceTurn;  //True - vez da branca, False - vez da preta.
    void TransformPawn(Piece * piece);
    Piece * emptyPiece = new Piece();

  public:
    //Vetor que guarda as melhores jogadas de cada peça:
    PiecesValues white_values[16];
    PiecesValues black_values[16];
    //Vetor de peças do tabuleiro:
    Piece * white_pieces[16];
    Piece * black_pieces[16];
    States();
    Obstacles IsInTheWay(Piece *, int, int);
    Obstacles IsInTheSpot(Piece *, int, int);
    bool IsCheck(bool, int, int);
    bool MovePiece(Piece *, int, int);  //Move a peça apenas se for possivel, retornando true quando possivel e false caso contrario (podendo comer uma peça quando uma inimiga estiver na casa final)
    bool IsCheckMate(bool);
    GameResult WhoWon(void);
    bool IsPositionValid(Piece *, int, int);  //Função que passa a peça, e uma posição x e y. A função retorna se o movimento é possivel para a peça, para aquela posição.
    Piece * GetPiece(int, int); //Função que recebe uma posição X e uma Y, e retorna a peça daquela posição (retorna peça vazia caso não tenha peça na posição).
    bool SetPiece(Piece *, int, int); //Função que seta a peça em uma posição X,Y, retorna true se a peça foi colocada la e false caso não tenha sido (pois o local já continha outra peça ou estava fora do tabuleiro).
    void PlayBestMove(bool, Level);   //Função que joga o melhor movimento da cor da peça passado para ela (de acordo com Level de dificultade. dificil, medio, facil).
    void UpdateBestMoves(void); //Função que atualiza os melhores movimentos para as peças brancas e pretas.
    void SetPieceTurn(bool);  //Seta a vez da peça que vai jogar (para a função de Load)
    bool GetPieceTurn(void);
    void SaveGame(GameMode); //Salva o jogo em um arquivo PGN de acordo com o modo de jogo.
    void LoadGame(GameMode); //Faz o load do arquivo PGN para o jogo.
    PiecesValues GetPieceBestMove(Piece *);  //Função recebe uma peça e retorna a melhor jogada para a peça. Caso retorne uma posição x,y -1 e -1, a peça não pode mover (não há jogadas pra ela)
    void KillAllPieces(void);
};

#endif
