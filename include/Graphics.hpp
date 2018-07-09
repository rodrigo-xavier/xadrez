#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "Texture.hpp"
#include "common.hpp"


#include <string> 

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
        //metodos

        bool init();
        bool loadMedia();
        void close(); 

        const int SCREEN_WIDTH = 680;
        const int SCREEN_HEIGHT = 680;
}; 

