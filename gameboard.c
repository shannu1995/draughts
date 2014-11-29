#include "gameboard.h"

/* Copies the master board to a local copy for each game */
void init_gameboard(enum cell_contents board[][BOARDWIDTH])
{
	int i, j;
	for(i = 0; i < BOARDHEIGHT; i++)
	{
		for(j = 0; j < BOARDWIDTH; j++)
		{
			board[i][j] = master_board[i][j];
		}
	}
}

/* Prints the game board to the screen */
void display_gameboard(enum cell_contents board[][BOARDWIDTH])
{
	int i, j;
	printf("   |");
	for(i = 0; i < 8; i++)
	{
		printf(" %d |", i);
	}
	printf("\n");
	printf("-----------------------------------");
	printf("\n");
	for(i = 0; i < BOARDHEIGHT; i++)
	{
		printf(" %d |", i);
		for(j = 0; j < BOARDWIDTH; j++)
		{
			switch(board[i][j])
			{
				case WHITE:
				{
					printf(" %s",WHITE_DISPLAY);
					printf(" |");
					break;
				}
				
				case EMPTY:
				{
					printf("  ");
					printf(" |");
					break;
				}
				
				case K_RED:
				{
					break;
				}
				
				case K_WHITE:
				{
					break;
				}
				
				case RED:
				{
					printf(" %s",RED_DISPLAY);
					printf(WHITE_RESET);
					printf(" |");
					break;
				}
				
			}
		}
		printf("\n");
		printf("-----------------------------------");
		printf("\n");
	}
}
