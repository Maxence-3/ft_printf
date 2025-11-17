# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 15:57:00 by mde-carv          #+#    #+#              #
#    Updated: 2025/11/17 17:28:16 by mde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
HEADER = -I./includes
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 
%.o : %.c
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: fclean clean re all