#include "../include/Pawn.hpp"

/**@brief Método construtor do Peão
*
*Parâmetros: booleano indicando se a peça é branca e posições X e Y da peça no tabuleiro
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição: O método atribui um nome, uma cor, um valor, 
*posições X e Y e atribuí à peça o estado de vida
*
*Assertivas de entrada: booleano que indica se a peça é branca e duas posições 
*X e Y que indicam a posição da peça no tabuleiro
*
*Requisitos: O método deve setar um nome, uma posição, 
*uma cor um estado de vida e um valor à peça
*
*Hipóteses: O nome da peça deve ser do tipo PieceName e as posições 
*X e Y devem pertencer ao tabuleiro
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: bool isWhite, int position_X, int position_Y
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: O método constrói a peça 
*King atribuindo características básicas ao objeto da classe
*
*/

Pawn::Pawn(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Pawn;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
  isAlive = true;
  PieceValue = 1;
}

Pawn::~Pawn()
{
}

/**@brief Função que valida se o movimento do Peão é possível
*
*Parâmetros: dois inteiros que indicam a posição final da peça
*
*Tratamento de Erros: É verificado se as posições inseridas nos 
*parâmetros pertencem ao tabuleiro
*
*Descrição: O método verifica se a posição final pertence ao tabuleiro, 
*e em seguida verifica se o movimento é possível para o Peão e se a 
*posição final é diferente da posição em que ele já está
*
*Assertivas de entrada: dois inteiros que indicam a posição final da peça no tabuleiro
*
*Requisitos: As posições dos parâmetros devem pertencer ao tabuleiro 
*e o Peão deve poder se mover até lá
*
*Hipóteses: Se o movimento do Peão for possível, o método deve retornar um booleano true, 
*caso contrário deve retornar um booleano false
*
*Assertivas de saida: bool true or bool false
*
*Interface explicita: int FinalPosition_X, int FinalPosition_Y
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: Se o movimento do Peão for possível, o método deve retornar um booleano true, 
*caso contrário deve retornar um booleano false
*
*/

bool Pawn::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  if(FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8 && isAlive)  //Assertivas de entrada, X e Y precisam ser positivos e maiores ou iguais a zero e menores que 8 (para estarem no tabuleiro). e estar viva
  {
    //Calculo do deslocamento entre a posição da peça e a nova jogada
    int movement_x = FinalPosition_X - position_X;
    int movement_y = FinalPosition_Y - position_Y;

    if(movement_x == 0 || ((movement_x == -1 && hasDiagonalEnemyLeft) || (movement_x == 1 && hasDiagonalEnemyRight))) //Checa se Peao pode comer na diagonal
    {
      if((isWhite && movement_y < 0) || (!isWhite && movement_y > 0)) //Impede do Peao andar para trás.
      {
        movement_y = abs(movement_y);
        if(movement_y == 2 && movement_x == 0) //Andar duas vezes (não pode fazer isso caso esteja 'comendo' uma peça na diagonal)
        {
          if(isWhite && position_Y == 6) //Checa se é branca e se é a primeira jogada
          {
            return true;
          }

          if(!isWhite && position_Y == 1) //Checa se é preta e se é a primeira jogada
          {
            return true;
          }

          return false; //Caso não seja a primeira jogada, não se pode andar duas vezes.
        }

        if(movement_y == 1) //Andar apenas uma casa
        {
          return true;
        }
      }
    }
  }

  return false;
}

/**@brief Método que seta um inimigo na posição 
*diagonal em relação à posição do peão
*
*Parâmetros: dois booleanos que indicam se existe 
*um inimigo na diagonal esquerda e direita
*
*Tratamento de Erros: É verificado se a cor da peça da 
*diagonal esquerda ou direita é diferente da cor do peão
*
*Descrição: Se a cor da peça que está na diagonal esquerda ou direita
*em relação à posição do peão for diferente da cor do peão, então a peça 
*da diagonal é considerada inimiga e é setado um valor true na variável 
*da classe que indica se há um inimigo na diagonal esquerda ou direita
*
*Assertivas de entrada: dois booleanos que indicam se há inimigos na diagonal do peão
*
*Requisitos: Deve ser setado na variável da classe um valor booleano que indique se 
*há inimigos na diagonal dianteira em relação ao peão
*
*Hipóteses: Se existir uma peça na diagonal dianteira do peão, e essa peça for da 
*cor inimiga, então essa peça deve ser considerada inimiga
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: bool hasDiagonalEnemyLeft, bool hasDiagonalEnemyRight
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: Se existir uma peça na diagonal dianteira do peão,
* deve ser atribuido um valor true à variável que indica se há um inimigo na 
*diagonal dianteira do peão, caso contrário deve ser atribuído um valor de false
*
*/

void Pawn::SetDiagonalEnemy(bool hasDiagonalEnemyLeft, bool hasDiagonalEnemyRight)
{
  if(isWhite)
  {
    this->hasDiagonalEnemyRight = hasDiagonalEnemyRight;
    this->hasDiagonalEnemyLeft = hasDiagonalEnemyLeft;
  }
  else
  {
    this->hasDiagonalEnemyRight = hasDiagonalEnemyLeft;
    this->hasDiagonalEnemyLeft = hasDiagonalEnemyRight;
  }

}
