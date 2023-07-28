NAME = miniRT

SRC =	srcs/main.c		\
		srcs/struct/camera1.c		\
		srcs/struct/camera2.c		\
		srcs/struct/camera3.c		\
		srcs/struct/color.c			\
		srcs/struct/init.c			\
		srcs/rendering/render.c		\
		srcs/rendering/closest_hit.c	\
		srcs/rendering/closest_t.c	\
		srcs/rendering/equation.c	\
		srcs/rendering/lighting.c	\
		srcs/handler/event.c		\
		srcs/vector/vector_1.c		\
		srcs/vector/vector_2.c		\
		srcs/utils/utils.c			\
		srcs/utils/put_pixel.c		\
		srcs/parser/error_message_1.c	\
		srcs/parser/error_message_2.c	\
		srcs/parser/check_file.c		\
		srcs/parser/check_infile.c	\
		srcs/parser/check_object_1.c	\
		srcs/parser/check_object_2.c	\
		srcs/parser/get_infile.c		\
		srcs/parser/get_variable.c	\
		srcs/parser/get_object.c		\
		srcs/parser/get_light.c		\
		srcs/parser/good_number.c		\
		srcs/parser/good_variable.c	\
		srcs/parser/get_next_line.c	\
		srcs/parser/get_next_line_utils.c	\
		srcs/parser/ft_split_white.c	\
		srcs/parser/ft_atof.c			\
		srcs/parser/parser_util.c		\
		srcs/parser/objs_manager.c	\
		srcs/parser/free.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror # -g -fsanitize=address 
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