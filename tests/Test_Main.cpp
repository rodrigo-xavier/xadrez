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
  REQUIRE(piece->IsMovementPossible(5,8) == false);
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

TEST_CASE("Teste da função 'IsMovementPossible' do Peao", "Função determina corretamente quando o movimento é ou não possível")
{
  //Testando se quando é branca, reconhece que não pode andar para atrás (apenas para frente) e também não pode ter uma jogada para a mesma posição.
  Piece *pawn;
  pawn = new Pawn(true, 0, 1);
  REQUIRE(pawn->IsMovementPossible(0,2) == true);
  REQUIRE(pawn->IsMovementPossible(0,0) == false);
  REQUIRE(pawn->IsMovementPossible(0,1) == false);

  //Testando se quando for a primeira jogada, o peao pode andar 2 casas ou 1 casa. (mas não pode ir mais que duas)
  pawn = new Pawn(true, 0, 1);
  REQUIRE(pawn->IsMovementPossible(0,2) == true);
  REQUIRE(pawn->IsMovementPossible(0,3) == true);
  REQUIRE(pawn->IsMovementPossible(0,4) == false);

  //Testando andar 2 casas quando não for a primeira jogada.
  pawn = new Pawn(true, 0, 2);
  REQUIRE(pawn->IsMovementPossible(0,4) == false);

  //Testando andar 1 casa quando não for a primeira jogada.
  REQUIRE(pawn->IsMovementPossible(0,3) == true);

  //Testa jogada diagonal, quando há inimigo na direita (x negativo quando branca), esquerda (x positivo quando branca) e quando não ha inimigo.
  pawn = new Pawn(true, 2, 2);
  pawn->SetDiagonalEnemy(false, true);
  REQUIRE(pawn->IsMovementPossible(1,3) == true);
  REQUIRE(pawn->IsMovementPossible(3,3) == false);
  pawn->SetDiagonalEnemy(true, false);
  REQUIRE(pawn->IsMovementPossible(3,3) == true);
  REQUIRE(pawn->IsMovementPossible(1,3) == false);
  pawn->SetDiagonalEnemy(false, false);
  REQUIRE(pawn->IsMovementPossible(3,3) == false);

  //Peça preta, testando primeira jogada 2 andadas ou 1, 1 andada sem ser na primeira jogada, 2 andadas sem ser na primeira jogada.
  pawn = new Pawn(false, 0, 6);
  REQUIRE(pawn->IsMovementPossible(0,4) == true);
  REQUIRE(pawn->IsMovementPossible(0,6) == false);
  REQUIRE(pawn->IsMovementPossible(0,5) == true);
  REQUIRE(pawn->IsMovementPossible(0,3) == false);

  pawn = new Pawn(false, 0, 5);
  REQUIRE(pawn->IsMovementPossible(0,4) == true);
  REQUIRE(pawn->IsMovementPossible(0,3) == false);

  //Peça preta, testada jogada na diagonal.
  pawn = new Pawn(false, 1, 5);
  pawn->SetDiagonalEnemy(false, true);
  REQUIRE(pawn->IsMovementPossible(2,4) == true);
  REQUIRE(pawn->IsMovementPossible(0,4) == false);
  pawn->SetDiagonalEnemy(true, false);
  REQUIRE(pawn->IsMovementPossible(0,4) == true);
  REQUIRE(pawn->IsMovementPossible(2,4) == false);
  pawn->SetDiagonalEnemy(false, false);
  REQUIRE(pawn->IsMovementPossible(2,4) == false);

  //Teste quando for a primeira jogada e tenta se jogar na diagonal e andar duas casas pra frente (peça preta, mas valido para peça branca)
  pawn = new Pawn(false, 2, 6);
  pawn->SetDiagonalEnemy(false, true);
  REQUIRE(pawn->IsMovementPossible(3,4) == false);

  //Tentando fazer jogada fora do tabuleiro
  pawn->SetDiagonalEnemy(false, false);
  REQUIRE(pawn->IsMovementPossible(-1,-2) == false);
}

TEST_CASE("Teste da função 'SetPosition' do Peão", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *pawn;
  pawn = new Pawn(true, 0, 1);

  //Seta uma posição possível
  REQUIRE(pawn->SetPosition(0,3) == true);
  REQUIRE(pawn->GetPositionX() == 0);
  REQUIRE(pawn->GetPositionY() == 3);

  //Seta uma posição não possível
  REQUIRE(pawn->SetPosition(0,0) == false);
  
  //Demonstra que a posição não mudou (pois não era possível)
  REQUIRE(pawn->GetPositionX() == 0);
  REQUIRE(pawn->GetPositionY() == 3);
}

TEST_CASE("Teste da funcao 'returnPiece' do Tabuleiro ", "Retorna a peça que esta em determinada posicao")
{
    Board *board;

    board = new Board();

    REQUIRE(board->returnPiece(0,0) == 't');
    REQUIRE(board->returnPiece(0,5) == 'b');
    REQUIRE(board->returnPiece(2,0) == '0');
    REQUIRE(board->returnPiece(2,5) == '0');
    REQUIRE(board->returnPiece(6,5) == 'p');

    delete board;
}

TEST_CASE("Testa o destrutor da classe do Tabuleiro", "Seta o tabuleiro em 0")
{
    Board *board;

    board = new Board();
    delete board;

    REQUIRE(board->returnPiece(0,0) == '0');
    REQUIRE(board->returnPiece(0,5) == '0');
    REQUIRE(board->returnPiece(2,0) == '0');
    REQUIRE(board->returnPiece(2,5) == '0');
    REQUIRE(board->returnPiece(6,5) == '0');
}