#include "draughts.h"

int main (int argc, char *argv[])
{
	struct result scoreboard[SCOREBOARDSIZE];
	int result = 0;
	char prompt[80 + 1];
	int min = 1, max = 4;
	char player_one[16], player_two[16];
	main_menu();
	sprintf(prompt, "Enter an integer (%d - %d): ", min, max);
	getInteger(&result, 11, prompt, min, max);
	init_scoreboard(scoreboard);
	
	switch(result)
	{
		
		case 1:
		{
			sprintf(prompt, "Enter player one name: ");
			getString(player_one, 16, prompt);
			sprintf(prompt, "Enter player two name: ");
			getString(player_two, 16, prompt);
			play_game(player_one, player_two, scoreboard);
			break;
		}
		
		case 2:
		{
			display_scoreboard(scoreboard);
			break;
		}
		
		case 3:
		{
			break;
		}
		
		case 4:
		{
			exit(0);
			break;
		}
	}
	
	return EXIT_SUCCESS;
}

void main_menu()
{
	printf("Englih Draughts - Main Menu\n");
	printf("1) Play Game\n");
	printf("2) Display Winners\n");
	printf("3) Reset Scoreboard\n");
	printf("4) Quit\n");
}
