CC = gcc -Wall -Wextra -Werror -o

PUSH_SRC =	src/push_swap/main.c src/push_swap/algo.c src/push_swap/insertion_sort.c src/push_swap/clean_ops.c \
			src/push_swap/quick_sort.c src/ops/ops_1.c src/ops/ops_2.c src/ops/ops_3.c src/check_arg.c libft/libft.a
CHECK_SRC = src/checker/main.c src/checker/visio.c src/check_arg.c src/get_next_line.c src/ops/ops_1.c src/ops/ops_2.c src/ops/ops_3.c libft/libft.a

all :
	make re -C libft
	$(CC) push_swap $(PUSH_SRC) -I libft -I inc
	$(CC) checker $(CHECK_SRC) -I libft -I inc

test : re
	$(CC) nb_generation test/main.c -L libft -lft -I inc -I libft
	./nb_generation
	ARG=$$(<nb); ./push_swap $$ARG | ./checker $$ARG
	time ./push_swap $$(<nb) | wc -l

test2 : re
	ARG=$$(<nb); ./push_swap $$ARG | ./checker $$ARG
	time ./push_swap $$(<nb) | wc -l

vtest : re
	$(CC) nb_generation test/main.c -L libft -lft -I inc -I libft
	./nb_generation
	ARG=$$(<nb); ./push_swap $$ARG | ./checker $$ARG -v
	time ./push_swap $$(<nb) | wc -l

vtest2 : re
	ARG=$$(<nb); ./push_swap $$ARG | ./checker $$ARG -v
	time ./push_swap $$(<nb) | wc -l

clean :
	rm -f nb_generation nb
	make clean -C libft

fclean :
	rm -f nb_generation checker push_swap nb
	make fclean -C libft

re:  fclean all