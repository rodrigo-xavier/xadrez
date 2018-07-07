#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "common.hpp"

#ifndef LTEXTURE_H
#define LTEXTURE_H

/**@brief Método que retorna um booleano indicando se o movimento é possível
*
*Parâmetros: 
*
*Tratamento de Erros:
*
*Descrição:
*
*Assertivas de entrada:
*
*Requisitos: 
*
*Hipóteses: 
*
*Assertivas de saida:
*
*Interface explicita:
*
*Interface implicita:
*
*Contrato na especificação: 
*
*/

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

#endif
