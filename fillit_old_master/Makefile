NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror# -O3 -march=native
SRCS = srcs/main.c srcs/ft_map.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a -L./libft

all: $(NAME)

#execute:
#		./$(NAME) text1.$(NAME)

clean: 
		rm -rf $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all # execute
