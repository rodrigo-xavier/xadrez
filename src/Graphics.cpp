#include "../include/Graphics.hpp"
#include <cstdio>
#include "../include/Piece.hpp"
#include "../include/States.hpp"

bool Graphics::loadMedia() {
    bool success = true;
    
    //carrega a textura
    if( !gBoard.loadFromFile( "../assets/Chess_Wood.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !gCheckTexture.loadFromFile( "../assets/check2.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !casaVerde.loadFromFile( "../assets/CasaVerde.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !bestMove.loadFromFile( "../assets/bestMove.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !pieceSelected.loadFromFile( "../assets/pieceSelected.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    if( !gBishop.loadFromFile( "../assets/BishopB.png" ) ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    //Texturas de endGame
    //brancas ganham
    if( !endGame[(int)GameResult::WhiteWins].loadFromFile( "../assets/Wwin.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    //pretas ganham
    if( !endGame[(int)GameResult::BlackWins].loadFromFile( "../assets/Bwin.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    //empate
    if( !endGame[(int)GameResult::Draw].loadFromFile( "../assets/Draw.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    
    //peças brancas
    
    //whitePieces[(int)PieceName::Empty] = NULL;
    
    if( !whitePieces[(int)PieceName::Pawn].loadFromFile( "../assets/PawnW.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !whitePieces[(int)PieceName::Knight].loadFromFile( "../assets/KnightW.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !whitePieces[(int)PieceName::Bishop].loadFromFile( "../assets/BishopW.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !whitePieces[(int)PieceName::Rook].loadFromFile( "../assets/RookW.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !whitePieces[(int)PieceName::Queen].loadFromFile( "../assets/QueenW.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !whitePieces[(int)PieceName::King].loadFromFile( "../assets/KingW.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    //Peças pretas
    
    //blackPieces[(int)PieceName::Empty] = NULL;

    if( !blackPieces[(int)PieceName::Pawn].loadFromFile( "../assets/PawnB.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !blackPieces[(int)PieceName::Knight].loadFromFile( "../assets/KnightB.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !blackPieces[(int)PieceName::Bishop].loadFromFile( "../assets/BishopB.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !blackPieces[(int)PieceName::Rook].loadFromFile( "../assets/RookB.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !blackPieces[(int)PieceName::Queen].loadFromFile( "../assets/QueenB.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !blackPieces[(int)PieceName::King].loadFromFile( "../assets/KingB.png") ) {
        printf( "Failed to load texture!\n" );
        success = false;
    }

    
        //Load sprites do menu
    if( !gButtonSpriteSheetTexture.loadFromFile( "../assets/menus.png") ) {
        printf( "Failed to load button sprite texture!\n" );
        success = false;
    }else{

        //Set sprites
        for( int i = 0; i < (int) ButtonSprite::BUTTON_SPRITE_TOTAL; ++i )
        {
            gSpriteClips[ i ].x = 0;
            gSpriteClips[ i ].y = i * 340;
            gSpriteClips[ i ].w = Button::BUTTON_WIDTH;
            gSpriteClips[ i ].h = Button::BUTTON_HEIGHT;
        }

        //Set buttons in corners
        gButtons[ 0 ].setPosition( 0, 0 );
        gButtons[ 1 ].setPosition( SCREEN_WIDTH - Button::BUTTON_WIDTH, 0 );
        gButtons[ 2 ].setPosition( 0, SCREEN_HEIGHT - Button::BUTTON_HEIGHT );
        gButtons[ 3 ].setPosition( SCREEN_WIDTH - Button::BUTTON_WIDTH, SCREEN_HEIGHT - Button::BUTTON_HEIGHT );
        gButtons[ 4 ].setPosition( 0, 0 );
        gButtons[ 5 ].setPosition( SCREEN_WIDTH - Button::BUTTON_WIDTH, 0 );                                                                                                                  
        gButtons[ 6 ].setPosition( 0, SCREEN_HEIGHT - Button::BUTTON_HEIGHT );
        gButtons[ 7 ].setPosition( SCREEN_WIDTH - Button::BUTTON_WIDTH, SCREEN_HEIGHT - Button::BUTTON_HEIGHT );

    }
    return success;
}

bool Graphics::init(){

    bool success = true;

    //Inicializa o  SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL nao pode iniciar! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
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


void Graphics::close() {
    //libera imagens
    gBoard.free();

    for(int i = 1 ; i < 7 ; i++){
        whitePieces[i].free();
    }

    for(int i = 1 ; i < 7 ; i++){
        blackPieces[i].free();
    }

    //destroi janela
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
