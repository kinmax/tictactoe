#include <stdio.h>
#include "tictactoe.h"

/* Affichage de la grille */
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

/* Affichage des erreur */
void	display_error(int error)
{
  if (error == -1)
    printf("Error: please enter a number between 1 and 9\n");
  else if (error != -42)
    printf("Error : the cell %d is already used, please choose another cell", error + 1);
}
