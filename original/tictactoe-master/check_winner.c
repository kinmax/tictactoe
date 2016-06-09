
/* Fonction qui vérifie si un colone est pleine pour le joueur actuel */
int	check_column_full(char board[3][3], int player)
{
  int	is_full;
  int	count;
  int	i;
  int	j;

  is_full = 0;
  count = 0;
  i = 0;
  while (i < 3 && count < 3)
    {
      count = 0;
      for (j = 0; j < 3; j++)
	if (board[i][j] == player)
	  count++;
      i++;
    }
  if (count == 3)
    is_full = 1;
  return (is_full);
}

/*Fonction qui vérifie si une ligne est pleine pour le joueur actuel */
int	check_line_full(char board[3][3], int player)
{
  int	is_full;
  int	count;
  int	i;
  int	j;

  is_full = 0;
  count = 0;
  i = 0;
  while (i < 3 && count < 3)
    {
      count = 0;
      for (j = 0; j < 3; j++)
	if (board[j][i] == player)
	  count++;
      i++;
    }
  if (count == 3)
    is_full = 1;
  return (is_full);
}

/* Fonction qui vérifie si une diagonale est pleine pour le joueur actuel */
int	check_diagonal_full(char board[3][3], int player)
{
  int	is_full;

  is_full = 0;
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    is_full = 1;
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    is_full = 1;
  return (is_full);
}

/* Foncion qui fait appel aux 3 précédentes et qui retourne au main si
** un joueur à gagné ou non 
*/
int	check_winner(char board[3][3], int player)
{
  if (check_line_full(board, player) == 1)
    return (player);
  else if (check_column_full(board, player) == 1)
    return (player);
  else if (check_diagonal_full(board, player) == 1)
    return (player);
  else
    return (-1);
}
