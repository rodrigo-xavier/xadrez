//#ifndef GRAPHICS_HPP
//#define GRAPHICS_HPP
//#include "Graphics.hpp"
//#endif

//#ifndef TEXTURE_HPP                                                        
//#define TEXTURE_HPP                                                        
#include "Texture.hpp"                                                     
//#endif 

#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif

//#include "GUIheaders.hpp"

#include "common.hpp"

#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

enum class GameMode {

    GAME_MODE_PVP = 0,
    GAME_MODE_CPU = 1,
    GAME_MODE_EDIT = 2,
    GAME_MODE_QUIT = 3,
    GAME_MODE_CONTINUE = 4,
    GAME_MODE_SAVE = 5,
    GAME_MODE_LOAD = 6,
    GAME_MODE_MAIN_MENU = 7,
    GAME_MODE_PAUSE = 8,
    GAME_MODE_TOTAL = 9

};

// Controla o estado do jogo
class GameState{
    
    public: 
        GameState();
        int pause = 0;

        GameMode getGameState();
        void setGameState(GameMode gameMode);
        void startStateMachine(GameMode gameMode);
        void renderPauseMenu();


    private: 
        GameMode gameState;
        //Graphics *graphics;

        void renderPVP();
        void renderMainMenu();
        void renderEditMode();
        void renderCPU();
};


#endif
