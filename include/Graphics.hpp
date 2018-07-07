#include <cstdio>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include<SDL2/SDL.h>
#include "Texture.hpp"
#include "common.hpp"

using namespace std;

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

class Graphics{
    public:
        Graphics();
        bool init();
        bool loadMedia();
        void close();

};
