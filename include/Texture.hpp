//#ifndef GAME_STATE_HPP
//#define GAME_STATE_HPP
//#include "Graphics.hpp"
#include "common.hpp"
//#endif

#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif

//#include "GUIheaders.hpp"


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
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
class Texture {
    public:
        //inicia as variaveis
        Texture();

        //desaloca memoria
        ~Texture();

        //carrega imagens de um arquivo
        bool loadFromFile( std::string path);

        //Desaloca textura
        void free();

        //Renderiza textura em algum ponto
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

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
