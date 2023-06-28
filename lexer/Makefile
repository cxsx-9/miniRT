NAME = check

SRC = lexer.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror -fsanitize=address
CC = cc

# MLX = $(MLXDIR)libmlx.a
# MLXDIR = ./mlx/

LIBFT = $(LIBDIR)libft.a
LIBDIR = ../libft/

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : %.o : %.c 
	$(CC) $(CFLAG) -Ilibft -Iincludes/miniRT.h -c $< -o $@

$(LIBFT) :
	make -C $(LIBDIR)

clean :
	make -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re : fclean all