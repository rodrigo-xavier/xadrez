#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>

#ifndef LTEXTURE_H
#define LTEXTURE_H

class Texture
{
    public:
        //inicia as variaveis
        Texture();

        //desaloca memoria
        ~Texture();

        //carrega imagens de um arquivo
        bool loadFromFile( std::string path );
            
        //Cria imagem a partir de uma string
        bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

        //Desaloca textura
        void free();

        //Renderiza textura em algum ponto
        void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        //dimensoes da imagem
        int getWidth();                                                                                                                                                      
        int getHeight();

    private:
        //a textura
        SDL_Texture* mTexture;

        //dimensoes da imagem
        int mWidth;
        int mHeight;

};

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//Scene textures
extern Texture gBoard;

extern TTF_Font *gFont;


#endif
