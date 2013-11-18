#include <stdio.h>
#include "chess.h"

Move GetMove(Dudes *Board[8][8])
{
				Move move;
				Coordinates FromCoords = GetFromCoords(Board);
				Coordinates ToCoords= GetToCoords(Board);
				move.To = ToCoords;
				move.From = FromCoords;
				MovePiece(&move, Board);
}

Coordinates GetFromCoords(Dudes *Board[8][8])
{
				Coordinates Coords;
				DrawBoard(Board);
				printf("Move which piece?\n");
				Coords = GetInput();

				while (!ValidateCoords(Coords.X, Coords.Y))
				{
								DrawBoard(Board);
								printf("Invalid Coordinates! Select a piece to move:\n");
								Coords = GetInput();
				}

				return Coords;

}

Coordinates GetToCoords(Dudes *Board[8][8])
{

				Coordinates Coords;
				DrawBoard(Board);
				printf("Move piece to where?\n");
				Coords = GetInput();

				while (!ValidateCoords(Coords.X, Coords.Y))
				{
								DrawBoard(Board);
								printf("Invalid Coordinates! move piece where?\n");
								Coords = GetInput();
				}

				return Coords;

}

int ConvertLetterToNumber(char ch)
{
				int i = (int)ch;
				if (i > 90)
				{
								i -= 97;
				}
				else
				{
								i -= 65;
				}

				return i;
}

void skipgarb()
{
				while (getchar() != '\n')
				{
				}
}

int ValidateCoords(char x, int y)
{
				return ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7));
}

Coordinates GetInput()
{
