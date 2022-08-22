NAME =	push_swap
SRC	=	main.c brain.c parse_me.c push.c swap.c cleaner.c
LDIR = mlx
CFLAGS = -Wall -Wextra -Werror -g3 #-Ofast
CC = gcc
OBJ	=	$(SRC:.c=.o)
LIBS =  ./printf/printf.a ./libft/libft.a



all: $(NAME)
		 
$(NAME): $(OBJ)
	make -C printf/.
	make -C libft/.
	$(CC) $(CFLAGS) $(OBJ) $(LIBS)  -o $(NAME)



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

# mem: $(OBJ)
# 	make -C printf/.
# 	make -C libft/.
# 	$(CC)  -o push_swap $(LIBS) $(OBJ)
