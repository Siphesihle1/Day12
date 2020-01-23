NAME = ft_cat

OUT = *.o

SRC = *.c

all : $(NAME)

$(NAME): $(OUT)
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OUT)

$(OUT): $(SRC)
	@gcc -c $(SRC)

clean:
	@/bin/rm -f $(OUT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
