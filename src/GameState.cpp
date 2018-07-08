#include "../include/GameState.hpp"
#include <cstdio>
#include "../include/Piece.hpp"
#include "../include/States.hpp"
#include "../include/GUIBoard.hpp"
/*
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

        
        SDL_Rect board[8][8]; //matriz de retangulos (tabuleiro)
        SDL_Point focus = {-1,-1}; //posicao clicada
        Piece *focusedPiece = NULL; //ultima peça clicada
};

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
                    if(states->IsPositionValid(focusedPiece,i,j));
                        casaVerde.render(indexToPixel(i),indexToPixel(j)+2); 
                }
            }
        }

    }
}*/


GameState::GameState(){
    gameState = GameMode::GAME_MODE_MAIN_MENU;
    //graphics = gr;
}

GameMode GameState::getGameState(){
    return gameState; 
}

void GameState::setGameState(GameMode gameMode){
    gameState = gameMode;
}

void GameState::renderMainMenu(){

    bool quit = false;


    for (int i = 0 ; i < Button::TOTAL_BUTTONS/2 ; i++){
        gButtons[i].setCurrentSprite((ButtonSprite) i);
    }

    //Event handler
    SDL_Event e;

    while(gameState == GameMode::GAME_MODE_MAIN_MENU){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameState = GameMode::GAME_MODE_QUIT;
                }

                //Handle button events
                for( int i = 0; i < Button::TOTAL_BUTTONS/2; ++i ) {
                    gButtons[ i ].handleEvent( &e , this);
                }
            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            //Render buttons
            for( int i = 0; i < Button::TOTAL_BUTTONS/2; ++i )
            {
                gButtons[ i ].render();
            }

            //Update screen
            SDL_RenderPresent( gRenderer );

    }
}

void GameState::renderPauseMenu(){

    bool quit = false;
    pause = 1;


    for (int i = Button::TOTAL_BUTTONS/2 ; i < Button::TOTAL_BUTTONS ; i++){
        gButtons[i].setCurrentSprite((ButtonSprite) i);
    }

    //Event handler
    SDL_Event e;

    //while(gameState == GAME_MODE_PAUSE){
    while(pause == 1){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameState = GameMode::GAME_MODE_QUIT;
                } else if(e.type == SDL_KEYDOWN){
                    switch(e.key.keysym.sym){
                        case SDLK_ESCAPE:
                            pause = 0;
                            break;
                    }
                }

                //Handle button events
                for( int i = Button::TOTAL_BUTTONS/2; i < Button::TOTAL_BUTTONS; ++i )
                {
                    gButtons[ i ].handleEvent( &e , this);
                }
            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            //Render buttons
            for( int i = Button::TOTAL_BUTTONS/2; i < Button::TOTAL_BUTTONS; ++i )
            {
                gButtons[ i ].render();
            }

            //Update screen
            SDL_RenderPresent(gRenderer);

    }
}

void GameState::renderEditMode(){

    bool quit = false;

    SDL_Event e;

    while(gameState == GameMode::GAME_MODE_EDIT){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameState = GameMode::GAME_MODE_QUIT;
                } else if(e.type == SDL_KEYDOWN){
                    switch(e.key.keysym.sym){
                        case SDLK_ESCAPE:
                            renderPauseMenu();
                            //gameState = GAME_MODE_PAUSE;
                            break;
                    }
                }

            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            gBoard.render(0,0);
            //Update screen
            SDL_RenderPresent( gRenderer );

    }
}

void GameState::renderPVP(){

    bool quit = false;

    SDL_Event e;
    States *states = new States();
    GUIBoard *tabuleiro = new GUIBoard();

    while(gameState == GameMode::GAME_MODE_PVP){

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameState = GameMode::GAME_MODE_QUIT;
                } else if(e.type == SDL_KEYDOWN){
                    switch(e.key.keysym.sym){
                        case SDLK_ESCAPE:
                            renderPauseMenu();
                            //gameState = GAME_MODE_PAUSE;
                            break;
                    }
                } else if(e.type == SDL_MOUSEBUTTONDOWN){
                    switch(e.type){
                        case SDL_MOUSEBUTTONDOWN: //se clicar
                            int x = -1, y = -1;
                            SDL_GetMouseState(&x,&y); //pega posicao do mouse
                            tabuleiro->updateFocus((int)x,(int)y); //atualiza o indice da matriz focado
                            
                            //ve se houve jogada, atualiza os vetores de peças e zera a peça focada
                            if(tabuleiro->checkMovement(states)){
                                tabuleiro->focusedPiece = NULL;
                            }else{
                                //Se nao houve jogada, a peça focada é o foco atual
                                tabuleiro->focusedPiece = states->GetPiece(tabuleiro->focus.x,tabuleiro->focus.y); 
                            }
                            break;
                    }
                }

            }

            //limpa tela
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            
            //renderiza tabuleiro
            gBoard.render(0,0);
           
            //renderiza todas as peças
            tabuleiro->renderAllPieces(states);
            //tabuleiro->renderPossibleMoves(states);

            //t->renderPieceOnBoard(PieceName::Knight,1,1,1);

            //atualiza tela
            SDL_RenderPresent( gRenderer );
    }
    delete states;
    delete tabuleiro;
}

void GameState::renderCPU(){

    bool quit = false; 
    
    SDL_Event e;

    while(gameState == GameMode::GAME_MODE_CPU){
    
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    gameState = GameMode::GAME_MODE_QUIT;
                } else if(e.type == SDL_KEYDOWN){
                    switch(e.key.keysym.sym){
                        case SDLK_ESCAPE:
                            renderPauseMenu();
                            //gameState = GAME_MODE_PAUSE;
                            break;
                    }
                }

            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            gBoard.render(0,0);
            //Update screen
            SDL_RenderPresent( gRenderer );
    }
}

void GameState::startStateMachine(GameMode gameMode){

    gameState = gameMode;

    while(gameState != GameMode::GAME_MODE_QUIT){

        switch(gameState){
            case GameMode::GAME_MODE_MAIN_MENU:
                renderMainMenu();
                break;
            case GameMode::GAME_MODE_PVP:
                renderPVP();
                break;
            case GameMode::GAME_MODE_CPU:
                renderCPU();
                break;
            case GameMode::GAME_MODE_EDIT:
                renderEditMode();
                break;
//            case GAME_MODE_PAUSE:
//                renderPauseMenu();
//                break;
        }
    }
}
