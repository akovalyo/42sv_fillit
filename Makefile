# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 21:26:34 by akovalyo          #+#    #+#              #
#    Updated: 2020/02/22 13:31:22 by akovalyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 
FLAGS = -Wall -Wextra -Werror -c
SRC = main.c \

OF = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -I ./
	@ar rc $(NAME) $(OF)
	@ranlib $(NAME)

clean:
	@rm -f $(OF)

fclean: clean 
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) libft.h

test: 
	@gcc -o test test*.c -L. -lft

testcl:
	@rm test

testclall:
	@rm test*
