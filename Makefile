# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/29 11:54:05 by digonza2          #+#    #+#              #
#    Updated: 2026/01/07 20:13:19 by digonza2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

FILES =	utils.c \
		numbers.c \
		ft_printf.c \

OBJTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	ar rcs $(NAME) $(OBJTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJTS)

fclean: clean
	rm -rf $(NAME)

del:
	rm -rf *.out

re: fclean all

.PHONY: make all clean fclean re
