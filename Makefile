CC = cc

NAME = minitalk.a

CFLAGS = -Wall -Wextra -Werror

SRCS = client.c	\
	   server.c

OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft && cp libft/libft.a $(NAME)

RMLIBFT = make -C libft clean

RMFLIBFT = make -C libft fclean

all: $(NAME) 

$(NAME): $(OBJS)
	$(LIBFT) 
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) -I . -c $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)
	$(RMLIBFT)

fclean: clean
	rm -f $(NAME)
	$(RMFLIBFT)

re: fclean all

.PHONY: all clean fclean re
