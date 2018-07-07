#include "../include/Piece.hpp"

Piece::Piece()
{
}

Piece::~Piece()
{
}

/**@brief Método que retorna a cor da peça.
*
*Parâmetros: Este método não recebe nenhum parâmetro
*
*Tratamento de Erros: Este método não contém nenhum tratamento de erros
*
*Descrição: Este método retorna true se a cor da peça for branca e false se a cor da peça for preta
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: O método deve retornar um booleano
*
*Hipóteses: O método retorna a cor da peça
*
*Assertivas de saida: booleano isWhite
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implicita.
*
*Contrato na especificação: O método apenas retorna um booleano que indica a cor da peça
*
*/

bool Piece::GetColor()
{
  return isWhite;
}

/**@brief Método que retorna o nome da peça.
*
*Parâmetros: Este método não recebe nenhum parâmetro
*
*Tratamento de Erros: Este método não contém nenhum tratamento de erros
*
*Descrição: Este método retorna o nome da peça
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: O método deve retornar um enum PieceName
*
*Hipóteses: O método retorna o nome da peça
*
*Assertivas de saida: enumerador do tipo PieceName 
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implicita.
*
*Contrato na especificação: O método apenas retorna um enum do tipo PieceName
*que indica o nome da peça
*
*/

PieceName Piece::GetName()
{
  return name;
}

/**@brief Método que retorna a posição da peça no eixo X do tabuleiro.
*
*Parâmetros: Este método não recebe nenhum parâmetro
*
*Tratamento de Erros: Este método não contém nenhum tratamento de erros
*
*Descrição: Este método retorna a posição da peça no eixo X do tabuleiro
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: O método deve retornar um inteiro que indica a 
*posição da peça no eixo X do tabuleiro
*
*Hipóteses: O método retorna a poisção da peça no eixo X do tabuleiro
*
*Assertivas de saida: inteiro position_X
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implicita.
*
*Contrato na especificação: O método apenas retorna um inteiro
*que indica a posição da peça no eixo X do tabuleiro
*
*/

int Piece::GetPositionX()
{
  return position_X;
}

/**@brief Método que retorna a posição da peça no eixo Y do tabuleiro.
*
*Parâmetros: Este método não recebe nenhum parâmetro
*
*Tratamento de Erros: Este método não contém nenhum tratamento de erros
*
*Descrição: Este método retorna a posição da peça no eixo Y do tabuleiro
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: O método deve retornar um inteiro que indica a 
*posição da peça no eixo Y do tabuleiro
*
*Hipóteses: O método retorna a poisção da peça no eixo Y do tabuleiro
*
*Assertivas de saida: inteiro position_Y
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implicita.
*
*Contrato na especificação: O método apenas retorna um inteiro
*que indica a posição da peça no eixo Y do tabuleiro
*
*/

int Piece::GetPositionY()
{
  return position_Y;
}

/**@brief Método que retorna um booleano indicando se o movimento é possível
*
*Parâmetros: Este método dois parâmetros que indicam a posição X e Y da peça no tabuleiro
*
*Tratamento de Erros: Este método não contém nenhum tratamento de erros
*
*Descrição: Este método retorna um booleano false que indica se o movimento da peça é possível
*
*Assertivas de entrada: Dois inteiros que indicam a posição X e Y
*
*Requisitos: O método deve retornar um booleano false que indica se o movimento é possível
*
*Hipóteses: As posições X e Y serem posições do tabuleiro e o método retornar um booleano indicando a 
*
*Assertivas de saida: inteiro position_Y
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implicita.
*
*Contrato na especificação: O método apenas retorna um inteiro
*que indica a posição da peça no eixo Y do tabuleiro
*
*/

bool Piece::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  return false;
}

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

void Piece::SetDiagonalEnemy(bool hasDiagonalEnemyRight, bool hasDiagonalEnemyLeft)
{
}

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

void Piece::SetPosition(int position_X, int position_Y)
{
  if(isAlive)
  {
    this->position_X = position_X;
    this->position_Y = position_Y;
  }
}

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

bool Piece::GetIsAlive()
{
  return isAlive;
}

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

void Piece::SetDead()
{
  isAlive = false;
  this->position_X = -1;
  this->position_Y = -1;
}
