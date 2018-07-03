#include <cstdio>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include<SDL2/SDL.h>
#include "Texture.hpp"

using namespace std;

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//Scene textures
extern Texture gBoard;                                                                                                                                                                                                                     

extern TTF_Font *gFont;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


class Graphics{
    public:
        Graphics();
        bool init();
        bool loadMedia();
        void close();

};
