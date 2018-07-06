#include "../include/Graphics.hpp"


Graphics::Graphics(void){
}

bool Graphics::init(){

	bool success = true;

	//Inicializa o  SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL nao pode iniciar! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//filtro de textura linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Filtro de textura linear não habilitado" );
		}

		//cria janela
		gWindow = SDL_CreateWindow( "Xadrez", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ){
			printf( "Janela nao pode ser criada! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else{
			//cria renderer vsync
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//inicializa a cor do renderer
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//carregamento de png
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool Graphics::loadMedia()
{
	bool success = true;

	//carrega a textura
	if( !gBoard.loadFromFile( "../assets/Chess_Wood.png" ) )
	{
		printf( "Failed to load press texture!\n" );
		success = false;
	}
	
	return success;
}

void Graphics::close()
{
	//libera imagens
	gBoard.free();

	//destroi janela
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
    TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
