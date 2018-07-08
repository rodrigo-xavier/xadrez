#include "Piece.hpp"
#include "States.hpp"
#include "common.hpp"

#ifndef GUIBOARD_HPP
#define GUIBOARD_HPP

class GUIBoard{
    public:
        GUIBoard(void);
        void updateFocus(int x, int y); //atualiza posicao clicada
        int indexToPixel(int index); //A partir de um indice (casa) retorna a posicao em pixels do tabuleiro
        //cor = 0 = branca, cor = 1 = preta
        void renderPieceOnBoard(PieceName piece, int cor, int ix, int iy); //renderiza peça no indice do tabuleiro
        void renderAllPieces(States* states);
        bool checkMovement(States* states); //checa se ouve alguma jogada, condicao: usa movePiece se a ultima peça clicada não for vazia
        void renderPossibleMoves(States *states);
        void renderBestMove(States *states);


        SDL_Rect board[8][8]; //matriz de retangulos (tabuleiro)
        SDL_Point focus = {-1,-1}; //posicao clicada
        Piece *focusedPiece = NULL; //ultima peça clicada
};

#endif
