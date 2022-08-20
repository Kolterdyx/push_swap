

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = push_swap.c stack_functions1.c stack_functions2.c stack_functions3.c utils.c sorter.c utils2.c utils3.c

OBJS = $(SRCS:.c=.o)


%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<


$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)


.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm $(OBJS)
	make -C libft clean

fclean: clean
	rm $(NAME)
	make -C libft fclean

re: clean fclean all