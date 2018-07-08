#include "../include/GameState.hpp"

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
