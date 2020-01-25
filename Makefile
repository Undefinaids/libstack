NAME	=  libstack.so

CC	= gcc

RM	= rm -f

SRCS	= ./src/stack.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include
CFLAGS += -Wall -Wextra -fPIC

LDFLAGS = -shared

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
