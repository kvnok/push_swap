NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = ./src/errorcheck.c ./src/fillstack.c ./src/helpers.c ./src/indexes.c \
./src/main.c ./src/printing.c ./src/push.c ./src/radix.c ./src/support.c\
./src/reverse.c ./src/rotate.c ./src/sorter.c ./src/swap.c

SRCDIR = ./src
OBJ = $(SRC:./src/%.c=./obj/%.o)
OBJDIR = ./obj

LIBFT = ./libft/libft.a

all: $(NAME)

$(OBJDIR):
	@mkdir obj

$(LIBFT):
	@$(MAKE) -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
