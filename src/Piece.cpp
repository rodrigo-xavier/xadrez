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
*Parâmetros: Este método contém dois parâmetros que indicam a posição X e Y da peça no tabuleiro
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
*Assertivas de saida: booleano false
*
*Interface explicita: int FinalPosition_X, int FinalPosition_Y
*
*Interface implicita: Não há interface implicita.
*
*Contrato na especificação: O método apenas retorna um booleano
*que indica se é possível a peça se mover para a nova posição
*
*/

bool Piece::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  return false;
}

void Piece::SetDiagonalEnemy(bool hasDiagonalEnemyRight, bool hasDiagonalEnemyLeft)
{
}

/**@brief Método que seta as posições X e Y da peça no tabuleiro
*
*Parâmetros: dois inteiros que indicam as posições X e Y
*
*Tratamento de Erros: É verifica do a peça está viva
*
*Descrição: O método insere na peça as suas respectivas posições no eixo X e Y do tabuleiro
*
*Assertivas de entrada: dois inteiros indicando as posições X e Y
*
*Requisitos: O método deve receber dois inteiros que pertençam à posições do tabuleiro
* e seta-los nas posições X e Y da classe peça
*
*Hipóteses: O valor dos inteiros pertence à alguma posição do tabuleiro,
* a peça deve estar viva e as posições da peça devem ser inseridas na variável da classe
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: int position_X, int position_Y
*
*Interface implicita: Não há interface implicita
*
*Contrato na especificação: O método apenas insere as posições X e Y da 
*peça na variável da classe
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

/**@brief Método que diz se a peça está viva ou não
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição: O método retorna um booleano que indica se a peça está ou não está viva
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: o valor retornado deve ser um booleano
*
*Hipóteses: O valor retornado é um booleano
*
*Assertivas de saida: bool isAlive
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: O método deve retornar um booleano que indica se a peça está viva
*
*/

bool Piece::GetIsAlive()
{
  return isAlive;
}

/**@brief Método que mata a peça
*
*Parâmetros: Não há parâmetros
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição: Este método mata a peça setando suas posições para -1 e atribuindo 
*false à variável da classe que indica se a peça está viva
*
*Assertivas de entrada: Não há assertivas de entrada
*
*Requisitos: O método deve atribuir -1 às posições X e Y da variável da classe e false à 
*variável da classe que indica se a peça está viva ou morta
*
*Hipóteses: São atribuídas posições inválidas às variáveis da peça
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: Não há interface explicita
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: O método apenas insere posições inválidas à 
*peça morta e diz que ela está realmente morta
*
*/

void Piece::SetDead()
{
  isAlive = false;
  this->position_X = -1;
  this->position_Y = -1;
}
