#include "../Headers/Piece.hpp"
#include "../Headers/Test_Piece.hpp"

#include <iostream>

using namespace std;

void test(void);

int main()
{
	test();
	return 0;
}

void test(void)
{
	Test_Piece piece;

	if (piece.run())
		cout << "SUCESSO" << endl();
	else
		cout << "FALHA" << endl();
}