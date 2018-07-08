#include "../include/Button.hpp"

Button::Button()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = ButtonSprite::BUTTON_SPRITE_MAIN_MENU;
}

void Button::setPosition( int x, int y )
{                                                                                                                      
    mPosition.x = x;
    mPosition.y = y;
}

void Button::setCurrentSprite(ButtonSprite sprite){
    mCurrentSprite = sprite;
}

void Button::handleEvent( SDL_Event* e , GameState *gm)
{
    check = 0;
    //If mouse event happened
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN ){
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        //g if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < mPosition.x ) {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + BUTTON_WIDTH ){
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y ){
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT ) {
            inside = false;
        }

        //Mouse is outside button
        if( !inside ) {
            //mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
            mCurrentSprite = mCurrentSprite;
        }
        //Mouse is inside button
        else {
            check = 1;
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                //mCurrentSprite = BUTTON_SPRITE_CONTINUE;
                break;

                case SDL_MOUSEBUTTONDOWN:
                    switch(mCurrentSprite){
                        case ButtonSprite::BUTTON_SPRITE_PVP :
                             gm->setGameState(GameMode::GAME_MODE_PVP);
                            //mCurrentSprite = BUTTON_SPRITE_CONTINUE;
                            break;
                        case ButtonSprite::BUTTON_SPRITE_CPU:
                             gm->setGameState(GameMode::GAME_MODE_CPU);
                            break;
                        case ButtonSprite::BUTTON_SPRITE_EDIT:
                             gm->setGameState(GameMode::GAME_MODE_EDIT);
                            break;
                        case ButtonSprite::BUTTON_SPRITE_QUIT:
                             gm->setGameState(GameMode::GAME_MODE_QUIT);
                            break;
                        case ButtonSprite::BUTTON_SPRITE_CONTINUE:
                             gm->pause = 0;
                             //gm->setGameState(GAME_MODE_CONTINUE);
                            break;
                        case ButtonSprite::BUTTON_SPRITE_SAVE:
                             gm->pause = 0;
                             //gm->setGameState(GAME_MODE_SAVE);
                 //           *gm = GAME_MODE_SAVE;
                            break;
                        case ButtonSprite::BUTTON_SPRITE_LOAD:
                             gm->pause = 0;
                             //gm->setGameState(GAME_MODE_LOAD);
                  //          *gm = GAME_MODE_LOAD;
                            break;
                        case ButtonSprite::BUTTON_SPRITE_MAIN_MENU:
                             gm->pause = 0;
                             gm->setGameState(GameMode::GAME_MODE_MAIN_MENU);
                            //*gm = GAME_MODE_MAIN_MENU;
                            break;
                    }
                //mCurrentSprite = BUTTON_SPRITE_SAVE;
                break;
            }
        }
    }
}

void Button::render()
{
    //Show current button sprite
    gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &(gSpriteClips[ (int) mCurrentSprite ]) );

    if(check == 1){
        //gCheckTexture.render(mPosition.x,mPosition.y);
        //gBishop.render(mPosition.x + BUTTON_WIDTH/2 - 40 ,mPosition.y);
        blackPieces[(int)PieceName::Knight].render(mPosition.x + BUTTON_WIDTH/2 - 40 ,mPosition.y);
    }
}

