#include "../include/GUIBoard.hpp"

GUIBoard::GUIBoard(){
    int i=0, j=0;
    for(i = 0 ; i < 8 ; i++){
        for(j = 0 ; j < 8 ; j++){
            board[i][j].x = 20 + i*80;
            board[i][j].y = 20 + j*80;
            board[i][j].h = 80;
            board[i][j].w = 80;
        }
    }
}

void GUIBoard::updateFocus(int x, int y){

    //Fora das extremidades do tabuleiro
    if((x < 20) || (y < 20) || (x>660) || (y>660) ){
        focus.x = -1;
        focus.y = -1;
        return;
    } else{

        focus.x = (int) (x-20)/80;
        focus.y = (int) (y-20)/80;
    }
}

int GUIBoard::indexToPixel(int index){

    if((index < 0) || (index > 7)){
        printf("Indice invalido");
        return -1;
    }

    return (index * 80 + 20);

}

void GUIBoard::renderPieceOnBoard(PieceName piece, int cor, int ix, int iy){

    if(ix < 0 || iy < 0){
        return;
    }

    if(cor == 0){
        whitePieces[(int) piece].render(indexToPixel(ix), indexToPixel(iy));
    } else{
        blackPieces[(int) piece].render(indexToPixel(ix), indexToPixel(iy));
    }
}

void GUIBoard::renderAllPieces(States* states){
    int i = 0;
    //Renderiza brancas
    for(i = 0 ; i < 16 ; i++){
        renderPieceOnBoard(states->white_pieces[i]->GetName(), 0, states->white_pieces[i]->GetPositionX(), states->white_pieces[i]->GetPositionY());
    }

    //renderiza as pretas
    for(i = 0 ; i < 16 ; i++){
        renderPieceOnBoard(states->black_pieces[i]->GetName(), 1, states->black_pieces[i]->GetPositionX(), states->black_pieces[i]->GetPositionY());
    }
}

bool GUIBoard::checkMovement(States* states){
    bool move = false;
    if(focusedPiece != NULL){
        if(focusedPiece->GetName() != PieceName::Empty){
            move = states->MovePiece(focusedPiece,focus.x,focus.y);
        }
    }
    return move;
}


void GUIBoard::renderPossibleMoves(States *states){
    int i = 0, j = 0;
    if(focusedPiece != NULL){
        if(focusedPiece->GetName() != PieceName::Empty){
            for(i = 0 ; i < 8 ; i++){
                for(j = 0 ; j < 8 ; j++){
                    if(states->IsPositionValid(focusedPiece,i,j))
                    {
                      casaVerde.render(indexToPixel(i),indexToPixel(j)+2);
                    }
                }
            }
        }

    }
}

void GUIBoard::renderBestMove(States *states){

    if(focusedPiece != NULL){
        if(focusedPiece->GetName() != PieceName::Empty){

            PiecesValues bestPosition = states->GetPieceBestMove(focusedPiece);
            if(bestPosition.max_Value_X < 0 || bestPosition.max_Value_Y < 0){
                return;
            }
            bestMove.render(indexToPixel(bestPosition.max_Value_X), indexToPixel(bestPosition.max_Value_Y)+2);
        }
    }
}


