CC=		gcc

NAME=	fdf

CFLAGS=	-Werror -Wextra -Wall

INCLUDES= -I./libft -I./get_next_line -I./includes

LIBFT= ./libft/libft.a

MLX= ./minilibx-linux/libmlx_Linux.a

LIB= $(LIBFT) $(MLX)

FILES=	./srcs/*main.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

OBJ=	$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(INCLUDES) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -c $(INCLUDES)  -o $@ $<

$(MLX):
	make -C ./minilibx-linux

$(LIBFT):
	make -C ./libft

clean:
	@rm -rf $(OBJ) $(B_OBJ)
	@make -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean $(NAME)
