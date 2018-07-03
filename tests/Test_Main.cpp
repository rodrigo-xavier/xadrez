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
#include "../include/States.hpp"

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
	REQUIRE(piece->GetPositionX() == -1);
  REQUIRE(piece->GetPositionY() == -1);
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
  pawn = new Pawn(true, 0, 6);
  REQUIRE(pawn->IsMovementPossible(0,5) == true);
  REQUIRE(pawn->IsMovementPossible(0,7) == false);
  REQUIRE(pawn->IsMovementPossible(0,6) == false);

  //Testando se quando for a primeira jogada, o peao pode andar 2 casas ou 1 casa. (mas não pode ir mais que duas)
  REQUIRE(pawn->IsMovementPossible(0,4) == true);
  REQUIRE(pawn->IsMovementPossible(0,3) == false);

  //Testando andar 2 casas quando não for a primeira jogada.
  pawn = new Pawn(true, 0, 5);
  REQUIRE(pawn->IsMovementPossible(0,3) == false);

  //Testando andar 1 casa quando não for a primeira jogada.
  REQUIRE(pawn->IsMovementPossible(0,4) == true);

  //Testa jogada diagonal, quando há inimigo na direita (x positivo quando branca), esquerda (x negativo quando branca) e quando não ha inimigo.
  pawn = new Pawn(true, 5, 5);
  pawn->SetDiagonalEnemy(false, true);
  REQUIRE(pawn->IsMovementPossible(6,4) == true);
  REQUIRE(pawn->IsMovementPossible(3,4) == false);
  pawn->SetDiagonalEnemy(true, false);
  REQUIRE(pawn->IsMovementPossible(4,4) == true);
  REQUIRE(pawn->IsMovementPossible(6,4) == false);
  pawn->SetDiagonalEnemy(false, false);
  REQUIRE(pawn->IsMovementPossible(6,4) == false);

  //Peça preta, testando primeira jogada 2 andadas ou 1, 1 andada sem ser na primeira jogada, 2 andadas sem ser na primeira jogada.
  pawn = new Pawn(false, 0, 1);
  REQUIRE(pawn->IsMovementPossible(0,3) == true);
  REQUIRE(pawn->IsMovementPossible(0,4) == false);
  REQUIRE(pawn->IsMovementPossible(0,2) == true);

  pawn = new Pawn(false, 0, 2);
  REQUIRE(pawn->IsMovementPossible(0,3) == true);
  REQUIRE(pawn->IsMovementPossible(0,1) == false);

  //Peça preta, testada jogada na diagonal.
  pawn = new Pawn(false, 1, 2);
  pawn->SetDiagonalEnemy(false, true);
  REQUIRE(pawn->IsMovementPossible(0,3) == true);
  REQUIRE(pawn->IsMovementPossible(2,3) == false);
  pawn->SetDiagonalEnemy(true, false);
  REQUIRE(pawn->IsMovementPossible(2,3) == true);
  REQUIRE(pawn->IsMovementPossible(0,1) == false);
  pawn->SetDiagonalEnemy(false, false);
  REQUIRE(pawn->IsMovementPossible(2,3) == false);

  //Teste quando for a primeira jogada e tenta se jogar na diagonal e andar duas casas pra frente
  pawn = new Pawn(true, 2, 6);
  pawn->SetDiagonalEnemy(false, true);
  REQUIRE(pawn->IsMovementPossible(3,4) == false);

  //Tentando fazer jogada fora do tabuleiro
  pawn->SetDiagonalEnemy(false, false);
  REQUIRE(pawn->IsMovementPossible(-1,-2) == false);
  pawn = new Pawn(false, 7, 7);
  REQUIRE(pawn->IsMovementPossible(8,8) == false);
}

TEST_CASE("Teste da função 'SetPosition' do Peão", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *pawn;
  pawn = new Pawn(false, 0, 1);

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

TEST_CASE("Teste da função 'IsMovementPossible' do Bispo", "A função determina que o bispo só pode se mover na diagonal, ir e voltar (só na diagonal, sem fazer curvas no caminho)")
{
  Piece *bishop;
  bishop = new Bishop(false, 2, 7);
  //Andar da posição inicial para diagonal direita (2 casas)
  REQUIRE(bishop->IsMovementPossible(4, 5) == true);

  //Andar da posição inicial para diagonal esquerda (2 casas)
  REQUIRE(bishop->IsMovementPossible(0, 5) == true);

  //Tentativa de andar em linha reta
  REQUIRE(bishop->IsMovementPossible(2, 6) == false);

  //Tentativa de ficar parado no mesmo local
  REQUIRE(bishop->IsMovementPossible(2, 7) == false);

  //Andar uma jogada para direita
  REQUIRE(bishop->IsMovementPossible(3, 6) == true);

  //Andar uma jogada para esquerda
  REQUIRE(bishop->IsMovementPossible(1, 6) == true);

  //Andar para fora do tabuleiro (negativo ou maior que 7)
  REQUIRE(bishop->IsMovementPossible(3, 8) == false);
  REQUIRE(bishop->IsMovementPossible(-1, 4) == false);
}

TEST_CASE("Teste da função 'SetPosition' do Bispo", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *bishop;
  bishop = new Bishop(false, 2, 7);

  //Andar para a diagonal direita
  REQUIRE(bishop->SetPosition(3,6) == true);
  REQUIRE(bishop->GetPositionX() == 3);
  REQUIRE(bishop->GetPositionY() == 6);

  //Seta uma posição não possível (andar em linha reta)
  REQUIRE(bishop->SetPosition(3,5) == false);

  //Demonstra que a posição não mudou (pois não era possível)
  REQUIRE(bishop->GetPositionX() == 3);
  REQUIRE(bishop->GetPositionY() == 6);

  //Da posição que estava (3,6), andar para esquerda
  REQUIRE(bishop->SetPosition(2,5) == true);
  REQUIRE(bishop->GetPositionX() == 2);
  REQUIRE(bishop->GetPositionY() == 5);
}

TEST_CASE("Teste da função 'IsMovementPossible' da Torre", "A função determina que a Torre só pode se mover na horizontal ou vertical (um por jogada), ir e voltar (só na vertical/horizontal, sem fazer curvas no caminho)")
{
  Piece *rook;
  rook = new Rook(false, 0, 7);
  //Andar da posição inicial para diagonal direita
  REQUIRE(rook->IsMovementPossible(1, 6) == false);

  //Tentativa de andar vertical (2 casas)
  REQUIRE(rook->IsMovementPossible(0, 5) == true);

  //Tentativa de andar horizontal (2 casas)
  REQUIRE(rook->IsMovementPossible(2, 7) == true);

  //Tentativa de ficar parado no mesmo local
  REQUIRE(rook->IsMovementPossible(0, 7) == false);

  //Andar para fora do tabuleiro (negativo ou maior que 7)
  REQUIRE(rook->IsMovementPossible(0, 8) == false);
  REQUIRE(rook->IsMovementPossible(0, -1) == false);
}

TEST_CASE("Teste da função 'SetPosition' da Torre", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *rook;
  rook = new Rook(false, 0, 7);

  //Andar para a vertical
  REQUIRE(rook->SetPosition(0,6) == true);
  REQUIRE(rook->GetPositionX() == 0);
  REQUIRE(rook->GetPositionY() == 6);

  //Seta uma posição não possível (andar na diagonal)
  REQUIRE(rook->SetPosition(1,5) == false);

  //Demonstra que a posição não mudou (pois não era possível)
  REQUIRE(rook->GetPositionX() == 0);
  REQUIRE(rook->GetPositionY() == 6);

  //Da posição que estava (0,6), andar para horizontal
  REQUIRE(rook->SetPosition(1,6) == true);
  REQUIRE(rook->GetPositionX() == 1);
  REQUIRE(rook->GetPositionY() == 6);
}

TEST_CASE("Teste da função 'IsMovementPossible' do Cavalo", "A função determina que o Cavalo só pode se mover em 'L', ir e voltar")
{
  Piece *knight;
  knight = new Knight(false, 1, 7);

  //Andar da posição inicial (1x7) para todas casas possíveis
  REQUIRE(knight->IsMovementPossible(0, 5) == true);
  REQUIRE(knight->IsMovementPossible(2, 5) == true);
  REQUIRE(knight->IsMovementPossible(3, 6) == true);

  //Andar em linha reta (vertical/horizontal) - ver que não é possível
  REQUIRE(knight->IsMovementPossible(1, 6) == false);
  REQUIRE(knight->IsMovementPossible(2, 7) == false);

  //Ficar na mesma posição que a inicial - ver que não é possível
  REQUIRE(knight->IsMovementPossible(1, 7) == false);

  //Peça no meio do tabuleiro (4x4), todas as posições possíveis
  knight = new Knight(false, 4, 4);
  REQUIRE(knight->IsMovementPossible(3, 2) == true);
  REQUIRE(knight->IsMovementPossible(5, 2) == true);
  REQUIRE(knight->IsMovementPossible(2, 3) == true);
  REQUIRE(knight->IsMovementPossible(6, 3) == true);
  REQUIRE(knight->IsMovementPossible(3, 6) == true);
  REQUIRE(knight->IsMovementPossible(5, 6) == true);
  REQUIRE(knight->IsMovementPossible(2, 5) == true);
  REQUIRE(knight->IsMovementPossible(6, 5) == true);
}

TEST_CASE("Teste da função 'SetPosition' do Cavalo", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *knight;
  knight = new Knight(false, 1, 7);

  //Andar da posição inicial (1x7) para (2x5)
  REQUIRE(knight->SetPosition(2,5) == true);
  REQUIRE(knight->GetPositionX() == 2);
  REQUIRE(knight->GetPositionY() == 5);

  //Seta uma posição não possível (andar na vertical)
  REQUIRE(knight->SetPosition(2,4) == false);

  //Demonstra que a posição não mudou (pois não era possível)
  REQUIRE(knight->GetPositionX() == 2);
  REQUIRE(knight->GetPositionY() == 5);

  //Da posição que estava (2,5), voltar para a posição inicial (1x7)
  REQUIRE(knight->SetPosition(1,7) == true);
  REQUIRE(knight->GetPositionX() == 1);
  REQUIRE(knight->GetPositionY() == 7);
}

TEST_CASE("Teste da função 'IsMovementPossible' da Rainha", "A função determina que a Rainha pode se mover em qualquer direção (por jogada), ir e voltar")
{
  Piece *queen;
  queen = new Queen(false, 3, 7);

  //Andar da posição inicial (3x7) para todas casas possíveis
  REQUIRE(queen->IsMovementPossible(2, 7) == true);
  REQUIRE(queen->IsMovementPossible(2, 6) == true);
  REQUIRE(queen->IsMovementPossible(3, 6) == true);
  REQUIRE(queen->IsMovementPossible(4, 6) == true);
  REQUIRE(queen->IsMovementPossible(4, 7) == true);

  //Peça no meio do tabuleiro (4x4), todas as posições possíveis ao redor dela
  queen = new Queen(false, 4, 4);
  REQUIRE(queen->IsMovementPossible(3, 4) == true);
  REQUIRE(queen->IsMovementPossible(5, 4) == true);
  REQUIRE(queen->IsMovementPossible(5, 3) == true);
  REQUIRE(queen->IsMovementPossible(4, 3) == true);
  REQUIRE(queen->IsMovementPossible(3, 3) == true);
  REQUIRE(queen->IsMovementPossible(3, 5) == true);
  REQUIRE(queen->IsMovementPossible(4, 5) == true);
  REQUIRE(queen->IsMovementPossible(5, 5) == true);

  //Mostrar que ela não pode ir para a mesma casa que está
  REQUIRE(queen->IsMovementPossible(4, 4) == false);

  //Movimento não possível
  REQUIRE(queen->IsMovementPossible(2, 5) == false);

  //Mostrar que pode se mover varias casas
  REQUIRE(queen->IsMovementPossible(1, 7) == true);
}

TEST_CASE("Teste da função 'SetPosition' da Rainha", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *queen;
  queen = new Queen(false, 3, 7);

  //Seta uma posição não possível (2x5)
  REQUIRE(queen->SetPosition(2,5) == false);

  //Demonstra que a posição não mudou (pois não era possível)
  REQUIRE(queen->GetPositionX() == 3);
  REQUIRE(queen->GetPositionY() == 7);

  //Da posição que estava (3,7), vai para (0x7)
  REQUIRE(queen->SetPosition(0,7) == true);
  REQUIRE(queen->GetPositionX() == 0);
  REQUIRE(queen->GetPositionY() == 7);
}

TEST_CASE("Teste da função 'IsMovementPossible' do Rei", "A função determina que o Rei pode se mover em qualquer direção (por vez), ir e voltar, apenas 1 casa andada por vez")
{
  Piece *king;
  king = new King(false, 4, 7);

  //Andar da posição inicial (4x7) para todas casas possíveis
  REQUIRE(king->IsMovementPossible(3, 7) == true);
  REQUIRE(king->IsMovementPossible(3, 6) == true);
  REQUIRE(king->IsMovementPossible(4, 6) == true);
  REQUIRE(king->IsMovementPossible(5, 6) == true);
  REQUIRE(king->IsMovementPossible(5, 7) == true);

  //Peça no meio do tabuleiro (4x4), todas as posições possíveis ao redor dela
  king = new King(false, 4, 4);
  REQUIRE(king->IsMovementPossible(3, 4) == true);
  REQUIRE(king->IsMovementPossible(5, 4) == true);
  REQUIRE(king->IsMovementPossible(5, 3) == true);
  REQUIRE(king->IsMovementPossible(4, 3) == true);
  REQUIRE(king->IsMovementPossible(3, 3) == true);
  REQUIRE(king->IsMovementPossible(3, 5) == true);
  REQUIRE(king->IsMovementPossible(4, 5) == true);
  REQUIRE(king->IsMovementPossible(5, 5) == true);

  //Mostrar que ela não pode ir para a mesma casa que está
  REQUIRE(king->IsMovementPossible(4, 4) == false);

  //Movimento não possível - mover mais de 1 casa por vez
  REQUIRE(king->IsMovementPossible(4, 6) == false);
}

TEST_CASE("Teste da função 'SetPosition' do Rei", "Função retorna true se o movimento for possível (setando a nova posição) e false caso movimento não seja possível (não modificando a posição)")
{
  Piece *king;
  king = new King(false, 4, 7);

  //Seta uma posição não possível (2x7)
  REQUIRE(king->SetPosition(2,7) == false);

  //Demonstra que a posição não mudou (pois não era possível)
  REQUIRE(king->GetPositionX() == 4);
  REQUIRE(king->GetPositionY() == 7);

  //Da posição que estava (4,7), vai para (3x7)
  REQUIRE(king->SetPosition(3,7) == true);
  REQUIRE(king->GetPositionX() == 3);
  REQUIRE(king->GetPositionY() == 7);
}

TEST_CASE("Teste da função 'SetDead' e 'GetIsAlive' para cada peça", "A função seta a peça como morta e não é possivel reviver ela (e a posição -1x-1)")
{
  Piece *pawn, *bishop, *rook, *knight, *queen, *king, *piece;
  pawn = new Pawn(false, 0, 1);
  rook = new Rook(false, 0, 0);
  knight = new Knight(false, 1, 0);
  bishop = new Bishop(false, 2, 0);
  queen = new Queen(false, 3, 0);
  king = new King(false, 4, 0);
  piece = new Piece();

  //Verificação inicial
  REQUIRE(pawn->GetIsAlive() == true);
  REQUIRE(rook->GetIsAlive() == true);
  REQUIRE(knight->GetIsAlive() == true);
  REQUIRE(bishop->GetIsAlive() == true);
  REQUIRE(queen->GetIsAlive() == true);
  REQUIRE(king->GetIsAlive() == true);
  REQUIRE(piece->GetIsAlive() == false);

  //Mata todas as peças
  pawn->SetDead();
  rook->SetDead();
  knight->SetDead();
  bishop->SetDead();
  queen->SetDead();
  king->SetDead();

  //Verifica que a posição de todas as peças agora é -1x-1
  REQUIRE(pawn->GetPositionX() == -1);
  REQUIRE(pawn->GetPositionY() == -1);
  REQUIRE(rook->GetPositionX() == -1);
  REQUIRE(rook->GetPositionY() == -1);
  REQUIRE(knight->GetPositionX() == -1);
  REQUIRE(knight->GetPositionY() == -1);
  REQUIRE(bishop->GetPositionX() == -1);
  REQUIRE(bishop->GetPositionY() == -1);
  REQUIRE(queen->GetPositionX() == -1);
  REQUIRE(queen->GetPositionY() == -1);
  REQUIRE(king->GetPositionX() == -1);
  REQUIRE(king->GetPositionY() == -1);
  REQUIRE(piece->GetPositionX() == -1);
  REQUIRE(piece->GetPositionY() == -1);

  //Verifica que todas morreram
  REQUIRE(pawn->GetIsAlive() == false);
  REQUIRE(rook->GetIsAlive() == false);
  REQUIRE(knight->GetIsAlive() == false);
  REQUIRE(bishop->GetIsAlive() == false);
  REQUIRE(queen->GetIsAlive() == false);
  REQUIRE(king->GetIsAlive() == false);
  REQUIRE(piece->GetIsAlive() == false);
}

TEST_CASE("Teste da função 'States' ", "Função inicializa o tabuleiro em situação inicial de jogo")
{
  States * pieces = new States();

// Testa posições X das peças pretas
  REQUIRE(pieces->black_pieces[8]->GetPositionX() == 0);
  REQUIRE(pieces->black_pieces[9]->GetPositionX() == 1);
  REQUIRE(pieces->black_pieces[10]->GetPositionX() == 2);
  REQUIRE(pieces->black_pieces[11]->GetPositionX() == 3);
  REQUIRE(pieces->black_pieces[12]->GetPositionX() == 4);
  REQUIRE(pieces->black_pieces[13]->GetPositionX() == 5);
  REQUIRE(pieces->black_pieces[14]->GetPositionX() == 6);
  REQUIRE(pieces->black_pieces[15]->GetPositionX() == 7);

// Testa posições Y dos peões pretos
  REQUIRE(pieces->black_pieces[0]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[1]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[2]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[3]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[4]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[5]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[6]->GetPositionY() == 1);
  REQUIRE(pieces->black_pieces[7]->GetPositionY() == 1);

// Testa posições Y dos peões brancos
  REQUIRE(pieces->white_pieces[0]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[1]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[2]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[3]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[4]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[5]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[6]->GetPositionY() == 6);
  REQUIRE(pieces->white_pieces[7]->GetPositionY() == 6);

// Testa posições X das peças brancas
  REQUIRE(pieces->white_pieces[8]->GetPositionX() == 0);
  REQUIRE(pieces->white_pieces[9]->GetPositionX() == 1);
  REQUIRE(pieces->white_pieces[10]->GetPositionX() == 2);
  REQUIRE(pieces->white_pieces[11]->GetPositionX() == 3);
  REQUIRE(pieces->white_pieces[12]->GetPositionX() == 4);
  REQUIRE(pieces->white_pieces[13]->GetPositionX() == 5);
  REQUIRE(pieces->white_pieces[14]->GetPositionX() == 6);
  REQUIRE(pieces->white_pieces[15]->GetPositionX() == 7);

}

TEST_CASE("Teste da função 'IsInTheSpot' do para todas as pecas", "Funcao retorna enums sobre a posicao final")
{
  States * state;
  state = new States();

  // Knight
  REQUIRE(state->IsInTheSpot(3,6,state->white_pieces[9]) == Obstacles::Friend);
  REQUIRE(state->IsInTheSpot(2,5,state->white_pieces[9]) == Obstacles::Empty);

  state->black_pieces[0] = new Pawn(false, 2, 5);
  REQUIRE(state->IsInTheSpot(2,5,state->white_pieces[9]) == Obstacles::Enemy);

  // Pawn
  state->white_pieces[0] = new Pawn(true, 2, 6);
  state->black_pieces[0] = new Piece();
  REQUIRE(state->IsInTheSpot(2,5,state->white_pieces[0]) == Obstacles::Empty);

  state->white_pieces[1] = new Pawn(true, 2, 5);
  REQUIRE(state->IsInTheSpot(2,5,state->white_pieces[0]) == Obstacles::Friend);

  state->black_pieces[0] = new Pawn(false, 3, 5);
  REQUIRE(state->IsInTheSpot(3,5,state->white_pieces[0]) == Obstacles::Enemy);

  // Rook
  state->white_pieces[8] = new Rook(true, 0, 4);
  REQUIRE(state->IsInTheSpot(7,4,state->white_pieces[8]) == Obstacles::Empty);

  state->white_pieces[0] = new Rook(true, 7, 4);
  REQUIRE(state->IsInTheSpot(7,4,state->white_pieces[8]) == Obstacles::Friend);
  state->white_pieces[0] = new Piece();

  state->black_pieces[8] = new Rook(false, 7, 4);
  REQUIRE(state->IsInTheSpot(7,4,state->white_pieces[8]) == Obstacles::Enemy);

   // Bishop
  state->white_pieces[10] = new Bishop(true, 4, 5);
  REQUIRE(state->IsInTheSpot(5,4,state->white_pieces[10]) == Obstacles::Empty);
  REQUIRE(state->IsInTheSpot(5,6,state->white_pieces[10]) == Obstacles::Friend);
  state->black_pieces[5] = new Bishop(false, 0, 1);
  REQUIRE(state->IsInTheSpot(0,1,state->white_pieces[10]) == Obstacles::Enemy);

  // Queen
  state->white_pieces[11] = new Queen(true, 3, 3);
  REQUIRE(state->IsInTheSpot(0,3,state->white_pieces[11]) == Obstacles::Empty);
  REQUIRE(state->IsInTheSpot(2,2,state->white_pieces[11]) == Obstacles::Empty);
  REQUIRE(state->IsInTheSpot(6,6,state->white_pieces[11]) == Obstacles::Friend);
  REQUIRE(state->IsInTheSpot(1,1,state->white_pieces[11]) == Obstacles::Enemy);

  // King
  state->white_pieces[12] = new King(true, 2, 4);
  state->white_pieces[1] = new Piece();
  state->black_pieces[0] = new Pawn(false, 1, 4);
  REQUIRE(state->IsInTheSpot(2,5,state->white_pieces[12]) == Obstacles::Empty);
  REQUIRE(state->IsInTheSpot(3,3,state->white_pieces[12]) == Obstacles::Friend);
  REQUIRE(state->IsInTheSpot(1,4,state->white_pieces[12]) == Obstacles::Enemy);
}

TEST_CASE("Teste da função 'IsInTheWay' para todas as pecas", "Funcao retorna enums sobre a posicao final")
{
  States * state;
  state = new States();

  REQUIRE(state->IsInTheWay(0,5,state->white_pieces[0]) == Obstacles::Empty); // Pawn
  REQUIRE(state->IsInTheWay(0,5,state->white_pieces[8]) == Obstacles::Friend); // Rook
  REQUIRE(state->IsInTheWay(0,5,state->white_pieces[9]) == Obstacles::Empty); // Knight
  REQUIRE(state->IsInTheWay(4,5,state->white_pieces[10]) == Obstacles::Friend); // Bishop
  REQUIRE(state->IsInTheWay(3,5,state->white_pieces[11]) == Obstacles::Friend); // Queen
  REQUIRE(state->IsInTheWay(4,6,state->white_pieces[12]) == Obstacles::Empty); // King

  state = new States();
  state->black_pieces[0] = new Pawn(false, 1, 5);
  state->white_pieces[3] = new Piece();
  state->white_pieces[4] = new Piece();

  REQUIRE(state->IsInTheWay(1,4,state->white_pieces[1]) == Obstacles::Enemy); // Pawn
  state->white_pieces[1] = new Piece();
  state->black_pieces[1] = new Pawn(false, 1, 6);
  REQUIRE(state->IsInTheWay(0,5,state->white_pieces[10]) == Obstacles::Enemy); // Bishop
  REQUIRE(state->IsInTheWay(3,5,state->white_pieces[11]) == Obstacles::Empty); // Queen
  REQUIRE(state->IsInTheWay(5,5,state->white_pieces[11]) == Obstacles::Empty); // Queen
  REQUIRE(state->IsInTheWay(4,6,state->white_pieces[12]) == Obstacles::Empty); // King
  REQUIRE(state->IsInTheWay(4,5,state->white_pieces[10]) == Obstacles::Empty); // Bishop
  state->black_pieces[1] = new Pawn(false, 4, 4);
  state->white_pieces[8] = new Rook(true, 2, 4);
  REQUIRE(state->IsInTheWay(5,4,state->white_pieces[8]) == Obstacles::Enemy); // Rook

  state = new States();
  state->black_pieces[4] = new Pawn(false, 5, 5);
  state->white_pieces[1] = new Piece();

  REQUIRE(state->IsInTheWay(0,5,state->white_pieces[10]) == Obstacles::Empty); // Bishop
  state->white_pieces[4] = new Piece();
  state->black_pieces[1] = new Pawn(false, 4, 6);
  REQUIRE(state->IsInTheWay(5,5,state->white_pieces[11]) == Obstacles::Enemy); // Queen
  REQUIRE(state->IsInTheWay(4,6,state->white_pieces[12]) == Obstacles::Empty); // King - o caminho dele não existe, anda apenas uma casa, entao sempre vai ser Empty

  state = new States();
  state->white_pieces[6] = new Pawn(true, 7, 5);
  REQUIRE(state->IsInTheWay(7,4,state->white_pieces[7]) == Obstacles::Friend); // Pawn
}
