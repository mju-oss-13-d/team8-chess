#include <stdio.h>
#include "chess.h"
#include<stdlib.h>

Move GetMove(Dudes *Board[8][8])
{
				Move move;
				Coordinates FromCoords = GetFromCoords(Board);
				Coordinates ToCoords= GetToCoords(Board);
				move.From = FromCoords;
				move.To = ToCoords;
				MovePiece(&move, Board);
}

Coordinates GetFromCoords(Dudes *Board[8][8])
{
				Coordinates Coords;
				DrawBoard(Board);
				printf("djasflksdajflksadf\n");
				printf("Move which piece?\n");
				Coords = GetInput();
				printf("%d %d\n", Coords.X, Coords.Y);
				

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
				printf("djasflksdajflksadf124124214\n");
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
				char temp;
				Coordinates Coords;
				scanf("%c%d", &temp, &Coords.Y);
				skipgarb();
				Coords.X = ConvertLetterToNumber(temp);
				Coords.Y--;
				return Coords;
}

int CheckFriendlyPiece(Coordinates Coords, Dudes *Board[8][8])
{
				return (Board[Coords.X][Coords.Y]->Colour == Gamestate.Turn);
}

void MovePiece(Move *move, Dudes *Board[8][8])
{
				if(Board[move->From.X][move->From.Y]->Piece == pawn &&  Board[move->From.X][move->From.Y]->Colour == white){
					if(move->To.Y == move->From.Y+1 && move->To.X == move->From.X){
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;;
					}else{
						printf("잘못움직엿다\n");
					}
				}
				if(Board[move->From.X][move->From.Y]->Piece == pawn &&  Board[move->From.X][move->From.Y]->Colour == black){
					if(move->To.Y == move->From.Y-1 && move->To.X == move->From.X){
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;;
					}else{
						printf("잘못움직엿다\n");
					}
				}
				if(Board[move->From.X][move->From.Y]->Piece == rook){
					if(move->To.Y != move->From.Y && move->To.X != move->From.X){
						printf("잘못움직엿다\n");
					}else{
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;
					}
				}
				if(Board[move->From.X][move->From.Y]->Piece == knight){
					if(((abs(move->From.X - move->To.X) == 1) && (abs(move->From.Y - move->To.Y) == 2)) ||
						((abs(move->From.X - move->To.X) == 2) && (abs(move->From.Y - move->To.Y) == 1))){
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;
					}else{
						printf("잘못움직엿다\n");
					}
				}
				if(Board[move->From.X][move->From.Y]->Piece == king){
					if(((abs(move->From.X - move->To.X) == 1) && (abs(move->From.Y - move->To.Y) == 1)) || 
						((abs(move->From.X - move->To.X) == 1) && (abs(move->From.Y - move->To.Y) == 0)) || 
						((abs(move->From.X - move->To.X) == 0) && (abs(move->From.Y - move->To.Y) == 1))){
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;
					}else{
						printf("잘못움직엿다\n");
					}
				}
				if(Board[move->From.X][move->From.Y]->Piece == queen){
					if(abs(move->From.X - move->To.X) == abs(move->From.Y - move->To.Y) || 
						move->To.Y != move->From.Y && move->To.X == move->From.X || 
						move->To.Y == move->From.Y && move->To.X != move->From.X){
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;
					}else{
						printf("잘못움직엿다\n");
					}
				}
				if(Board[move->From.X][move->From.Y]->Piece == bishop){
					if(abs(move->From.X - move->To.X) == abs(move->From.Y - move->To.Y)){
						Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
						Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
						Board[move->From.X][move->From.Y]->Colour = empty;
						Board[move->From.X][move->From.Y]->Piece = none;
					}else{
						printf("잘못움직엿다\n");
					}
				}
}
