#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

// Dá pra ajeitar essa porcaria no makefile pra ficar só #include <funcoes.h>, acho que tem a ver com aquela tag -I do gcc/g++, mas tava dando problema
// Isso não vai dar problema se não alterar o nome dos diretórios lib e include, ou não mover este arquivo de teste para outro lugar
#include "../lib/catch.hpp"
#include "../include/Piece.hpp"
#include "../include/Board.hpp"

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

TEST_CASE("Testes das funcoes usadas na main", "Todas as funcoes de funcoes")
{

    //teste para acertar
     SECTION("Teste de soma()")
     {
         int a = 2, b = 5;
         REQUIRE(soma(a, b) == 7);
     }

    /*
    //teste para falhar
    SECTION("Teste de soma()"){
        int a=2,b=5;
        REQUIRE(soma(a,b)== 6); 
    }*/
}

TEST_CASE("Teste da estrutura basica das peças","Toda estrutura basica da peça")
{
	Piece *piece;
	int* a;
	piece = new Piece();	
      	a = piece->GetPosition();
	REQUIRE(piece->GetColor() == false);
	REQUIRE(piece->GetName() == 1);
	REQUIRE(a[0] == 0);
	REQUIRE(a[1] == 0);
}
