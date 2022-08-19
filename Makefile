NAME =	push_swap
SRC	=	main.c arg_check.c brain.c parse_me.c push.c swap.c
LDIR = mlx
CFLAGS =  -Wall -Wextra -Werror #-Ofast
CC = gcc
OBJ	=	$(SRC:.c=.o)
LIBS = libft/libft.a  printf/printf.a



all: $(NAME)
		 
$(NAME): $(OBJ)
	make -C printf/.
	make -C libft/.
	$(CC) $(CFLAGS) -o $(NAME) $(LIBS) $(OBJ)



clean:
	@rm -f *.o
	@make clean -C libft/.
	@make clean -C printf/.
	


fclean: clean 
	@rm -f $(NAME) 
	@rm -f libft/libft.a
	@rm -f printf/print.a
	@rm -f push_swap
	
re: fclean all
