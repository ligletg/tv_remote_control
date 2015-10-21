NAME	= remote

SRCS	= remote.c

CFLAGS	= -I /usr/X11/include -g

LDFLAGS =  -L/usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit

OBJS	= $(SRCS:.c=.o)

CC	= gcc -ggdb3

RM	= rm -f

all	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(NAME)	: all

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(OBJS) $(NAME)

re	: fclean all