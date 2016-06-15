# define WHITE	"\033[0m"
# define YELLOW	"\033[38;5;228m"
# define BLUE	"\033[38;5;104m"
# define L_BLUE	"\033[38;5;51m"
# define GREY	"\033[38;5;239m"

extern int display_menu(void);
extern void display_highscores(void);
extern void	display_board(char board[3][3]);
extern void	display_error(int error);
extern int	check_column_full(char board[3][3], int player);
extern int	check_line_full(char board[3][3], int player);
extern int	check_diagonal_full(char board[3][3], int player);
extern int	check_winner(char board[3][3], int player);
extern void    init_board(char board[3][3]);
extern int     game_loop(char board[3][3]);
