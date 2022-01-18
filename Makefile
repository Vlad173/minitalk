# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vladislove <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:51:44 by vladislov         #+#    #+#              #
#    Updated: 2022/01/09 07:59:54 by pmeredyt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

server: server.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@make OBJ="$(OBJ_B)" all

clean:
	@$(RM) server.o client.o utils.o

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
