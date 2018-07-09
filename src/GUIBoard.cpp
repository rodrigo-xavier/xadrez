#include "../include/GUIBoard.hpp"
#include "../include/GameState.hpp"

/**@brief Método que define o tamanho do tabuleiro e as posições das casas
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição: Este método percorre uma determinada quantidade de pixels 
*definindo o tamanho do tabuleiro e suas casas 
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: As casas são definidas dentro da imagem do tubleiro
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: A função deve definir corretamente as casas do tabuleiro
*
*/

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

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

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

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

int GUIBoard::indexToPixel(int index){

    if((index < 0) || (index > 7)){
        printf("Indice invalido");
        return -1;
    }

    return (index * 80 + 20);

}

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

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

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

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

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

bool GUIBoard::checkMovement(States* states){
    bool move = false;
    if(focusedPiece != NULL){
        if(focusedPiece->GetName() != PieceName::Empty){
            move = states->MovePiece(focusedPiece,focus.x,focus.y);
        }
    }
    return move;
}

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/


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

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

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

/**@brief 
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição:
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: 
*
*/

//escolhe qual lado começar
bool GUIBoard::choosePieceTurn(GameState *gm, States *states){
    bool selected = false;
    bool white = true;
    int x=-1,y=-1;
    SDL_Event e;

    while(selected == false){

        while(SDL_PollEvent(&e) != 0){
        
            //Usuario pede pra sair
            if( e.type == SDL_QUIT ) {
                gm->setGameState(GameMode::GAME_MODE_QUIT);
            } else if(e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION){
                switch(e.type){
                    case SDL_MOUSEBUTTONDOWN:
                        selected = true;
                        if(y > 340){
                            white = true;
                        } else{
                            white = false;
                        } 
                        break;
                    case SDL_MOUSEMOTION: 
                        SDL_GetMouseState(&x,&y);
                        break;
                }
            } 

            


           SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
           SDL_RenderClear( gRenderer );

           //renderiza tabuleiro
           gBoard.render(0,0);

           renderAllPieces(states);

           //renderiza selecao
           if(y < 340){
               selection.render(20,22);
           } else{
               selection.render(20,342);
           }

            SDL_RenderPresent( gRenderer );
        } 
    }
    return white;
}
