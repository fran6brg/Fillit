NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror# -O3 -march=native
SRCS = srcs/main.c srcs/ft_map.c srcs/ft_check.c srcs/ft_solve.c\
	   srcs/ft_tetris.c srcs/free.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a -L./libft

all: $(NAME)

clean: 
		rm -rf $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all
