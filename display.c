#include <stdio.h>
#include "tictactoe.h"
#include <stdlib.h>
#include <string.h>

void display_highscores(void)
{
    char scores[51];
    FILE *file;

    system("clear");
    file = fopen ("scores.txt", "r");
    printf ("%s%10s\n", "Name", "      Win Balance");
    while (!feof(file))
    {
        fgets (scores, 51, file);
        printf ("%s\n", scores);
    }


}

int display_menu(void)
{
    int opi, k = 0, f = 0;
    char op[71];
    while (f == 0)
    {
        system("clear");
        printf ("████████╗██╗ ██████╗████████╗ █████╗  ██████╗████████╗ ██████╗ ███████╗\n");
        printf ("╚══██╔══╝██║██╔════╝╚══██╔══╝██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██╔════╝\n");
        printf ("   ██║   ██║██║        ██║   ███████║██║        ██║   ██║   ██║█████╗\n");
        printf ("   ██║   ██║██║        ██║   ██╔══██║██║        ██║   ██║   ██║██╔══╝  \n");
        printf("   ██║   ██║╚██████╗   ██║   ██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗\n");
        printf("   ╚═╝   ╚═╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n");

        printf ("1 - PLAY\n2 - HIGHSCORES\n3 - CREDITS\n4 - QUIT\n");
        if (k == 1)
        {
            printf ("Invalid option!\n");
        }
        scanf ("%s", op);
        if (strlen(op) > 1)
        {
            k = 1;
            f = 0;
        }
        else
        {
            opi = atoi(op);
            if (opi != 1 && opi != 2 && opi != 3 && opi != 4)
            {
                k = 1;
                f = 0;
            }
            else
            {
                k = 0;
                f = 1;
            }
        }
    }
    return (opi);
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
