#include "../include/Piece.hpp"
#include "../include/Pawn.hpp"
#include "../include/Knight.hpp"
#include "../include/Bishop.hpp"
#include "../include/Rook.hpp"
#include "../include/Queen.hpp"
#include "../include/King.hpp"
#include "../include/Board.hpp"
#include "../include/States.hpp"

using namespace std;

void ExecuteProgram(void);

int main()
{

	system("clear");
	cout << "\n\n\n\n\t\t\tSUCCESS\n\n\n\n";

	ExecuteProgram();

	return 0;
}

void ExecuteProgram()
{
	int x,y,i,j,moveX,moveY;
	bool color;

	States * states;
	Piece * piece;
	states = new States();

	while(states->WhoWon() == GameResult::NoContest)
	{
		system("clear");
		printf(" 0   1   2   3   4   5   6   7\n");
		printf("------------------------------\n");
		for(j = 0; j < 8; j++)
		{
			for(i = 0; i < 8; i++)
			{
				piece = states->GetPiece(i,j);
				color = piece->GetColor();
				switch (piece->GetName())
				{
					case PieceName::Empty:
					printf(" 0  ");
					break;
					case PieceName::Pawn:
					color ? printf(" wP ") : printf(" bP ");
					break;
					case PieceName::Knight:
					color ? printf(" wK ") : printf(" bK ");
					break;
					case PieceName::Bishop:
					color ? printf(" wB ") : printf(" bB ");
					break;
					case PieceName::Rook:
					color ? printf(" wR ") : printf(" bR ");
					break;
					case PieceName::Queen:
					color ? printf(" wQ ") : printf(" bQ ");
					break;
					case PieceName::King:
					color ? printf(" wK ") : printf(" bK ");
					break;
				}
			}
			printf(" |%d\n", j);
		}

		printf("\nDigite a peça que voce quer mover:\n");
		printf("Digite a posição X da peça:");
		scanf("%d", &x);
		printf("Digite a posição Y da peça:");
		scanf("%d", &y);
		printf("\nDigite a posição que voce quer mover:\n");
		printf("Digite a posição X final:");
		scanf("%d", &moveX);
		printf("Digite a posição Y final:");
		scanf("%d", &moveY);

		if(states->MovePiece(states->GetPiece(x,y),moveX,moveY))
		{
			states->PlayBestMove(false, Level::Hard);
		}
	}
	return;
}
