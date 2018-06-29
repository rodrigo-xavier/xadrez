#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

// Dá pra ajeitar essa porcaria no makefile pra ficar só #include <funcoes.h>, acho que tem a ver com aquela tag -I do gcc/g++, mas tava dando problema
// Isso não vai dar problema se não alterar o nome dos diretórios lib e include, ou não mover este arquivo de teste para outro lugar
#include "../lib/catch.hpp"
#include "../include/Piece.hpp"
#include "../include/Pawn.hpp"
#include "../include/Knight.hpp"
#include "../include/Bishop.hpp"
#include "../include/Rook.hpp"
#include "../include/Queen.hpp"
#include "../include/King.hpp"
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
}

TEST_CASE("Teste da classe de estrutura basica das peças","Toda estrutura basica da peça")
{
	Piece *piece;
	piece = new Piece();

	REQUIRE(piece->GetColor() == false);
	REQUIRE(piece->GetName() == PieceName::Empty);
	REQUIRE(piece->GetPositionX() == 0);
  REQUIRE(piece->GetPositionY() == 0);
}

TEST_CASE("Teste da classe de Peão","Toda estrutura basica da peça Peão")
{
	Pawn *pawn;
	pawn = new Pawn(true, 1, 1);

	REQUIRE(pawn->GetColor() == true);
	REQUIRE(pawn->GetName() == PieceName::Pawn);
	REQUIRE(pawn->GetPositionX() == 1);
  REQUIRE(pawn->GetPositionY() == 1);
}

TEST_CASE("Teste da classe de Cavalo","Toda estrutura basica da peça Cavalo")
{
	Knight *knight;
	knight = new Knight(false, 2, 5);

	REQUIRE(knight->GetColor() == false);
	REQUIRE(knight->GetName() == PieceName::Knight);
	REQUIRE(knight->GetPositionX() == 2);
  REQUIRE(knight->GetPositionY() == 5);
}

TEST_CASE("Teste da classe do Bispo","Toda estrutura basica da peça Bispo")
{
	Bishop *bishop;
	bishop = new Bishop(true, 15, 7);

	REQUIRE(bishop->GetColor() == true);
	REQUIRE(bishop->GetName() == PieceName::Bishop);
	REQUIRE(bishop->GetPositionX() == 15);
  REQUIRE(bishop->GetPositionY() == 7);
}

TEST_CASE("Teste da classe da Torre","Toda estrutura basica da peça Torre")
{
	Rook *rook;
	rook = new Rook(true, 9, 3);

	REQUIRE(rook->GetColor() == true);
	REQUIRE(rook->GetName() == PieceName::Rook);
	REQUIRE(rook->GetPositionX() == 9);
  REQUIRE(rook->GetPositionY() == 3);
}

TEST_CASE("Teste da classe da Rainha","Toda estrutura basica da peça Rainha")
{
	Queen *queen;
	queen = new Queen(false, 21, 6);

	REQUIRE(queen->GetColor() == false);
	REQUIRE(queen->GetName() == PieceName::Queen);
	REQUIRE(queen->GetPositionX() == 21);
  REQUIRE(queen->GetPositionY() == 6);
}

TEST_CASE("Teste da classe do Rei","Toda estrutura basica da peça Rei")
{
	King *king;
	king = new King(true, 8, 12);

	REQUIRE(king->GetColor() == true);
	REQUIRE(king->GetName() == PieceName::King);
	REQUIRE(king->GetPositionX() == 8);
  REQUIRE(king->GetPositionY() == 12);
}
