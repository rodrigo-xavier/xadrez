#include "../include/Texture.hpp"

Texture::Texture()
{
    //Inicializa
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture()
{
    //Desaloca
    free();
}


bool Texture::loadFromFile( std::string path )
{
    //apaga o que tinha antes
    free();

    //a textura que sera retornada
    SDL_Texture* newTexture = NULL;

    //carrega imagem numa surface
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //transparencia
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //textura a partir da surface
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //dimensoes
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //libera a memoria da superficie
        SDL_FreeSurface( loadedSurface );
    }

    mTexture = newTexture;
    return mTexture != NULL;
}

void Texture::free()
{
    //libera textura se existir
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //O quanto da textura vai renderizar
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //corte na textura (pra pegar partes da textura)
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //renderiza na tela
    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int Texture::getWidth()
{
    return mWidth;
}

int Texture::getHeight()
{
    return mHeight;
}

