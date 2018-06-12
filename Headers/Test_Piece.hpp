#ifndef TEST_PIECE_HPP_INCLUDED
#define TEST_PIECE_HPP_INCLUDED

using namespace std;

class Test_Piece
{
  private:
    const static bool FALHA;
    const static bool SUCESSO;
    bool estado;

  public:
    bool run(void);
};

#endif