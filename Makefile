# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:31:59 by dcoutinh          #+#    #+#              #
#    Updated: 2022/07/28 17:14:06 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minitalik

CFLAGS = -Wall -Wextra -Werror

SRCS =  server.c	\
		client.c

OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft && cp libft/libft.a $(NAME)

CLIBFT = make -C libft clean

FCLIBFT = make -C libft fclean

all: $(NAME)

$(NAME): $(SRC)
	$(LIBFT)
	$(CC) -I . -c $(CFLAGS) $(SRCS)

clean: 
	rm -f $(OBJS)
	$(CLIBFT)

fclean:
	rm -f (

