SRCS = $(wildcard *.c)
 	 
OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -c -Wall -Wextra -Werror
LINK = -lft -Llibft -lmlx -framework OpenGL -framework AppKit
NAME = so_long

all: lib $(NAME)

%.c:
	$(CC) $(CFLAGS) $(SRCS)

lib:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(LINK) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) libft/*.o

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus .c.o lib
