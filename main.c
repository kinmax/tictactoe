#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tictactoe.h"

struct strscores
{
    char name1[51];
    int score;
} scores[11], hold;

int	main()
{
    char board[3][3], name[51];
    int	i, win, menuop, p1 = 0, p2 = 0, replay = 1, pass;
    FILE* file;
    menuop = display_menu();

    switch(menuop)
    {
    case 1:			/*play*/
        file = fopen ("scores.txt", "r");/*Lê o arquivo e salva na struct*/
        scores[10].score = -1;

        for (i = 0; i < 10; i++)
        {
            fscanf (file, "%s%d", scores[i].name1, &scores[i].score);
        }
        fclose (file);
        /*As linhas 31 a 36 impedem que os highscores sejam zerados quando o processo for parado em andamento (Ctrl + C)*/
        file = fopen ("scores.txt", "w");
        for (i = 0; i < 10; i++)
        {
            fprintf(file, "%s       %d\n", scores[i].name1, scores[i].score);
        }
        fclose (file);
        while (replay == 1)
        {
            init_board(board);
            win = game_loop(board);
            system("clear");
            display_board(board);
            if (win == 0 || win == 1)
                printf("Player %d won!\n", win + 1);
            if (win == 0)
                p1++;
            if (win == 1)
                p2++;
            else if (win == 2)
                printf("Draw! No winner this time :'(\n");
            printf("Do you wanna play another round? (Y = 1/N = 0)\n");
            scanf ("%d", &replay);

        }
        printf ("Number of wins\nPlayer 1: %d\nPlayer 2: %d\n", p1, p2);
        if (p1 > p2)
        {
            printf ("Player 1 is the champion!\n");
            printf ("Enter your name, champion (Without spaces, new line or tab - 3 characters): ");
            scanf("%s", name);
            strcpy(scores[10].name1, name);
            scores[10].score = p1-p2;
            printf ("\n");
        }
        else if (p1 < p2)
        {
            printf ("Player 2 is the champion!");
            printf ("Enter your name, champion (Without spaces, new line or tab - 3 characters): ");
            scanf ("%s", name);
            strcpy(scores[10].name1, name);
            scores[10].score = p2-p1;
            printf ("\n");

        }
        else
        {
            printf ("We have no champion this time!\n");
        }

        /*Bubble Sort*/
        for (pass = 1; pass < 11; pass++)
        {
            for (i = 0; i < 10; i++)
            {
                if (scores[i].score < scores[i+1].score)
                {
                    hold = scores[i];
                    scores[i] = scores[i+1];
                    scores[i+1] = hold;
                }
            }
        }
        file = fopen ("scores.txt", "w");/*Salva os novos highscores no arquivo*/
        for (i = 0; i < 10; i++)
        {
            fprintf(file, "%s       %d\n", scores[i].name1, scores[i].score);
        }

        fclose (file);
        break;

    case 2:			/*highscores*/
        system("clear");
        display_highscores();
        break;
    case 3:
        system("clear");
        printf ("Original game made by Gaelith, available at https://github.com/Gaelith/tictactoe\nModifications made by Kin Max Piamolini Gusmão, as the final work for Laboratório de Programação I\nModified code available at https://github.com/kinmax/tictactoe\n");
        break;
    default:
        break;
    }
    return 0;

}

void	init_board(char board[3][3])
{
    int	i;
    int	j;
    char	n;

    i = 0;
    n = '1';
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = n++;
}

int	check_input(char board[3][3], char *input)
{
    int insert_nb;

    if (strlen(input) > 1)
        return (-1);
    if (input[0] < '1' || input[0] > '9')
        return (-1);
    insert_nb = input[0] - '1';
    if (board[insert_nb / 3][insert_nb % 3] == 1 || board[insert_nb / 3][insert_nb % 3] == 0)
        return (insert_nb);
    return (-42);
}

int	game_loop(char board[3][3])
{
    int	win;
    int	turn;
    int	error;
    int	player;
    char input[64];
    int	insert_nb;

    win = -1;
    turn = 0;
    error = -42;
    while (win == -1)
    {
        player = turn % 2;
        system("clear");
        display_board(board);
        display_error(error);
        printf("Player %d enter the case number where to put an %c : ", player + 1, player == 0 ? 'X' : 'O');
        scanf("%s", input);
        error = check_input(board, input);
        if (error == -42)
        {
            insert_nb = input[0] - '1';
            board[insert_nb / 3][insert_nb % 3] = player;
            win = check_winner(board, player);
            if (win >= 0)
                return (player);
            else if (turn >= 8)
                return (2);
            turn++;
        }
    }
    return (0);
}


