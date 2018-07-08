#include "../include/GameState.hpp"
#include <cstdio>
#include "../include/Piece.hpp"
#include "../include/States.hpp"
#include "../include/GUIBoard.hpp"


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
                gButtons[i].render();
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
    bool showHint = false;
    bool showBest = false;
    int x = -1, y = -1;
    //player:
    //bool white = true;

    SDL_Event e;
    States *states = new States();
    GUIBoard *tabuleiro = new GUIBoard();
    GameResult gameResult = GameResult::NoContest;
    
    states->SetPieceTurn(tabuleiro->choosePieceTurn(this, states));


    while(gameState == GameMode::GAME_MODE_PVP){

            //lida com a fila de eventos
            while( SDL_PollEvent( &e ) != 0 ) {
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
                        case SDLK_h:
                            showHint = !showHint;
                            break;
                        case SDLK_b:
                            showBest = !showBest;
                    }
                } else if(e.type == SDL_MOUSEBUTTONDOWN){
                    switch(e.type){
                        case SDL_MOUSEBUTTONDOWN: //se clicar
                            x = -1;
                            y = -1;
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
            
            //trata se teve save
            if(gameState == GameMode::GAME_MODE_SAVE){
                
                states->SaveGame(GameMode::GAME_MODE_PVP);
                gameState = GameMode::GAME_MODE_PVP;
            }

            //trata se teve load
            if(gameState == GameMode::GAME_MODE_LOAD){
                
                states->LoadGame(GameMode::GAME_MODE_PVP);
                gameState = GameMode::GAME_MODE_PVP;
            }

            //limpa tela
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            //renderiza tabuleiro
            gBoard.render(0,0);
            
            gameResult = states->WhoWon();
            if(gameResult == GameResult::NoContest){

                if((tabuleiro->focusedPiece != NULL) ){
                    //foco da peça
                    if(tabuleiro->focusedPiece->GetName() != PieceName::Empty && (tabuleiro->focusedPiece->GetColor() == states->GetPieceTurn() )){
                        pieceSelected.render(tabuleiro->indexToPixel(tabuleiro->focus.x),tabuleiro->indexToPixel(tabuleiro->focus.y)+2);
                    }
                
                    //renderiza todos os movimentos possiveis se a peça em foco for a da jogada
                    if(showHint && (tabuleiro->focusedPiece->GetColor() == states->GetPieceTurn() ) )
                        tabuleiro->renderPossibleMoves(states);

                    if(showBest &&  (tabuleiro->focusedPiece->GetColor() == states->GetPieceTurn() ))
                        tabuleiro->renderBestMove(states);
                    //renderiza todas as peças
                    }
                tabuleiro->renderAllPieces(states);

            } else{
                endGame[(int)gameResult].render(0,0);
            }
            //atualiza tela
            SDL_RenderPresent( gRenderer );
    }
    delete states;
    delete tabuleiro;
}

void GameState::renderCPU(){

    bool quit = false;
    bool showHint = false;
    bool showBest = false;
    int x = -1, y = -1;

    bool player = true; //true -> branco
    bool CPUTurn = false; 

    SDL_Event e;
    States *states = new States();
    GUIBoard *tabuleiro = new GUIBoard();
    GameResult gameResult = GameResult::NoContest;

    //jogador escolhe sua peça
    player = tabuleiro->choosePieceTurn(this,states); 
    states->SetPieceTurn(player);

    CPUTurn = false; //jogador joga primeiro

    while(gameState == GameMode::GAME_MODE_CPU){
        
        //lida com a fila de eventos
        while( SDL_PollEvent( &e ) != 0 ) {
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
                    case SDLK_h:
                        showHint = !showHint;
                        break;
                    case SDLK_b:
                        showBest = !showBest;
                }
            } else if(e.type == SDL_MOUSEBUTTONDOWN){
                switch(e.type){
                    case SDL_MOUSEBUTTONDOWN: //se clicar
                        if(CPUTurn == false){
                            x = -1;
                            y = -1;
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
                            CPUTurn = true;
                        }
                }
            }

        }
        
        //trata se teve save
        if(gameState == GameMode::GAME_MODE_SAVE){
                
            states->SaveGame(GameMode::GAME_MODE_CPU);
            gameState = GameMode::GAME_MODE_CPU;
        }

        //trata se teve load
        if(gameState == GameMode::GAME_MODE_LOAD){
            
            states->LoadGame(GameMode::GAME_MODE_CPU);
            gameState = GameMode::GAME_MODE_CPU;
        }


       //limpa tela
       SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
       SDL_RenderClear( gRenderer );

       //renderiza tabuleiro
       gBoard.render(0,0);
       
       gameResult = states->WhoWon();
       if(gameResult == GameResult::NoContest){
           
           //cpu joga
           if(CPUTurn = true){
               states->PlayBestMove(!player, Level::Hard);
               CPUTurn = false;
           }

           if((tabuleiro->focusedPiece != NULL) ){
               //foco da peça
               if(tabuleiro->focusedPiece->GetName() != PieceName::Empty && (tabuleiro->focusedPiece->GetColor() == states->GetPieceTurn() )){
                   pieceSelected.render(tabuleiro->indexToPixel(tabuleiro->focus.x),tabuleiro->indexToPixel(tabuleiro->focus.y)+2);
               }
           
               //renderiza todos os movimentos possiveis se a peça em foco for a da jogada
               if(showHint && (tabuleiro->focusedPiece->GetColor() == states->GetPieceTurn() ) )
                   tabuleiro->renderPossibleMoves(states);

               if(showBest &&  (tabuleiro->focusedPiece->GetColor() == states->GetPieceTurn() ))
                   tabuleiro->renderBestMove(states);
               //renderiza todas as peças
               }
           tabuleiro->renderAllPieces(states);

       } else{
           endGame[(int)gameResult].render(0,0);
       }
       //atualiza tela
       SDL_RenderPresent( gRenderer );
    }
    delete states;
    delete tabuleiro;
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
        }
    }
}
