//#ifndef GAME_STATE_HPP
//#define GAME_STATE_HPP
//#include "GameState.hpp"
//#endif

//#ifndef BUTTON_HPP
//#define BUTTON_HPP
//#include "Button.hpp"
//#endif

//#ifndef TEXTURE_HPP
//#define TEXTURE_HPP
//#include "Texture.hpp"
//#endif

//#ifndef SDL_INCLUDES
//#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "Texture.hpp"
#include "common.hpp"

#ifndef PIECE_HPP_INCLUDED
#include "../include/Piece.hpp"
#endif
//#endif

//#include "GUIheaders.hpp"
//#ifndef GRAPHICS_HPP
//#define GRAPHICS_HPP

#include <string> 

class Graphics{
    public: 
        //metodos

        bool init();
        bool loadMedia();
        void close(); 

/*        //variaveis                                                                                                    
        //Mouse button sprites
        SDL_Rect gSpriteClips[(int) ButtonSprite::BUTTON_SPRITE_TOTAL ]; 
        Texture gCheckTexture;
        Texture gButtonSpriteSheetTexture;
        //Buttons objects
        Button gButtons[ Button::TOTAL_BUTTONS ]; 
        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;
        //The window renderer
        SDL_Renderer* gRenderer = NULL;
        //Scene textures
        Texture gBoard;
        Texture whitePieces[7];
        Texture blackPieces[7];
        Texture gBishop;*/

        const int SCREEN_WIDTH = 680;
        const int SCREEN_HEIGHT = 680;
}; 

//#endif
