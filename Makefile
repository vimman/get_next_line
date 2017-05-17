# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdurot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 17:39:38 by qdurot            #+#    #+#              #
#    Updated: 2017/05/17 19:44:09 by qdurot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line_test

CFLAGS = -Wall -Werror -extra

LFLAGS = -L libft -lft

SRC = main.c get_next_line.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

LINCLUD = libft/libft.h

INCLUD = get_next_line.h

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ): $(LIB)
	gcc $(FLAGS) $(INCLUD) $(LINCLUD) -c $(SRC) $(LFLAGS)

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
