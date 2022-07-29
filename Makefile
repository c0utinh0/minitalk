# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:31:59 by dcoutinh          #+#    #+#              #
#    Updated: 2022/07/29 17:23:53 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minitalk.a

CFLAGS = -Wall -Wextra -Werror

SRCS =  server.c	\
	client.c	\
	server_bonus.c	\
	client_bonus.c


OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft && cp libft/libft.a $(NAME)

CLIBFT = make -C libft clean

FCLIBFT = make -C libft fclean

all: $(NAME)

$(NAME): $(SRC)
	$(LIBFT)
	$(CC) server.c $(NAME) -o server
	$(CC) client.c $(NAME) -o client

bonus: $(SRC)
	$(LIBFT)
	$(CC) server_bonus.c $(NAME) -o server_bonus
	$(CC) client_bonus.c $(NAME) -o client_bonus


clean: 
	rm -f $(OBJS)
	$(CLIBFT)

fclean:
	rm -f $(NAME)
	$(FCLIBFT)
	rm server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re
