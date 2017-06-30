# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdurot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 17:39:38 by qdurot            #+#    #+#              #
#    Updated: 2017/05/17 22:05:19 by qdurot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line_test

FLAGS = -Wall -Werror -Wextra -g

LFLAGS = -Llibft -lft

SRC = main.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ):
	@gcc $(FLAGS) -c $(SRC) -I libft

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
