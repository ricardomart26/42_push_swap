CC = gcc -Wall -Wextra -Werror

CCS = gcc -Wall -Wextra -Werror -fsanitize=address

INCLUDE = -I push_swap.h

SRC = $(wildcard main/*.c) $(wildcard cmds_and_combos/*.c) $(wildcard utils/*.c) $(wildcard simulate/*.c)

OBJS = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	mv $(OBJS) Objs

san: fclean $(OBJS)
	$(CCS) $(OBJS) -g -o $(NAME)
	mv $(OBJS) Objs

clean:
	rm -f Objs/*.o

test:
	$(CC) random_numbers.c -o test
	

fclean: clean
	rm -f swap.out

re:	fclean $(NAME)

.PHONY: all clean fclean re
