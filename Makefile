CC = gcc -Wall -Werror -Wextra

INCLUDE = -I push_swap.h

LIB = -L ./Libft -l libft.a -static

SRC = $(wildcard SRC/*.c)

OBJS = $(SRC:.c=.o)

NAME = swap.out

all: $(NAME)

$(NAME): $(OBJS)
	mkdir Objs
	@echo "created Dirs"
	$(CC) $(OBJS) -o $(NAME)
	mv $(OBJS) Objs

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf Objs
	rm -f swap.out

re:	fclean $(NAME)

.PHONY: all clean fclean re