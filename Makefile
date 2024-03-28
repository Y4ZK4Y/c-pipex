# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/03/25 14:09:19 by ykarimi       #+#    #+#                  #
#    Updated: 2024/03/25 14:09:24 by ykarimi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = lib/libft/libft.a
INCLUDES = -I./include -I./lib/libft/include

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C lib/libft

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C lib/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C lib/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re