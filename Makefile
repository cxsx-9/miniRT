NAME = miniRT

SRC =	srcs/main.c		\
		srcs/color.c	\
		srcs/vector.c	\
		srcs/event.c	\
		srcs/init.c		\
		srcs/put_pixel.c	\
		srcs/camera.c		\
		srcs/utils.c		\
		lexer/check_file.c	\
		lexer/lexer.c		\
		lexer/get_next_line.c	\
		lexer/get_next_line_utils.c	\
		lexer/ft_split_white.c	\
		lexer/free.c

OBJ = $(SRC:.c=.o)

CFLAG = -g -fsanitize=address# -Wall -Wextra -Werror
CC = cc

MLX = $(MLXDIR)libmlx.a
MLXDIR = ./mlx/

LIBFT = $(LIBDIR)libft.a
LIBDIR = ./libft/

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT) -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ) : %.o : %.c 
	$(CC) $(CFLAG) -Ilibft -Imlx -Iincludes -c $< -o $@

$(MLX) :
	make -C $(MLXDIR)

$(LIBFT) :
	make -C $(LIBDIR)

clean :
	make -C $(MLXDIR) clean
	make -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re : fclean all