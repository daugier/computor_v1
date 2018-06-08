# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <daugier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 17:05:44 by ddufour           #+#    #+#              #
#    Updated: 2017/10/05 23:19:35 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor_v1

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I header/

LIBS = -Llibft/

SRCS =	srcs/main.c \
		srcs/parse.c \
		srcs/display.c \
		srcs/resolve.c \

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libft
	@echo "Libft Compiled"
	@$(CC) $(LIBS) -lft  -o $@ $^
	@echo "Computor v1 Ready to work !"

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@make clean -s -C libft
	@echo ".o Libft delete"
	@$(RM) $(OBJ)
	@echo ".o Computor v1  delete"

fclean : clean
	@$(RM) libft/libft.a
	@echo "libft.a delete"
	@$(RM) $(NAME)
	@echo "Computor v1  delete"

re : fclean all
