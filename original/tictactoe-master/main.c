#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tictactoe.h"

/* Fonction principale qui fait appel au reste et gère l'affichage de fin */
int	main()
{
  char	board[3][3];
  int	win;

  init_board(board);
  win = game_loop(board);
  system("clear");
  display_board(board);
  if (win == 0 || win == 1)
    printf("Player %d won!\n", win + 1);
  else if (win == 2)
    printf("Draw! No winner this time :'(\n");
  return (0);
}

/* Initialisation la grille avec des numéros de case */
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

/* Gestion d'erreur de l'entrée utilisateur */
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

/* Boucle principale du jeu */
int	game_loop(char board[3][3])
{
  int	win;
  int	turn;
  int	error;
  int	player;
  char	input[64];
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
