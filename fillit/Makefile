CC = gcc -Wall -Wextra -Werror

INC = -I includes

NAME = fillit

SRC = src/ft_list.c src/ft_resolve.c src/main.c src/utilitaires.c

OBJ = ft_list.o ft_resolve.o main.o utilitaires.o

.PHONE = all clean fclean re

all: $(NAME)

$(NAME):
	@ $(CC) $(INC) -c $(SRC)
	@ $(CC) $(INC) -o $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all
