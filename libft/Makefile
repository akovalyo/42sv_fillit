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

NAME = libft.a
FLAGS = -c -Wall -Wextra -Werror
PATH = ./src/
HEADER = ./includes/
SRC_NAME = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
      ft_memccpy.c \
      ft_memmove.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
      ft_strlcat.c \
	  ft_strchr.c \
      ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
      ft_atoi.c \
      ft_isalpha.c \
      ft_isdigit.c \
      ft_isascii.c \
      ft_isalnum.c \
      ft_isprint.c \
      ft_toupper.c \
      ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
      ft_strjoin.c \
	  ft_strtrim.c \
      ft_strsplit.c \
      ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
      ft_putnbr.c \
	  ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
 	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_strlcpy.c \
	  ft_calloc.c \
	  ft_nbrlen.c \
	  ft_strspn.c \
	  ft_strcspn.c \
	  ft_lstadd_back.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstprint_str.c \
	  get_next_line.c
OF = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(PATH), $(SRC_NAME))

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -I$(HEADER)
	@ar rc $(NAME) $(OF)
	@ranlib $(NAME)

clean:
	@rm -f $(OF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) libft.h
