CC	= gcc

RM	= rm -rf

SRCS	= main.c \
	  check_winner.c \
	  display.c \

OBJS	= $(SRCS:.c=.o)

NAME	= tictactoe

CFLAGS	+= -Wall -W -Wextra -pedantic

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
