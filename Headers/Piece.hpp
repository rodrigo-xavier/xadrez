#ifndef PIECE_HPP_INCLUDED
#define PIECE_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Piece
{
  private:
    string nome;
    bool cor;

  public:
    Piece();
    ~Piece();
};

#endif