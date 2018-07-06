#ifndef TEXTURE_HPP_INCLUDED
#define TEXTURE_HPP_INCLUDED

#include "Texture.hpp"
//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer                                                                                                                              
extern SDL_Renderer* gRenderer;

//Scene textures
extern Texture gBoard;                                                                                                                                 

extern TTF_Font *gFont;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

#endif
