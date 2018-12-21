NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
