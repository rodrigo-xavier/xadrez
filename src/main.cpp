#include "../include/Piece.hpp"
#include "../include/Pawn.hpp"
#include "../include/Knight.hpp"
#include "../include/Bishop.hpp"
#include "../include/Rook.hpp"
#include "../include/Queen.hpp"
#include "../include/King.hpp"
#include "../include/Board.hpp"
#include "../include/States.hpp"
#include "../include/Texture.hpp"
#include "../include/Graphics.hpp"
#include "../include/common.hpp"


#include <cstdio>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include<SDL2/SDL.h>


using namespace std;

extern const int SCREEN_WIDTH = 680;
extern const int SCREEN_HEIGHT = 680;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
Texture gBoard;

TTF_Font *gFont = NULL; 

int main( int argc, char* args[] )
{
    //Inicializa o controle dos graficos
    Graphics graphics;
    
    //Inicia o SDL
	if( !graphics.init() )
	{
		printf( "Falha ao inicializar!\n" );
	}
	else
	{
		//Carrega mídia
		if( !graphics.loadMedia() )
		{
			printf( "Nao foi possivel carregar a midia!\n" );
		}
		else
		{	
			//flag de saída
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Current rendered texture
			Texture* currentTexture = &gBoard;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//limpa tela
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//renderiza textura
				currentTexture->render( 0, 0 );

				//atualiza a tela
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//libera os recursos e finaliza o sdl
    graphics.close();

	return 0;
}
