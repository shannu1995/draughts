#include "game.h"
#include <string.h>

/* Requirement 7 - Controls the flow of play in the game*/
void play_game(char * player_one, char * player_two, 
    struct result * outcome)
{
	/*Hello?*/
	enum cell_contents gameboard[BOARDWIDTH][BOARDHEIGHT];
	int r, q;
	struct player red_player;
	struct player white_player;
	init_gameboard(gameboard);
	display_gameboard(gameboard);
	red_player.col = P_RED;
	white_player.col = P_WHITE;
	srand(time(NULL));
	r = rand();
	q = r % 2;
	
	if(q == 0)
	{
		strcpy(red_player.name, player_one);
		strcpy(white_player.name, player_two);
	}
	
	else
	{
		strcpy(red_player.name, player_two);
		strcpy(white_player.name, player_one);
	}
	
	printf("The red player is %s\n", red_player.name);
	printf("The white player is %s\n", white_player.name);
	
	while(1 > 0)
	{
		player_turn(&red_player, gameboard);
		player_turn(&white_player, gameboard);
	}
	
}

void player_turn(struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	char *token;
	char prompt[80 + 1];
	char str[80];
	struct move player_move;
	/*char attack;*/
	printf("It is %s's turn\n", current->name);
	sprintf(prompt, "Enter input[hi,vi-hf,vf]:");
	getString(str, 16, prompt);
	token = strtok(str, ",");
	player_move.start.x = atoi(token);
	token = strtok(NULL, "-");
	player_move.start.y = atoi(token);
	token = strtok(NULL, ",");
	player_move.end.x = atoi(token);
	token = strtok(NULL, "\0");
	player_move.end.y = atoi(token);
	
	switch(is_valid_move(player_move, current, board))
	{
		case INVALID:
		{
			printf("The move you entered was invalid; please try again\n");
			player_turn(current, board);
			break;
		}
		case NORMAL:
		{
			board[player_move.end.y][player_move.end.x] = board[player_move.start.y][player_move.start.x];
			board[player_move.start.y][player_move.start.x] = EMPTY;
			display_gameboard(board);
			break;
		}
		case ATTACK:
		{
			board[player_move.end.y][player_move.end.x] = board[player_move.start.y][player_move.start.x];
			board[player_move.start.y][player_move.start.x] = EMPTY;
			display_gameboard(board);
			break;
		}
	}
}

/* Requirement 4 - Tests to see whether a move is valid or not*/
enum move_type is_valid_move(struct move next_move,struct player * current, enum cell_contents board[][BOARDWIDTH])
{
	enum move_type validity;
	validity = INVALID;
	if((board[next_move.end.y][next_move.end.x] == EMPTY) && (board[next_move.start.y][next_move.start.x] != EMPTY))
	{
		if(current->col == P_RED)
		{
			if(board[next_move.start.y][next_move.start.x] == RED)
			{
				if((next_move.end.y - next_move.start.y == 1) && (abs(next_move.end.x - next_move.start.x) == 1))
					validity = NORMAL;
				
				else if((next_move.end.y - next_move.start.y == 2) && (abs(next_move.end.x - next_move.start.x) == 2))
				{
					if((next_move.end.x > next_move.start.x))
					{
						if(board[next_move.end.y - 1][next_move.end.x - 1]==WHITE ||
						board[next_move.end.y - 1][next_move.end.x - 1]==K_WHITE)
						
						{
							board[next_move.end.y - 1][next_move.end.x - 1] = EMPTY;
							validity = ATTACK;
						}
						
					}
					
					else
					{
						if(board[next_move.end.y - 1][next_move.end.x + 1]==WHITE ||
						   board[next_move.end.y - 1][next_move.end.x + 1]==K_WHITE)
						{
							board[next_move.end.y - 1][next_move.end.x + 1] = EMPTY;
							validity = ATTACK;
						}
					}
					
				}
			}/*Normal red token*/
			else
			{
				if((abs(next_move.end.y - next_move.start.y) == 1) && (abs(next_move.end.x - next_move.start.x) == 1))
				validity = NORMAL;
			}
		}/*If it is red's turn*/
		
		else
		{
			if(board[next_move.start.y][next_move.start.x] == WHITE)
			{
				if((next_move.end.y - next_move.start.y == -1) && (abs(next_move.end.x - next_move.start.x) == 1))
					validity = NORMAL;
				
				else if((next_move.end.y - next_move.start.y == -2) && (abs(next_move.end.x - next_move.start.x) == 2))
				{
					if(next_move.end.x > next_move.start.x)
					{
						if(board[next_move.start.y - 1][next_move.start.x + 1] == RED ||
						   board[next_move.start.y - 1][next_move.start.x + 1] == K_RED)
						{
							board[next_move.start.y - 1][next_move.start.x + 1] = EMPTY;
							validity = ATTACK;
						}
					}
					
					else
					{
						if(board[next_move.start.y - 1][next_move.start.x - 1] == RED ||
						   board[next_move.start.y - 1][next_move.start.x - 1] == K_RED)
						{
							board[next_move.start.y - 1][next_move.start.x - 1] = EMPTY;
							validity = ATTACK;
						}
					}
				}
			} /*Normal White*/
			
			else
			{
				if((abs(next_move.end.x - next_move.start.x) == 1) && (abs(next_move.end.y - next_move.start.y) == 1))
				{
					validity = NORMAL;
				}
				
			}
			
		}/*If it is white's turn*/
		
	} /*if end is empty and start is not*/
	return validity;
}

/* Requirement  - Tests whether the next player has any valid moves */
BOOLEAN test_for_winner(struct player * next_player,enum cell_contents board[][BOARDWIDTH])
{
	BOOLEAN has_moves = TRUE;
	return has_moves;
}
