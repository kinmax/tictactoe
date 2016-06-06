#include <stdio.h>
#include "tictactoe.h"

void display_highscores(void)
{
	int i, hs;
	char name[51];
		
	system("clear");	
	FILE *file_numbers;
	FILE *file_names;
	file_numbers = fopen ("highscores_numbers.txt", "r");
	file_names = fopen ("highscores_names.txt", "r");
	while (!feof(highscores_numbers) && !feof(file_names))
	{
		fscanf (file_numbers, "%d", &hs);
		fscanf (file_names, "%s", name);
		printf ("%s%10d", name, hs);	
	}
	
	
}

int display_menu(void)
{
	int op;	
	system("clear");	
	printf ("               _____ ___ ____ _____  _    ____ _____ ___  _____ \n");
	printf("              |_   _|_ _/ ___|_   _|/ \\  / ___|_   _/ _ \\| ____|\n");
	printf ("                | |  | | |     | | / _ \\| |     | || | | |  _|\n");
	printf ("                | |  | | |___  | |/ ___ \\ |___  | || |_| | |___\n");
	printf ("                |_| |___\\____| |_/_/   \\_\\____| |_| \\___/|_____|\n\n\n");
	printf ("1 - PLAY\n2 - HIGHSCORES\n3 - CREDITS\n4 - QUIT\n");
	scanf ("%d", &op);
	return (op);
}

void	display_board(char board[3][3])
{
    int	i;
    int	j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j > 0)
                printf("%s|", BLUE);
            if (board[i][j] >= 49)
                printf("  %s%c%s  " , GREY, board[i][j], BLUE);
            else if (board[i][j] == 0)
                printf("  %sX%s  ", YELLOW, BLUE);
            else if (board[i][j] == 1)
                printf("  %sO%s  ", L_BLUE, BLUE);
        }
        if (i < 2)
            printf("\n-----------------\n");
    }
    printf("\n%s", WHITE);
}

void	display_error(int error)
{
    if (error == -1)
        printf("Error: please enter a number between 1 and 9\n");
    else if (error != -42)
        printf("Error : the cell %d is already used, please choose another cell\n", error + 1);
}
