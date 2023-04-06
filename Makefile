CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

INCLUDE = -I push_swap.h

SRC = $(wildcard main/*.c) $(wildcard cmds_and_combos/*.c) $(wildcard utils/*.c) $(wildcard simulate/*.c)

OBJS = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

san: fclean $(OBJS)
	$(CCS) $(OBJS) -g -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
