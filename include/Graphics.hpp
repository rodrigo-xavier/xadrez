#include <cstdio>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include<SDL2/SDL.h>
#include "Texture.hpp"
#include "common.hpp"

using namespace std;

class Graphics{
    public:
        Graphics();
        bool init();
        bool loadMedia();
        void close();

};
